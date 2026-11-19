#pragma once

#include <float.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

long double Func(long double x) {
    long double t = x;
    long double sum = t;

    for (int i = 1; i < 100 && fabsl(t) >= LDBL_EPSILON; i++) {
        t = -t * x * x * (2 * i - 1) / (2 * i + 1);
        sum += t;
    }
    return sum;
}

int Task() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
        long double x = 0.5L * i / n;
        printf("%f %.15f %.15f\n", (double)x, (double)Func(x), (double)atanl(x));
    }
    return 0;
}
