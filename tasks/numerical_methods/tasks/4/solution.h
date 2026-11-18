#pragma once

#include <float.h>
#include <math.h>
#include <stdio.h>

typedef long double (*Function)(long double);

static long double FirstEquation(long double x) {
    return 3.0L * x - 14.0L + expl(x) - expl(-x);
}

static long double FirstDerivative(long double x) {
    return 3.0L + expl(x) + expl(-x);
}

static long double SecondEquation(long double x) {
    return sqrtl(1.0L - x) - tanl(x);
}

// Для возрастающей выпуклой функции начинаем с правого конца.
static long double Newton(Function f, Function derivative,
                          long double left, long double right, long double epsilon) {
    long double minDerivative = derivative(left);
    long double x = right;
    long double value = f(x);
    long double previousStep = 0.0L;

    for (;;) {
        long double next = x - value / derivative(x);
        long double step = fabsl(next - x);
        long double nextValue = f(next);
        long double errorBound = fabsl(nextValue) / minDerivative;

        if (next == x) {
            return errorBound <= epsilon ? next : NAN;
        }

        if (previousStep > step) {
            long double estimate = step / (1.0L - step / previousStep);
            if (estimate < epsilon && errorBound <= epsilon) {
                return next;
            }
        }

        previousStep = step;
        x = next;
        value = nextValue;
    }
}

static long double Bisection(Function f, long double left, long double right,
                             long double epsilon) {
    long double leftValue = f(left);

    while (right - left >= epsilon) {
        long double middle = left + (right - left) / 2.0L;
        long double middleValue = f(middle);

        if (middleValue == 0.0L) {
            return middle;
        }
        if (middle == left || middle == right) {
            return NAN;
        }

        if ((leftValue < 0.0L) == (middleValue < 0.0L)) {
            left = middle;
            leftValue = middleValue;
        } else {
            right = middle;
        }
    }

    return left + (right - left) / 2.0L;
}

int Task(void) {
    long double epsilon;

    if (scanf("%Lf", &epsilon) != 1 || !isfinite(epsilon) || epsilon <= 0.0L) {
        return 1;
    }

    long double firstRoot = Newton(FirstEquation, FirstDerivative, 1.0L, 3.0L, epsilon);
    long double secondRoot = Bisection(SecondEquation, 0.0L, 1.0L, epsilon);

    if (!isfinite(firstRoot) || !isfinite(secondRoot)) {
        return 1;
    }

    printf("%.*Lg %.*Lg\n", LDBL_DECIMAL_DIG, firstRoot,
           LDBL_DECIMAL_DIG, secondRoot);
    return 0;
}
