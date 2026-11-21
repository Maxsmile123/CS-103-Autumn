#pragma once

#include <inttypes.h>
#include <stdio.h>

int Task() {
    enum { MAX_MATRIX_SIZE = 8 };
    int32_t matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
    int64_t square[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];

    FILE* input = fopen("input.txt", "r");
    if (input == NULL) {
        return 1;
    }

    int size = 0;
    if (fscanf(input, "%d", &size) != 1 || size < 1 || size > MAX_MATRIX_SIZE) {
        fclose(input);
        return 1;
    }

    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            if (fscanf(input, "%" SCNd32, &matrix[row][col]) != 1) {
                fclose(input);
                return 1;
            }
        }
    }
    fclose(input);

    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            int64_t sum = 0;
            for (int k = 0; k < size; ++k) {
                int64_t product = (int64_t)matrix[row][k] * matrix[k][col];
                if ((product > 0 && sum > INT64_MAX - product) || (product < 0 && sum < INT64_MIN - product)) {
                    return 1;
                }
                sum += product;
            }
            square[row][col] = sum;
        }
    }

    printf("%d %d\n", size, size);
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            printf("%" PRId64 "%c", square[row][col], col + 1 == size ? '\n' : ' ');
        }
    }
    return 0;
}