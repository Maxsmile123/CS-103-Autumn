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

    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        return 1;
    }

    int n = 0;
    int read = 0;
    while ((read = fscanf(file, "%d", &n)) == 1) {
        if (n < 1 || n > 8) {
            fclose(file);
            return 1;
        }

        Matrix a = ReadMatrix(file, n);
        if (a == NULL) {
            fclose(file);
            return 1;
        }

        int32_t min = a[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] < min) {
                    min = a[i][j];
                }
            }
        }

        int rows = 0;
        for (int i = 0; i < n; i++) {
            int has_min = 0;
            for (int j = 0; j < n; j++) {
                if (a[i][j] == min) {
                    has_min = 1;
                }
            }

            if (has_min == 0) {
                for (int j = 0; j < n; j++) {
                    a[rows][j] = a[i][j];
                }
                rows++;
            }
        }

        printf("%d %d\n", rows, n);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < n; j++) {
                printf("%" PRId32 " ", a[i][j]);
            }
            printf("\n");
        }
        if (rows == 0) {
            printf("\n");
        }

        FreeMatrix(a, n);
    }

    int error = read != EOF || ferror(file);
    fclose(file);
    return error;
}
