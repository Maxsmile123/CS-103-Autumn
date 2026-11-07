#pragma once

#include <stdint.h>
#include <stdio.h>

typedef int32_t** Matrix;

int Task()
{
    const int group = 103;
    int size;

    while (scanf("%d", &size) == 1) {
        if (size < 1 || size > 8) {
            return 0;
        }

        int a[8][8];
        int b[8][8];

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (scanf("%d", &a[i][j]) != 1) {
                    return 0;
                }
            }
        }

        int count = size * size;
        int shift = group % count;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int k = (i * size + j + shift) % count;
                b[k / size][k % size] = a[i][j];
            }
        }

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf("%d ", b[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
