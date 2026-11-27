#pragma once

#include <float.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

long double Func(long double x, long double eps, long double k, int *iters) {
    long double t = (x - 1.0L) / (x + 1.0L);
    long double term = t;
    long double sum = term;
    long double tol = eps * k;
    int iter = 0;

    while (fabsl(term) > tol && iter < 100) {
        iter++;
        term *= t * t * (2.0L * iter - 1.0L) / (2.0L * iter + 1.0L);
        sum += term;
    }

    *iters = iter;
    return sum;
}

int Task() {
    const long double eps = LDBL_EPSILON;

    const long double a = 0.2L;
    const long double b = 0.7L;

    int n;
    long double k;
    printf("Введите n и k: ");
    if (scanf("%d %Lf", &n, &k) != 2 || n <= 0 || k <= 0.0L) {
        printf("Ошибка ввода!\n");
        return 1;
    }

    long double h = (b - a) / n;

    printf("\nEPS = %.3Le, EPS*k = %.3Le\n\n", eps, eps * k);
    printf("%10s | %22s | %22s | %10s\n",
           "x", "Сумма ряда", "Значение функции", "Итераций");
    printf("-----------|------------------------|------------------------|------------\n");

    for (int i = 0; i <= n; ++i) {
        long double x = a + i * h;

        int iters = 0;
        long double sum = Func(x, eps, k, &iters);
        long double exact = 0.5L * logl(x);

        printf("%10.3Lf | %22.15Lf | %22.15Lf | %10d\n",
               x, sum, exact, iters);
    }
}

int main() {
    return Task();
}