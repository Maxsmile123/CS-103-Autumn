#pragma once

#include <stdio.h>
#include <math.h>

typedef double (*EquationFunc)(double);

double first_equation(double x) {
    return x + sqrt(x) + cbrt(x) - 2.5;
}

double second_equation(double x) {
    return 1.0 / (3.0 + sin(3.6 * x));
}

double solve_dichotomy(EquationFunc func, double left_border, double right_border, double epsilon) {
    while ((right_border - left_border) > epsilon) {
        double midpoint = (left_border + right_border) / 2.0;
        if (func(left_border) * func(midpoint) < 0.0) {
            right_border = midpoint;
        } else {
            left_border = midpoint;
        }
    }
    return (left_border + right_border) / 2.0;
}

double solve_iterations(EquationFunc func, double left_border, double right_border, double epsilon) {
    double start = (left_border + right_border) / 2.0;
    double current = func(start);
    while (fabs(current - start) > epsilon) {
        start = current;
        current = func(start);
    }
    return current;
}

int Task() {
    double epsilon;
    if (scanf("%lf", &epsilon) != 1 || epsilon <= 0.0) {
        return 1;
    }
    double root_dichotomy = solve_dichotomy(first_equation, 0.4, 1.0, epsilon);
    double root_iterations = solve_iterations(second_equation, 0.0, 0.85, epsilon);
    printf("%.15f %.15f\n", root_dichotomy, root_iterations);
    return 0;
}
