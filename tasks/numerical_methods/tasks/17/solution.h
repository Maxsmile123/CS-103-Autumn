#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

double F17(double x) {
    return 0.25 * x * x * x + x - 1.2502;
}
double dF17(double x) {
    return 0.75 * x * x + 1.0;
}

double F18(double x) {
    return x + sqrt(x) + cbrt(x) - 2.5;
}

double newton(double (*F)(double), double (*dF)(double), double x0, double eps, int *iter) {
    double x = x0, xp;
    *iter = 0;
    do {
        xp = x;
        x = x - F(x) / dF(x);
        (*iter)++;
    } while (fabs(x - xp) > eps);
    return x;
}

double bisect(double (*F)(double), double a, double b, double eps, int *iter) {
    *iter = 0;
    while (fabs(b - a) > eps) {
        double c = (a + b) / 2.0;
        if (F(a) * F(c) > 0)
            a = c;
        else
            b = c;
        (*iter)++;
    }
    return (a + b) / 2.0;
}

int Task() {
    double eps;
    if (scanf("%lf", &eps) != 1)
        return 1;

    int i17, i18;
    double r17 = newton(F17, dF17, 2.0, eps, &i17);
    double r18 = bisect(F18, 0.4, 1.0, eps, &i18);

    printf("%.15g %.15g\n", r17, r18);
    return 0;
}

int main(void) {
    return Task();
}