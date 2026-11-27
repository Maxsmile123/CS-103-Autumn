#pragma once

#include <float.h>
#include <stdint.h>

#include <math.h>
#include <stdio.h>

#define EPS 1e-6

typedef double (*Function)(double);

typedef struct {
    double root;
    double error;
    int steps;
} Result;

/* F возрастает: 1 < F' = 3 sin(x) + 2x cos(x) < 5 на [0.4, 1].
   Знаки F на концах различны, поэтому корень один.
   Для phi = x - F(x)/5 имеем 0 < phi' < 0.8. Функция возрастает,
   phi(a) > a и phi(b) < b, поэтому итерации остаются на отрезке.
   F'' = 5 cos(x) - 2x sin(x) > 0. Для Ньютона начинаем справа:
   касательная к выпуклой функции даёт точку между корнем и текущим x. */
static double f(double x)
{
    return 2.0 * x * sin(x) - cos(x);
}

static double df(double x)
{
    return 3.0 * sin(x) + 2.0 * x * cos(x);
}

static double phi(double x)
{
    return x - f(x) / 5.0;
}

/* На каждом шаге оставляем половину отрезка, содержащую корень. */
static Result bisection(Function f, double a, double b)
{
    int steps = 0;
    while (b - a >= EPS) {
        double mid = (a + b) / 2.0;
        double value = f(mid);
        ++steps;
        if (value == 0.0)
            return (Result){mid, 1e-14, steps};
        if ((f(a) < 0.0) == (value < 0.0))
            a = mid;
        else
            b = mid;
    }
    return (Result){(a + b) / 2.0, (b - a) / 2.0, steps};
}

/* Если |F'| >= m, по теореме Лагранжа |x - корень| <= |F(x)| / m.
   Небольшой запас учитывает округление double в этих примерах. */
static double error_bound(Function f, double x, double m)
{
    return fabs(f(x)) / m + 1e-14;
}

static Result iterations(Function f, Function phi, double x, double m)
{
    double previous, error;
    int steps = 0;
    do {
        previous = x;
        x = phi(previous);
        ++steps;
        error = error_bound(f, x, m);
    } while (fabs(x - previous) >= EPS || error >= EPS);
    return (Result){x, error, steps};
}

static Result newton(Function f, Function df, double x, double m)
{
    double previous, error;
    int steps = 0;
    do {
        previous = x;
        x = previous - f(previous) / df(previous);
        ++steps;
        error = error_bound(f, x, m);
    } while (fabs(x - previous) >= EPS || error >= EPS);
    return (Result){x, error, steps};
}

static void print_result(const char *method, Result r, double table_root)
{
    printf("%s\n  Root = %.12f, table value = %.4f\n"
           "  Error bound <= %.3e, steps = %d\n",
           method, r.root, table_root, r.error, r.steps);
}

int main(void)
{
    const double a = 0.4, b = 1.0, m = 1.0, table_root = 0.6533;
    printf("Variant 10. 2x sin(x) - cos(x) = 0\n");
    printf("Interval [%.1f, %.1f], tolerance %.0e\n", a, b, EPS);
    print_result("Bisection", bisection(f, a, b), table_root);
    print_result("Fixed-point iteration", iterations(f, phi, (a + b) / 2.0, m), table_root);
    print_result("Newton's method", newton(f, df, b, m), table_root);
    return 0;
}
