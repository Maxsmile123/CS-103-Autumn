#pragma once

#include <float.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

// Первое уравнение в виде x = phi(x).
double phi(double x) {
    return sqrt(log(1 + x) + 3);
}

// Левая часть второго уравнения.
double f(double x) {
    return 2 * x * sin(x) - cos(x);
}

// Производная левой части второго уравнения.
double df(double x) {
    return 3 * sin(x) + 2 * x * cos(x);
}

// Метод простых итераций.
double iterations(double (*g)(double), double a, double b,
                  double eps, int *steps, double *accuracy) {
    double x = (a + b) / 2;
    double previous;

    *steps = 0;

    do {
        previous = x;
        x = g(previous);

        *accuracy = fabs(x - previous);
        (*steps)++;
    } while (*accuracy >= eps);

    return x;
}

// Метод Ньютона.
double newton(double (*g)(double), double (*dg)(double),
              double a, double b, double eps,
              int *steps, double *accuracy) {
    double x = (a + b) / 2;
    double previous;

    *steps = 0;

    do {
        previous = x;
        x = previous - g(previous) / dg(previous);

        *accuracy = fabs(x - previous);
        (*steps)++;
    } while (*accuracy >= eps);

    return x;
}

int Task() {
    double eps;
    double root1, root2;
    double accuracy;
    int steps;

    if (scanf("%lf", &eps) != 1 || eps <= 0) {
        return 1;
    }

    root1 = iterations(phi, 2.0, 3.0, eps, &steps, &accuracy);
    root2 = newton(f, df, 0.4, 1.0, eps, &steps, &accuracy);

    printf("%.15f %.15f\n", root1, root2);

    return 0;
}
