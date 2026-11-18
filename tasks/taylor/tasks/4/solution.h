#pragma once

#include <float.h>
#include <math.h>
#include <stdio.h>

long double Func(long double x) {
    return logl(2.0L + x);
}

static long double TaylorSum(long double x, long double tolerance, int *iterations) {
    const long double ln2 = 0.693147180559945309417232121458176568L;
    long double ratio = x / 2.0L;
    long double term = ratio;
    long double sum = ln2;
    long double tailFactor = 1.0L - fabsl(ratio);
    int count = 0;

    while (count < 100 && fabsl(term) / tailFactor > tolerance) {
        sum += term;
        ++count;
        term *= -ratio * count / (count + 1);
    }

    *iterations = count;
    return sum;
}

int Task(void) {
    int n;
    long double k;

    if (scanf("%d %Lf", &n, &k) != 2 || n < 1 || !isfinite(k) || k <= 0.0L) {
        return 1;
    }

    long double tolerance = LDBL_EPSILON * k;

    printf("LDBL_EPSILON = %.6Le\n", LDBL_EPSILON);
    printf("%14s %25s %25s %10s\n", "x", "Taylor", "logl(2+x)", "Iterations");

    for (long long i = 0; i <= n; ++i) {
        long double x = -1.0L + 2.0L * i / n;
        int iterations;
        long double approximation = TaylorSum(x, tolerance, &iterations);

        printf("%14.12Lg %25.21Lg %25.21Lg %10d\n",
               x, approximation, Func(x), iterations);
    }

    return 0;
}
