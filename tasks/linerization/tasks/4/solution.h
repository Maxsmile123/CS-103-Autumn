#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

int Task(void)
{
    int n;

    if (scanf("%d", &n) != 1 || n < 1) {
        return 1;
    }

    // Проверяем, что размеры выделяемой памяти не переполнятся.
    if ((size_t)n > SIZE_MAX / sizeof(int32_t*) ||
        (size_t)n > SIZE_MAX / sizeof(int32_t)) {
        return 1;
    }

    // Выделяем память под указатели на строки.
    Matrix matrix = (Matrix)malloc(n * sizeof(*matrix));

    if (matrix == NULL) {
        return 1;
    }

    // Выделяем память для каждой строки.
    for (int row = 0; row < n; row++) {
        matrix[row] = (int32_t*)malloc(n * sizeof(*matrix[row]));

        if (matrix[row] == NULL) {
            for (int previousRow = 0; previousRow < row; previousRow++) {
                free(matrix[previousRow]);
            }

            free(matrix);
            return 1;
        }
    }

    // Читаем матрицу по строкам.
    for (int row = 0; row < n; row++) {
        for (int column = 0; column < n; column++) {
            if (scanf("%d", &matrix[row][column]) != 1) {
                for (int allocatedRow = 0; allocatedRow < n; allocatedRow++) {
                    free(matrix[allocatedRow]);
                }

                free(matrix);
                return 1;
            }
        }
    }

    // Перебираем диагонали по сумме индексов.
    for (long long diagonal = 0; diagonal <= 2LL * n - 2; diagonal++) {
        int firstRow = n - 1;
        int lastRow = 0;

        if (diagonal < n) {
            firstRow = (int)diagonal;
        }

        if (diagonal >= n) {
            lastRow = (int)(diagonal - n + 1);
        }

        // Проходим диагональ снизу слева вверх направо.
        for (int row = firstRow; row >= lastRow; row--) {
            int column = (int)(diagonal - row);

            if (diagonal > 0) {
                printf(" ");
            }

            printf("%d", matrix[row][column]);
        }
    }

    printf("\n");

    // Освобождаем строки и список указателей.
    for (int row = 0; row < n; row++) {
        free(matrix[row]);
    }

    free(matrix);
    return 0;
}
