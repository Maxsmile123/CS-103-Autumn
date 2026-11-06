#pragma once

#include <stdint.h>
#include <stdio.h>

typedef int32_t** Matrix;

int Task() {
    int n, f = 1, c = 0;
    int32_t x, m = 0;
    int64_t p[8];
    if (scanf("%d", &n) != 1) {
        return 0;
    }
    for (int j = 0; j < n; ++j) {
        p[j] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (scanf("%d", &x) != 1) {
                 return 0;
            }
            p[j] *= x;
            if (f) {
                m = x;
                c = j;
                f = 0;
            } else if (x < m) {
                m = x;
                c = j;
            } else if (x == m && j > c) {
                c = j;
            }
        }
    }

    printf("%lld\n", (long long)p[c]);
    return 0;
}