#include <stdio.h>
#include <math.h>

#define EPS 1e-7

// Первое уравнение: метод Ньютона
// 0.25*x^3 + x - 1.2502 = 0

double f(double x) {
    return 0.25 * x * x * x + x - 1.2502;
}

double df(double x) {
    return 0.75 * x * x + 1.0;
}

double newton_method() {
    double x = 2.0;
    double next;

    do {
        next = x - f(x) / df(x);

        if (fabs(next - x) < EPS)
            return next;

        x = next;

    } while (1);
}

// Второе уравнение: метод дихотомии
// x + sqrt(x) + cbrt(x) - 2.5 = 0

double g(double x) {
    return x + sqrt(x) + cbrt(x) - 2.5;
}

double dichotomy_method() {
    double a = 0.4;
    double b = 1.0;
    double c;

    while ((b - a) / 2.0 > EPS) {
        c = (a + b) / 2.0;

        if (g(a) * g(c) < 0)
            b = c;
        else
            a = c;
    }

    return (a + b) / 2.0;
}

int main() {
    double root1 = newton_method();
    double root2 = dichotomy_method();

    printf("Newton method: %.4f\n", root1);
    printf("Dichotomy method: %.4f\n", root2);

    return 0;
}
