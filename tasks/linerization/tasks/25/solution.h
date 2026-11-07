#pragma once

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

void FreeMatrix(Matrix a, int n) {
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
}

Matrix ReadMatrix(FILE* file, int n) {
    if ((size_t)n > SIZE_MAX / sizeof(int32_t*) || (size_t)n > SIZE_MAX / sizeof(int32_t)) {
        return NULL;
    }

    Matrix a = (Matrix)calloc((size_t)n, sizeof(int32_t*));
    if (a == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        a[i] = (int32_t*)malloc((size_t)n * sizeof(int32_t));
        if (a[i] == NULL) {
            FreeMatrix(a, n);
            return NULL;
        }

        for (int j = 0; j < n; j++) {
            if (fscanf(file, "%" SCNd32, &a[i][j]) != 1) {
                FreeMatrix(a, n);
                return NULL;
            }
        }
    }

    return a;
}

int Task(void) {

    int n = 0;
    if (scanf("%d", &n) != 1 || n < 1) {
        return 1;
    }

    Matrix a = ReadMatrix(stdin, n);
    if (a == NULL) {
        return 1;
    }

    for (int k = 0; k < n / 2 + n % 2; k++) {
        int last = n - 1 - k;

        for (int i = last; i >= k; i--) {
            printf("%" PRId32 " ", a[i][last]);
        }
        for (int j = last - 1; j >= k; j--) {
            printf("%" PRId32 " ", a[k][j]);
        }
        for (int i = k + 1; i <= last; i++) {
            printf("%" PRId32 " ", a[i][k]);
        }
        for (int j = k + 1; j < last; j++) {
            printf("%" PRId32 " ", a[last][j]);
        }
    }

    printf("\n");
    FreeMatrix(a, n);

    return 0;
}
