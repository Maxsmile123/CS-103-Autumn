#pragma once

#include <float.h>
#include <stdint.h>
#include <stdio.h>

long double Func(long double x) {
#ifdef __cplusplus
    using std::expl;
#else
    extern long double expl(long double);
#endif
    return (1.0L + x) * expl(-x);
}

int Task() {
    int n;
    long double k;
    if (scanf("%d %Lf", &n, &k) != 2 || n <= 0) {
        fputs("Enter a positive integer n followed by k.\n", stderr);
        return 1;
    }

    const long double tolerance = k * LDBL_EPSILON;
    if (!(tolerance > 0.0L && tolerance <= LDBL_MAX)) {
        fputs("k * LDBL_EPSILON must be positive and finite.\n", stderr);
        return 1;
    }

    const int precision = DECIMAL_DIG;
    const int width = precision + 7;
    const int max_iterations = 100;
    printf("LDBL_EPSILON = %.*Le\n", precision - 1, LDBL_EPSILON);
    printf("Tolerance    = %.*Le\n", precision - 1, tolerance);
    printf("f(x) = (1 + x) * exp(-x)\n");
    printf("%*s | %*s | %*s | %10s\n",
           width, "x", width, "Taylor sum", width, "f(x)", "Iterations");

    for (int i = 0; ; ++i) {
        const long double x = (long double)i / n;
        long double sum = 1.0L;
        long double term = -x * x / 2.0L;
        int iterations = 0;

        while (iterations < max_iterations &&
               (term <= -tolerance || term >= tolerance)) {
            const int degree = iterations + 2;
            sum += term;
            term *= -x * degree / ((degree - 1) * (degree + 1));
            ++iterations;
        }

        printf("%*.*Lg | %*.*Lg | %*.*Lg | %10d\n",
               width, precision, x, width, precision, sum,
               width, precision, Func(x), iterations);
        if (i == n) {
            break;
        }
    }

    return 0;
}
