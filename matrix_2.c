#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ORDER 8
#define MAX_NUMBER_LENGTH 31
#define NUMBER_SIZE (MAX_NUMBER_LENGTH + 1)
#define LINE_SIZE 1024
#define FORMAT_SIZE 16
#define MIN_ARGUMENT_COUNT 2
#define FILE_NAME_ARGUMENT 1
#define LAST_BYTE_OFFSET (-1)
#define CLEARED_MARK "A"
#define DELIMITERS " \t\r\n"

bool IsEqualRows(int n, char matrix[n][n][NUMBER_SIZE], int first_row, int second_row) {
    for (int j = 0; j < n; ++j) {
        if (strcmp(matrix[first_row][j], matrix[second_row][j]) != 0) {
            return false;
        }
    }
    return true;
}

bool IsClearedRow(char row[][NUMBER_SIZE]) {
    return strcmp(row[0], CLEARED_MARK) == 0;
}

void ClearRow(int n, int row, char matrix[n][n][NUMBER_SIZE]) {
    for (int j = 0; j < n; ++j) {
        strcpy(matrix[row][j], CLEARED_MARK);
    }
}

int main(int argc, char *argv[]) {
    if (argc < MIN_ARGUMENT_COUNT) {
        printf("Ошибка: не указано имя файла\n");
        printf("Использование: %s <имя_файла>\n", argv[0]);
        return EXIT_FAILURE;
    }
    const char *file_name = argv[FILE_NAME_ARGUMENT];
    char line[LINE_SIZE];
    int n = 0;

    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Не удалось открыть файл %s\n", file_name);
        return EXIT_FAILURE;
    }

    if (fgets(line, sizeof(line), file) == NULL) {
        printf("Файл пуст\n");
        fclose(file);
        return EXIT_FAILURE;
    }
    size_t line_length = strlen(line);
    if (line_length == LINE_SIZE - 1 && line[line_length - 1] != '\n') {
        printf("Первая строка файла слишком длинная\n");
        fclose(file);
        return EXIT_FAILURE;
    }
    for (char *token = strtok(line, DELIMITERS); token != NULL; token = strtok(NULL, DELIMITERS)) {
        ++n;
    }

    if (n < 1 || n > MAX_ORDER) {
        printf("Некорректный порядок матрицы: %d\n", n);
        fclose(file);
        return EXIT_FAILURE;
    }

    char matrix[n][n][NUMBER_SIZE];
    char number_format[FORMAT_SIZE];
    snprintf(number_format, sizeof(number_format), "%%%ds", MAX_NUMBER_LENGTH);

    rewind(file);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (fscanf(file, number_format, matrix[i][j]) != 1) {
                printf("В файле не хватает чисел для матрицы %dx%d\n", n, n);
                fclose(file);
                return EXIT_FAILURE;
            }
            int next_char = fgetc(file);
            if (next_char != EOF && !isspace(next_char)) {
                printf("Число длиннее %d символов\n", MAX_NUMBER_LENGTH);
                fclose(file);
                return EXIT_FAILURE;
            }
        }
    }
    fclose(file);

    for (int i = 0; i < n; ++i) {
        if (IsClearedRow(matrix[i])) {
            continue;
        }
        for (int k = i + 1; k < n; ++k) {
            if (IsEqualRows(n, matrix, i, k)) {
                ClearRow(n, k, matrix);
            }
        }
    }

    file = fopen(file_name, "a+");
    if (file == NULL) {
        printf("Не удалось открыть файл %s для записи\n", file_name);
        return EXIT_FAILURE;
    }

    if (fseek(file, LAST_BYTE_OFFSET, SEEK_END) == 0 && fgetc(file) != '\n') {
        fprintf(file, "\n");
    }

    fprintf(file, "\n");
    for (int i = 0; i < n; ++i) {
        if (IsClearedRow(matrix[i])) {
            continue;
        }
        for (int j = 0; j < n; ++j) {
            fprintf(file, "%s%s", matrix[i][j], (j < n - 1) ? " " : "\n");
        }
    }
    fclose(file);

    printf("Готово, результат дописан в %s\n", file_name);
    return EXIT_SUCCESS;
}
