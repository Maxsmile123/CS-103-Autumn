#pragma once

#include <float.h>
#include <stdint.h>
#include <stdio.h>

int Task() {
    int n;
    int a[10][10];
    int i, j, s, step;
    int i_min, i_max, first;

    while (scanf("%d", &n) == 1) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                scanf("%d", &a[i][j]);
            }
        }

        step = 0;
        first = 1;

        for (s = 2 * n - 2; s >= 0; s--) {
            i_min = s - (n - 1);
            if (i_min < 0) {
                i_min = 0;
            }

            i_max = s;
            if (i_max > n - 1) {
                i_max = n - 1;
            }

            if (step % 2 == 1) {
                for (i = i_min; i <= i_max; i++) {
                    j = s - i;
                    if (!first) {
                        printf(" ");
                    }
                    printf("%d", a[i][j]);
                    first = 0;
                }
            } else {
                for (i = i_max; i >= i_min; i--) {
                    j = s - i;
                    if (!first) {
                        printf(" ");
                    }
                    printf("%d", a[i][j]);
                    first = 0;
                }
            }

            step++;
        }

        printf("\n");
    }
    return 0;
}