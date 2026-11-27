#pragma once

#include <float.h>
#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus
using std::cosl;
using std::logl;
using std::sqrtl;
#else
extern long double cosl(long double);
extern long double logl(long double);
extern long double sqrtl(long double);
#endif

typedef long double (*NumericalFunction)(long double);

static long double FirstIteration(long double x) {
    return cosl(sqrtl(1.0L - 0.3L * x * x * x));
}

static long double SecondEquation(long double x) {
    return 3.0L * x - 4.0L * logl(x) - 5.0L;
}

static long double SecondDerivative(long double x) {
    return 3.0L - 4.0L / x;
}

static long double Absolute(long double value) {
    return value < 0.0L ? -value : value;
}

static long double FindRoot(NumericalFunction function,
                            NumericalFunction derivative,
                            long double x, long double epsilon) {
    long double previous_step = 0.0L;

    for (int iteration = 0; iteration < 256; ++iteration) {
        const long double next = derivative == NULL
            ? function(x)
            : x - function(x) / derivative(x);
        const long double step = next - x;

        if (step == 0.0L) {
            return next;
        }

        if (previous_step != 0.0L && Absolute(step) < epsilon) {
            const long double denominator = 1.0L - step / previous_step;
            if (denominator != 0.0L && Absolute(step / denominator) < epsilon) {
                return next;
            }
        }

        x = next;
        previous_step = step;
    }

    return x;
}

int Task() {
    long double epsilon;
    if (scanf("%Lf", &epsilon) != 1 ||
        !(epsilon > 0.0L && epsilon <= LDBL_MAX)) {
        return 1;
    }

    const long double first_root = FindRoot(FirstIteration, NULL, 0.5L, epsilon);
    const long double second_root = FindRoot(SecondEquation, SecondDerivative,
                                            4.0L, epsilon);

    printf("%.*Lg %.*Lg\n", DECIMAL_DIG, first_root, DECIMAL_DIG, second_root);
    return 0;
}
