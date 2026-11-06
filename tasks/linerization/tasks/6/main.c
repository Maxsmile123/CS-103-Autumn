#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    size_t side = (size_t)n;
    if (side > SIZE_MAX / sizeof(int) / side) {
        return 1;
    }

    int (*matrix)[n] = malloc(side * sizeof(*matrix));
    if (matrix == NULL) {
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                free(matrix);
                return 1;
            }
        }
    }

    int i = 0;
    int j = n - 1;
    printf("%d ", matrix[i][j]);

    ++i;

    for (size_t k = 1; k < 2 * side - 1; ++k) {
        if (k % 2 == 1) {
            for (; i > 0 && j > 0; --i, --j) {
                printf("%d ", matrix[i][j]);
            }
            printf("%d ", matrix[i][j]);

            if (i == n - 1 && j == 0) {
                break;
            }

            if (j == 0) {
                ++i;
            } else {
                --j;
            }
        } else {
            for (; j < n - 1 && i < n - 1; ++j, ++i) {
                printf("%d ", matrix[i][j]);
            }
            printf("%d ", matrix[i][j]);

            if (i == n - 1 && j == 0) {
                break;
            }

            if (i == n - 1) {
                --j;
            } else {
                ++i;
            }
        }
    }

    free(matrix);
    return 0;
}