#pragma once

#include <float.h>
#include <stdint.h>
#include <stdio.h>

double phi(double x);
double simple_iteration(double (*phi)(double), double a, double b, double eps);

double f(double x);
double df(double x);
double newton_method(double (*f)(double), double (*df)(double), double a, double b, double eps);

// 1-е уравнение: x = ln(x) + 1.8
double phi(double x) {
    return log(x) + 1.8;
}

// 2-е уравнение: f(x) = x * tg(x) - 1/3
double f(double x) {
    return x * tan(x) - 1.0 / 3.0;
}

// Производная 2-го уравнения: f'(x) = tg(x) + x / cos^2(x)
double df(double x) {
    double cos_x = cos(x);
    return tan(x) + x / (cos_x * cos_x);
}

// Метод простых итераций (принимает указатель на функцию phi)
double simple_iteration(double (*phi)(double), double a, double b, double eps) {
    // x_{n-1}, x_n, x_{n+1}
    double x_prev = (a + b) / 2.0;
    double x_curr = phi(x_prev);
    double x_next = phi(x_curr);

    while (fabs((x_next - x_curr) / (1.0 - (x_next - x_curr) / (x_curr - x_prev))) >= eps) {
        x_prev = x_curr;
        x_curr = x_next;
        x_next = phi(x_curr);
    }

    return x_next;
}

// Метод Ньютона (прринимает указатели на функцию и ее производную)
double newton_method(double (*f)(double), double (*df)(double), double a, double b, double eps) {
    double x_prev = (a + b) / 2.0;
    double x_curr = x_prev - f(x_prev) / df(x_prev);
    double x_next = x_curr - f(x_curr) / df(x_curr);

    while (fabs((x_next - x_curr) / (1.0 - (x_next - x_curr) / (x_curr - x_prev))) >= eps) {
        x_prev = x_curr;
        x_curr = x_next;
        x_next = x_curr - f(x_curr) / df(x_curr);
    }

    return x_next;
}

int Task() {
    double eps = DBL_EPSILON * 1000.0;

    double root1 = simple_iteration(phi, 2.0, 3.0, eps);
    double root2 = newton_method(f, df, 0.2, 1.0, eps);

    printf("%.14lf %.14lf\n", root1, root2);
    return 0;
}