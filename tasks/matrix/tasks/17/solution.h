
#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef int32_t** Matrix;

int Task() {

    int n;

    if (scanf("%d", &n) != 1 || n <= 0)
        return 1;

    size_t nn = (size_t)n;

    if (nn > SIZE_MAX / nn)
        return 1;

    size_t cells = nn * nn;

    if (nn > SIZE_MAX / sizeof(int32_t*) ||
        cells > SIZE_MAX / sizeof(int32_t))
        return 1;

    Matrix a = (Matrix)malloc(nn * sizeof(*a));
    int32_t* data = (int32_t*)malloc(cells * sizeof(*data));

    if (a == NULL || data == NULL) {
        free(a);
        free(data);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        a[i] = data + (size_t)i * nn;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%" SCNd32, &a[i][j]) != 1) {
                free(data);
                free(a);
                return 1;
            }
        }
    }

    int32_t min = a[0][0];
    int32_t max = a[0][0];

    int minRow = 0;
    int maxCol = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (a[i][j] < min) {
                min = a[i][j];
                minRow = i;
            }

            if (a[i][j] > max) {
                max = a[i][j];
                maxCol = j;
            }
        }
    }

    long long result = 0;

    for (int k = 0; k < n; k++) {
        result += (long long)a[minRow][k] * a[k][maxCol];
    }

    printf("%lld\n", result);

    free(data);
    free(a);

    return 0;
}
