#pragma once

#include <float.h>
#include <math.h>
#include <stdio.h>

long double Func(long double x) {
    return 1.0L / (2.0L * x - 5.0L);
}

int Task(void) {
    int n;
    long double k;

    if (scanf("%d %Lf", &n, &k) != 2 || n <= 0 || k <= 0.0L) {
        return 1;
    }

    long double eps = LDBL_EPSILON * k;
    printf("LDBL_EPSILON = %.6Le\n", LDBL_EPSILON);
    printf("%10s %22s %22s %8s\n", "x", "Taylor", "Func(x)", "terms");

    for (long long i = 0; i <= n; ++i) {
        long double x = 2.0L * i / n;
        long double ratio = 2.0L * x / 5.0L;
        long double term = -1.0L / 5.0L;
        long double sum = 0.0L;
        int terms = 0;

        do {
            sum += term;
            ++terms;
            term *= ratio;
        } while (terms < 100 && fabsl(term) / (1.0L - ratio) > eps);

        printf("%10.6Lf %22.15Lf %22.15Lf %8d\n",
               x, sum, Func(x), terms);
    }

    return 0;
}