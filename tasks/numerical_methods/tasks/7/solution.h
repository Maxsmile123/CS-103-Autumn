#pragma once

#include <float.h>
#include <stdint.h>
#include <stdio.h>

int Task() {
    #include <stdio.h>
#include <math.h>

#define EPS 0.0001

double F7(double x) {
    return 3.0 * pow(log(x), 2) + 6.0 * log(x) - 5.0;
}

double dF7(double x) { // Производная F'(x)
    return (6.0 * log(x) + 6.0) / x;
}

double f7_iter(double x) { // Функция x = f(x)
    return exp((5.0 - 3.0 * pow(log(x), 2)) / 6.0);
}


void dichotomy(double (*F)(double), double a, double b, double exact_root) {
    int iter = 0;
    double c;


    if (F(a) * F(b) >= 0) {
        printf("  Дихотомия: Метод неприменим (одинаковые знаки на концах)\n");
        return;
    }

    while (fabs(b - a) >= EPS) {
        c = (a + b) / 2.0;
        if (F(a) * F(c) > 0) {
            a = c;
        } else {
            b = c;
        }
        iter++;
    }

    double root = (a + b) / 2.0;
    double acc = fabs(root - exact_root); // Достигнутая точность относительно таблицы
    printf("  Дихотомия: корень = %.5f | таблица = %.4f | точность = %.5f | шагов = %d\n",
           root, exact_root, acc, iter);
}


void iteration(double (*f)(double), double a, double b, double exact_root) {
    int iter = 0;
    double x0 = (a + b) / 2.0; // Начальное приближение (середина отрезка)
    double x1 = f(x0);
    iter++;

    while (fabs(x1 - x0) >= EPS) {
        x0 = x1;
        x1 = f(x0);
        iter++;

        if (iter > 1000) {
            printf("  Итерации:  Метод расходится!\n");
            return;
        }
    }

    double acc = fabs(x1 - exact_root);
    printf("  Итерации:  корень = %.5f | таблица = %.4f | точность = %.5f | шагов = %d\n",
           x1, exact_root, acc, iter);
}

void newton(double (*F)(double), double (*dF)(double), double a, double b, double exact_root) {
    int iter = 0;
    double x0 = (a + b) / 2.0;
    double x1 = x0 - F(x0) / dF(x0);
    iter++;

    while (fabs(x1 - x0) >= EPS) {
        x0 = x1;
        x1 = x0 - F(x0) / dF(x0);
        iter++;

        if (iter > 1000) {
            printf("  Ньютон:    Метод расходится!\n");
            return;
        }
    }

    double acc = fabs(x1 - exact_root);
    printf("  Ньютон:    корень = %.5f | таблица = %.4f | точность = %.5f | шагов = %d\n",
           x1, exact_root, acc, iter);
}

int main() {
    printf("Точность вычислений EPS = %.4f\n\n", EPS);

    printf("=== Вариант 7: 3*ln^2(x) + 6*ln(x) - 5 = 0 на [1, 3] ===\n");
    dichotomy(F7, 1.0, 3.0, 1.8832);
    iteration(f7_iter, 1.0, 3.0, 1.8832);
    newton(F7, dF7, 1.0, 3.0, 1.8832);
    printf("\n");

    return 0;
}

    return 0;
}