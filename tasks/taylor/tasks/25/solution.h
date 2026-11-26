#pragma once

#include <float.h>
#include <stdint.h>
#include <stdio.h>

long double Func(long double x) {
    return 1.0L / (4.0L - x * x * x * x);
}

long double Taylor(long double x, int k, int* counter) {
    long double ratio = x * x * x * x / 4.0L;
    long double term = 0.25L;
    long double sum = term;
    long double eps = k * LDBL_EPSILON;
    *counter = 1;

    while (*counter < 100 && term * ratio / (1.0L - ratio) > eps) {
        term *= ratio;
        sum += term;
        (*counter)++;
    }
    return sum;
}

int Task(void) {
    int n = 0;
    int k = 0;
    if (scanf("%d%d", &n, &k) != 2 || n <= 0 || k <= 0) {
        return 1;
    }

    printf("x\tTaylor\tFunction\tCounter\n");
    for (int64_t i = 0; i <= n; i++) {
        long double x = (long double)i / n;
        int counter = 0;
        long double sum = Taylor(x, k, &counter);
        printf("%.10Lf\t%.10Lf\t%.10Lf\t%d\n", x, sum, Func(x), counter);
    }
    return 0;
}
