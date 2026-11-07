#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 7
#define LINE_LENGTH 256
#define DECIMAL_BASE 10

int ParseLine(const char* line, int* values) {
    int count = 0;
    const char* position = line;
    char* end_position = NULL;

    while (1) {
        long value = strtol(position, &end_position, DECIMAL_BASE);
        if (end_position == position) {
            break;
        }
        if (count >= MAX_SIZE) {
            return -1;
        }
        values[count] = (int)value;
        ++count;
        position = end_position;
    }
    return count;
}

int ReadMatrix(int matrix[][MAX_SIZE]) {
    char line[LINE_LENGTH];
    int size = 0;
    int row_count = 0;

    while ((size == 0 || row_count < size) && fgets(line, LINE_LENGTH, stdin) != NULL) {
        int column_count = ParseLine(line, matrix[row_count]);

        if (column_count < 0) {
            printf("Матрица больше %dx%d\n", MAX_SIZE, MAX_SIZE);
            return 0;
        }
        if (column_count == 0) {
            continue;
        }
        if (row_count == 0) {
            size = column_count;
        } else if (column_count != size) {
            printf("Строка %d содержит %d чисел, ожидалось %d\n", row_count + 1, column_count, size);
            return 0;
        }
        ++row_count;
    }

    if (size == 0 || row_count != size) {
        printf("Матрица не квадратная или ввод пуст\n");
        return 0;
    }
    return size;
}

void PrintSpiral(int matrix[][MAX_SIZE], int size) {
    int top = 0;
    int bottom = size - 1;
    int left = 0;
    int right = size - 1;

    while (top <= bottom && left <= right) {
        for (int i = top; i <= bottom; ++i) {
            printf("%d ", matrix[i][right]);
        }
        --right;

        if (left <= right) {
            for (int j = right; j >= left; --j) {
                printf("%d ", matrix[bottom][j]);
            }
            --bottom;
        }

        if (top <= bottom && left <= right) {
            for (int i = bottom; i >= top; --i) {
                printf("%d ", matrix[i][left]);
            }
            ++left;
        }

        if (top <= bottom && left <= right) {
            for (int j = left; j <= right; ++j) {
                printf("%d ", matrix[top][j]);
            }
            ++top;
        }
    }
    printf("\n");
}

int main(void) {
    int matrix[MAX_SIZE][MAX_SIZE];
    int size = ReadMatrix(matrix);

    if (size == 0) {
        return EXIT_FAILURE;
    }
    PrintSpiral(matrix, size);
    return EXIT_SUCCESS;
}
