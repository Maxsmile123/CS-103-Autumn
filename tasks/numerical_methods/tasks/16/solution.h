#include <stdio.h>
#include <math.h>

#define EPS 1e-7

// Первое уравнение: метод итерации
double phi(double x) {
    return (3.8 - 3.0 * sin(sqrt(x))) / 0.35;
}

double simple_iteration() {
    double x = 2.5;
    double next;

    do {
        next = phi(x);

        if (fabs(next - x) < EPS) {
            return next;
        }

        x = next;
    } while (1);
}

// Второе уравнение: метод Ньютона
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

        if (fabs(next - x) < EPS) {
            return next;
        }

        x = next;
    } while (1);
}

int main() {
    double x1 = simple_iteration();
    double x2 = newton_method();

    printf("Simple iteration: %.4f\n", x1);
    printf("Newton method: %.4f\n", x2);

    return 0;
}
