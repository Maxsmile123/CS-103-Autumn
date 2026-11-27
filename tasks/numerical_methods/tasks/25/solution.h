// решения задач от Крылова С.С. 3 задачи тремя способами

#include <math.h>
#include <stdio.h>

double Equation25(double x) {
    return sqrt(1.0 - 0.4 * x * x) - asin(x);
}

double Equation26(double x) {
    return exp(x) - exp(-x) - 2.0;
}

double Equation27(double x) {
    double t = log(x);
    return sin(t) - cos(t) + 2.0 * t;
}

double Derivative25(double x) {
    return -0.4 * x / sqrt(1.0 - 0.4 * x * x) - 1.0 / sqrt(1.0 - x * x);
}

double Derivative26(double x) {
    return exp(x) + exp(-x);
}

double Derivative27(double x) {
    double t = log(x);
    return (cos(t) + sin(t) + 2.0) / x;
}

double Dichotomy(double (*f)(double), double a, double b, double eps, double *error, int *steps) {
    double left_value = f(a);
    *steps = 0;

    while (b - a >= eps) {
        double middle = (a + b) / 2.0;
        double value = f(middle);
        (*steps)++;

        if (value == 0.0) {
            *error = 0.0;
            return middle;
        }
        if ((left_value < 0.0) == (value < 0.0)) {
            a = middle;
            left_value = value;
        } else {
            b = middle;
        }
    }

    *error = (b - a) / 2.0;
    return (a + b) / 2.0;
}

double Iteration25(double x) {
    return sin(sqrt(1.0 - 0.4 * x * x));
}

double Iteration26(double x) {
    return log(2.0 + exp(-x));
}

double Iteration27(double x) {
    return x - Equation27(x) / 4.0;
}


double SimpleIteration(double (*g)(double), double x, double eps, double q, double *error, int *steps) {
    *steps = 0;
    double change = 0.0;
    do {
        double next = g(x);
        change = fabs(next - x);
        x = next;
        (*steps)++;
        *error = q * change / (1.0 - q);
    } while (change >= eps || *error >= eps);

    return x;
}

double Newton(double (*f)(double), double (*derivative)(double), double x, double eps, double *error, int *steps) {
    double value = f(x);
    *steps = 0;
    while (fabs(value) >= eps) {
        x -= value / derivative(x);
        value = f(x);
        (*steps)++;
    }

    *error = fabs(value);
    return x;
}

void PrintResult(int number, double (*f)(double), double (*g)(double), double (*derivative)(double), double a, double b,
                 double reference, double q) {
    const double eps = 1e-8;
    const double midpoint = (a + b) / 2.0;
    double error = 0.0;
    int steps = 0;
    double root = Dichotomy(f, a, b, eps, &error, &steps);
    printf("%d    Дихотомия   %.10f    %.4f    %.3e    %d\n", number, root, reference, error, steps);
    root = SimpleIteration(g, midpoint, eps, q, &error, &steps);
    printf("%d    Итерации    %.10f    %.4f    %.3e    %d\n", number, root, reference, error, steps);
    root = Newton(f, derivative, midpoint, eps, &error, &steps);
    printf("%d    Ньютон      %.10f    %.4f    %.3e    %d\n", number, root, reference, error, steps);
}

int main(void) {
    printf("№     Метод       Корень          Таблица   Граница ошибки   Шаги\n");
    PrintResult(25, Equation25, Iteration25, Derivative25, 0.0, 1.0, 0.7672, 0.52);
    PrintResult(26, Equation26, Iteration26, Derivative26, 0.0, 1.0, 0.8814, 1.0 / 3.0);
    PrintResult(27, Equation27, Iteration27, Derivative27, 1.0, 3.0, 1.3749, 0.75);
    return 0;
}
