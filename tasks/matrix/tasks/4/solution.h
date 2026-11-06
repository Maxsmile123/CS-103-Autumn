#pragma once

#include <stdio.h>

int Task(void)
{
    FILE *file = fopen("input.txt", "r");

    if (file == NULL) {
        return 1;
    }

    int n;
    int matrix[8][8];

    if (fscanf(file, "%d", &n) != 1 || n < 1 || n > 8) {
        fclose(file);
        return 1;
    }

    int minRow = 0, maxRow = 0;
    long long minProduct = 0, maxProduct = 0;

    // Читаем матрицу и считаем произведения строк.
    for (int row = 0; row < n; row++) {
        long long product = 1;

        for (int column = 0; column < n; column++) {
            if (fscanf(file, "%d", &matrix[row][column]) != 1) {
                fclose(file);
                return 1;
            }

            product *= matrix[row][column];
        }

        if (row == 0 || product <= minProduct) {
            minProduct = product;
            minRow = row;
        }

        if (row == 0 || product >= maxProduct) {
            maxProduct = product;
            maxRow = row;
        }
    }

    fclose(file);

    // Меняем элементы найденных строк местами.
    for (int column = 0; column < n; column++) {
        int temp = matrix[minRow][column];
        matrix[minRow][column] = matrix[maxRow][column];
        matrix[maxRow][column] = temp;
    }

    printf("%d %d\n", n, n);

    for (int row = 0; row < n; row++) {
        for (int column = 0; column < n; column++) {
            if (column > 0) {
                printf(" ");
            }

            printf("%d", matrix[row][column]);
        }

        printf("\n");
    }

    return 0;
}
