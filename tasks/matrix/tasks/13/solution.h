#pragma once

#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

static const int MIN_MATRIX_SIZE = 1;
static const int MAX_MATRIX_SIZE = 8;
static const char* const INPUT_FILE_NAME = "input.txt";

static void FreeMatrix(Matrix matrix, size_t size) {
    if (matrix == NULL) {
        return;
    }
    for (size_t row = 0; row < size; ++row) {
        free(matrix[row]);
    }
    free(matrix);
}

static Matrix CreateMatrix(size_t size) {
    Matrix matrix = calloc(size, sizeof(*matrix));
    if (matrix == NULL) {
        return NULL;
    }
    for (size_t row = 0; row < size; ++row) {
        matrix[row] = malloc(size * sizeof(**matrix));
        if (matrix[row] == NULL) {
            FreeMatrix(matrix, size);
            return NULL;
        }
    }
    return matrix;
}

static bool IsMatrixRead(FILE* input, size_t size, Matrix matrix) {
    for (size_t row = 0; row < size; ++row) {
        for (size_t col = 0; col < size; ++col) {
            if (fscanf(input, "%" SCNd32, &matrix[row][col]) != 1) {
                return false;
            }
        }
    }
    return true;
}

static int32_t FindLowerTriangleMax(const Matrix matrix, size_t size) {
    int32_t max_element = matrix[0][0];
    for (size_t row = 0; row < size; ++row) {
        for (size_t col = 0; col <= row; ++col) {
            if (matrix[row][col] > max_element) {
                max_element = matrix[row][col];
            }
        }
    }
    return max_element;
}

static void MultiplyUpperTriangle(int32_t factor, size_t size, Matrix matrix) {
    for (size_t row = 0; row < size; ++row) {
        for (size_t col = row; col < size; ++col) {
            matrix[row][col] *= factor;
        }
    }
}

static void PrintMatrix(const Matrix matrix, size_t size) {
    printf("%zu %zu\n", size, size);
    for (size_t row = 0; row < size; ++row) {
        for (size_t col = 0; col < size; ++col) {
            if (col > 0) {
                printf(" ");
            }
            printf("%" PRId32, matrix[row][col]);
        }
        printf("\n");
    }
}

int Task() {
    FILE* input = fopen(INPUT_FILE_NAME, "r");
    if (input == NULL) {
        fprintf(stderr, "Не удалось открыть файл %s\n", INPUT_FILE_NAME);
        return 1;
    }

    int size_from_file = 0;
    if (fscanf(input, "%d", &size_from_file) != 1 || size_from_file < MIN_MATRIX_SIZE ||
        size_from_file > MAX_MATRIX_SIZE) {
        fprintf(stderr, "Размер матрицы должен быть от %d до %d\n", MIN_MATRIX_SIZE, MAX_MATRIX_SIZE);
        fclose(input);
        return 1;
    }
    size_t size = (size_t)size_from_file;

    Matrix matrix = CreateMatrix(size);
    if (matrix == NULL) {
        fprintf(stderr, "Не хватило памяти для матрицы\n");
        fclose(input);
        return 1;
    }

    if (!IsMatrixRead(input, size, matrix)) {
        fprintf(stderr, "В файле не хватает элементов матрицы или они некорректны\n");
        FreeMatrix(matrix, size);
        fclose(input);
        return 1;
    }
    fclose(input);

    int32_t lower_triangle_max = FindLowerTriangleMax(matrix, size);  // ищем по исходной матрице
    MultiplyUpperTriangle(lower_triangle_max, size, matrix);
    PrintMatrix(matrix, size);

    FreeMatrix(matrix, size);
    return 0;
}
