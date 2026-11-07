#pragma once

#include <stdint.h>
#include <stdio.h>

typedef int32_t** Matrix;

int Task() {
    int n;
    int i, j, r, c; 

    while (scanf("%d", &n) == 1) {
        int matrix[8][8];
        int result[8][8];

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                scanf("%d", &matrix[i][j]);
                result[i][j] = matrix[i][j];
            }
        }

        for (i = 0; i < n; i++) {
            int sum = 0;

            for (r = 0; r < n; r++) {
                for (c = 0; c < n; c++) {
                    if (r + c == 2 * i) {
                        sum += matrix[r][c];
                    }
                }
            }

            result[i][i] = sum;
        }

        printf("%d %d\n", n, n);

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("%d", result[i][j]);
                if (j < n - 1) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }

    return 0;
}