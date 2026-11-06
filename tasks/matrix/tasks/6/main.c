#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int rows;
    int cols;
    if (scanf("%d%d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
        return 1;
    }

    if ((size_t)rows > SIZE_MAX / sizeof(double) / (size_t)cols) {
        return 1;
    }

    double (*matrix)[cols] = malloc((size_t)rows * sizeof(*matrix));
    if (matrix == NULL) {
        return 1;
    }

    double min_value = 0.0;
    int last_col = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (scanf("%lf", &matrix[i][j]) != 1) {
                free(matrix);
                return 1;
            }

            if ((i == 0 && j == 0) || matrix[i][j] < min_value) {
                min_value = matrix[i][j];
                last_col = j;
            } else if (matrix[i][j] == min_value && j > last_col) {
                last_col = j;
            }
        }
    }

    for (int j = 0; j < last_col; ++j) {
        int i = 0;
        while (i < rows && matrix[i][j] != min_value) {
            ++i;
        }

        if (i < rows) {
            for (int row = 0; row < rows; ++row) {
                matrix[row][last_col] += matrix[row][j];
            }
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (j > 0) {
                putchar(' ');
            }
            printf("%.15g", matrix[i][j]);
        }
        putchar('\n');
    }

    free(matrix);
    return 0;
}
