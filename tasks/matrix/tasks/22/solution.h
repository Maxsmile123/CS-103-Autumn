#pragma once

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

typedef int32_t** Matrix;

int Task() {
    int32_t data[8][8];
    int32_t* rows[8];
    Matrix a = rows;
    int n;

    while (scanf("%d", &n) == 1) {
        if (n < 1 || n > 8) {
            return 1;
        }

        int32_t min = INT32_MAX;

        for (int i = 0; i < n; i++) {
            a[i] = data[i];

            for (int j = 0; j < n; j++) {
                if (scanf("%" SCNd32, &a[i][j]) != 1) {
                    return 1;
                }

                if (a[i][j] < min) {
                    min = a[i][j];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            int contains_min = 0;

            for (int j = 0; j < n; j++) {
                if (a[i][j] == min) {
                    contains_min = 1;
                    break;
                }
            }

            if (contains_min) {
                for (int j = 0; j < n / 2; j++) {
                    int32_t temp = a[i][j];
                    a[i][j] = a[i][n - 1 - j];
                    a[i][n - 1 - j] = temp;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%" PRId32 "%c",
                       a[i][j],
                       j == n - 1 ? '\n' : ' ');
            }
        }

        putchar('\n');
    }

    return 0;
}
