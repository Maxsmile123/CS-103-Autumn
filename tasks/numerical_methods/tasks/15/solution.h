#pragma once

#include <float.h>
#include <math.h>
#include <stdio.h>

static long double FirstEquation(long double x) {
    return 0.4L + atanl(sqrtl(x)) - x;
}

static long double SecondEquation(long double x) {
    return 3.0L * sinl(sqrtl(x)) + 0.35L * x - 3.8L;
}

static long double Iterate(long double (*equation)(long double), long double left, long double right, long double scale,
                           long double min_slope, long double epsilon) {
    long double current = (left + right) / 2.0L;

    for (;;) {
        long double value = equation(current);
        // By the mean value theorem, |f(x)| / min_slope bounds the root error.
        if (fabsl(value) / min_slope <= epsilon) {
            return current;
        }

        long double next = current - value / scale;
        if (next == current || next < left || next > right) {
            return NAN;
        }
        current = next;
    }
}

int Task() {
    long double epsilon = 0.0L;
    if (scanf("%Lf", &epsilon) != 1 || !isfinite(epsilon) || epsilon <= 0.0L) {
        return 1;
    }

    long double first_root = Iterate(FirstEquation, 1.0L, 2.0L, -1.0L, 0.75L, epsilon);
    long double second_root = Iterate(SecondEquation, 2.0L, 3.0L, 0.6L, 0.2L, epsilon);
    if (!isfinite(first_root) || !isfinite(second_root)) {
        return 1;
    }

    printf("%.*Lg %.*Lg\n", LDBL_DECIMAL_DIG, first_root, LDBL_DECIMAL_DIG, second_root);
    return 0;
}
