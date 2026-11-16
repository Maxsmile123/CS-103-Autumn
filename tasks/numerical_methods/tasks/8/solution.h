#pragma once

#include <float.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

double func_iteration(double x) {
    return sqrt(3.0 + log(1.0 + x));
}

double func_ditoxomii(double x) {
    return 0.6 * pow(3.0, x) - 2.3 * x - 3.0;
}

double method_ditoxomi(double a, double b, double eps) {
    while (b - a >= eps) {
        double mid = (a + b) / 2.0;
        double f_mid = func_ditoxomii(mid);

        if (f_mid == 0.0) {
            return mid;
        }

        if (func_ditoxomii(a) * f_mid < 0.0) {
            b = mid;
        } else {
            a = mid;
        }
    }

    return (a + b) / 2.0;
}

double method_iteration(double a, double b, double eps){
    double x = (a+b)/2, next, *ptr_x = &x, *ptr_next = &next;
    *ptr_next = func_iteration(x);
    while (fabs(next - x)>eps){
        *ptr_x = next;
        *ptr_next = func_iteration(x);
    }
    return next;
}

int Task(void) {
    double eps;
    scanf("%lf", &eps);

    double root1 = method_ditoxomi(2.0, 3.0, eps);
    double root2 = method_iteration(2.0, 3.0, eps);
    printf("%.15f %.15f\n", root1, root2);

    return 0;
}