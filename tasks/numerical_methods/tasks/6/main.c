#include <stdio.h>
#include <math.h>

typedef double (*Function)(double);

double f1(double x) {
    return x + cos(pow(x, 0.52) + 2.0);
}

double f2(double x) {
    double t = log(x);
    return 3.0 * t * t + 6.0 * t - 5.0;
}

double f3(double x) {
    return 0.6 * pow(3.0, x) - 2.3 * x - 3.0;
}

double phi_f1(double x) {
    return -cos(pow(x, 0.52) + 2.0);
}

double phi_f2(double x) {
    return x - f2(x) / 6.0;
}

double phi_f3(double x) {
    double t = (2.3 * x + 3.0) / 0.6;
    return log(t) / log(3.0);
}

double df1(double x) {
    return 1.0 - sin(pow(x, 0.52) + 2.0) * 0.52 * pow(x, -0.48);
}

double df2(double x) {
    double t = log(x);
    return 6.0 * t / x + 6.0 / x;
}

double df3(double x) {
    return 0.6 * pow(3.0, x) * log(3.0) - 2.3;
}

double dichotomy(Function f, double a, double b, double eps, int *steps) {
    *steps = 0;
    while (b - a >= eps) {
        double m = (a + b) / 2.0;
        double fm = f(m);
        *steps += 1;

        if (fm == 0.0) return m;
        if ((fm < 0.0) == (f(a) < 0.0)) a = m;
        else b = m;
    }
    return (a + b) / 2.0;
}

double iteration(Function phi, double a, double b, double eps, int *steps) {
    *steps = 0;
    double x = (a + b) / 2.0;

    for (int i = 0; i < 10000; i++) {
        double next = phi(x);
        *steps += 1;

        if (fabs(next - x) < eps) {
            return next;
        }

        x = next;
    }

    return x;
}

double niuton(Function f, Function df, double a, double b, double eps, int *steps) {
    *steps = 0;
    double x = (a + b) / 2.0;

    for (int i = 0; i < 10000; i++) {
        double fx = f(x);
        if (fx == 0.0) return x;

        double dx = df(x);
        if (dx == 0.0) return NAN;

        double next = x - fx / dx;
        *steps += 1;

        if (fabs(next - x) < eps) return next;

        x = next;
    }

    return x;
}

int main(void) {
    double eps = 1e-6;
    int steps;
    double ans;
    double a1 = 0.5, b1 = 1.0;
    double a2 = 1.0, b2 = 3.0;
    double a3 = 2.0, b3 = 3.0;

    printf("Табличное значение: 0.9892\nПолученные значения:\n");
    ans = dichotomy(f1, a1, b1, eps, &steps);
    printf("%f, число итераций: %d\n", ans, steps);
    ans = iteration(phi_f1, a1, b1, eps, &steps);
    printf("%f, число итераций: %d\n", ans, steps);
    ans = niuton(f1, df1, a1, b1, eps, &steps);
    printf("%f, число итераций: %d\n", ans, steps);
    printf("-----------------------------\n");
    printf("Табличное значение: 1.8832\nПолученные значения:\n");
    ans = dichotomy(f2, a2, b2, eps, &steps);
    printf("%f, число итераций: %d\n", ans, steps);
    ans = iteration(phi_f2, a2, b2, eps, &steps);
    printf("%f, число итераций: %d\n", ans, steps);
    ans = niuton(f2, df2, a2, b2, eps, &steps);
    printf("%f, число итераций: %d\n", ans, steps);
    printf("-----------------------------\n");
    printf("Табличное значение: 2.4200\nПолученные значения:\n");
    ans = dichotomy(f3, a3, b3, eps, &steps);
    printf("%f, число итераций: %d\n", ans, steps);
    ans = iteration(phi_f3, a3, b3, eps, &steps);
    printf("%f, число итераций: %d\n", ans, steps);
    ans = niuton(f3, df3, a3, b3, eps, &steps);
    printf("%f, число итераций: %d\n", ans, steps);

    return 0;
}