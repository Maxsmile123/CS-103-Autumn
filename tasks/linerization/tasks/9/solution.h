#pragma once

#include <stdint.h>
#include <stdio.h>

typedef int32_t** Matrix;

int Task()
{
    int n;

    // читаем матрицы до конца входного файла
    while (scanf("%d", &n) == 1) {
        if (n <= 0) {
            return 0;
        }

        int a[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (scanf("%d", &a[i][j]) != 1) {
                    return 0;
                }
            }
        }

        // перебираем диагонали от левого нижнего угла
        for (int d = 0; d < 2 * n - 1; d++) {
            int first = 0;
            int last = d;

            if (d >= n) {
                first = d - n + 1;
                last = n - 1;
            }

            if (d % 2 == 0) {
                // вверх и влево
                for (int j = last; j >= first; j--) {
                    int i = n - 1 - d + j;
                    printf("%d ", a[i][j]);
                }
            } else {
                // вниз и вправо
                for (int j = first; j <= last; j++) {
                    int i = n - 1 - d + j;
                    printf("%d ", a[i][j]);
                }
            }
        }

        printf("\n");
    }

    return 0;
}
