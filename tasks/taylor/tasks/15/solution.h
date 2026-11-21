#pragma once

#include <float.h>
#include <math.h>
#include <stdio.h>

long double Func(long double x) {
    return cosl(x);
}

static long double TaylorSum(long double x, long double tolerance, int* iterations) {
    const int max_iterations = 100;
    long double term = 1.0L;
    long double sum = term;
    *iterations = 0;

    for (int index = 1; index <= max_iterations; ++index) {
        long double twice_index = 2.0L * index;
        term *= -(x * x) / ((twice_index - 1.0L) * twice_index);
        if (fabsl(term) < tolerance) {
            break;
        }
        sum += term;
        ++*iterations;
    }
    return sum;
}

int Task() {
    int parts = 0;
    long double k = 0.0L;
    if (scanf("%d %Lf", &parts, &k) != 2 || parts < 1 || !isfinite(k) || k <= 0.0L) {
        return 1;
    }

    long double tolerance = LDBL_EPSILON * k;
    if (tolerance <= 0.0L) {
        return 1;
    }

    printf("Machine epsilon: %.*Le\n", LDBL_DECIMAL_DIG, (long double)LDBL_EPSILON);
    printf("%12s %24s %24s %12s\n", "x", "Taylor", "cos(x)", "Iterations");

    for (int index = 0;; ++index) {
        long double x = (long double)index / parts;
        int iterations = 0;
        long double sum = TaylorSum(x, tolerance, &iterations);
        printf("%12.8Lf %24.18Lf %24.18Lf %12d\n", x, sum, Func(x), iterations);
        if (index == parts) {
            break;
        }
    }
    return 0;
}
