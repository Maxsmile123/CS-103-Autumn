#pragma once

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

typedef int32_t** Matrix;

int Task() {

    int n;
    int32_t a[8][8];

    if (scanf("%d", &n) != 1 || n < 1 || n > 8)
        return 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%" SCNd32, &a[i][j]) != 1)
                return 1;
        }
    }

    int di[4] = {1, 0, -1, 0};
    int dj[4] = {0, 1, 0, -1};

    int i = (n - 1) / 2;
    int j = (n - 1) / 2;

    int dir = 0;
    int len = 1;
    int count = 1;
    int printed = 0;

    printf("%" PRId32, a[i][j]);
    printed = 1;

    while (count < n * n) {

        for (int rep = 0; rep < 2 && count < n * n; rep++) {

            for (int s = 0; s < len && count < n * n; s++) {

                i += di[dir];
                j += dj[dir];

                if (i >= 0 && i < n && j >= 0 && j < n) {

                    printf(" %" PRId32, a[i][j]);
                    count++;
                }
            }

            dir = (dir + 1) % 4;
        }

        len++;
    }

    printf("\n");

    return 0;
}
