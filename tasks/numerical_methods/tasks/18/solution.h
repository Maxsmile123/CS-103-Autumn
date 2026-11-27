#include <stdio.h>
#include <math.h>

#define EPS 1e-7

// Первое уравнение: метод дихотомии
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

// Второе уравнение: метод итераций
// x - 1 / (3 + sin(3.6 * x)) = 0
// приведено к виду x = phi(x)

double phi(double x) {
    return 1.0 / (3.0 + sin(3.6 * x));
}

double iteration_method() {
    double x = 0.0;
    double next;

    do {
        next = phi(x);

        if (fabs(next - x) < EPS)
            return next;

        x = next;

    } while (1);
}

int main() {
    double root1 = dichotomy_method();
    double root2 = iteration_method();

    printf("Dichotomy method: %.4f\n", root1);
    printf("Iteration method: %.4f\n", root2);

    return 0;
}
