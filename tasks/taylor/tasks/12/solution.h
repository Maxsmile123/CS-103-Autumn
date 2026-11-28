#pragma once

#include <float.h>
#include <stdint.h>
#include <stdio.h>

long double Func(long double x) {
    return powl(3.0L, x);
}

int Task() {
    const long double a = 0.0L;
    const long double b = 1.0L;
    const int max_iter = 100;

    int n = 0;
    long double k = 0.0L;

    printf("Введите количество разбиений n и коэффициент точности k: \n");
    if (scanf("%d %Lf", &n, &k) != 2 || n <= 0 || k <= 0.0L) {
        printf("Ошибка ввода.\n");
        return 1;
    }

    const long double eps = LDBL_EPSILON * k;
    const long double ln3 = logl(3.0L);
    const long double step = (b - a) / (long double)n;

    printf("\nМашинное эпсилон для типа long double = %.20Le\n\n", LDBL_EPSILON);
    printf("Таблица значений ряда Тейлора и стандартной функции для f(x) = 3^x\n\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("| %-10s | %-44s | %-43s | %-31s |\n",
           "x", "част. сумма ряда для 3^x", "значения функции 3^x", "число итераций");
    printf("-------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i <= n; ++i) {
        long double x = a + step * (long double)i;
        if (i == n) {
            x = b;
        }

        long double term = 1.0L;
        long double taylor_sum = term;
        int iter = 1;

        while (fabsl(term) >= eps && iter < max_iter) {
            term *= (x * ln3) / (long double)iter;
            taylor_sum += term;
            ++iter;
        }

        long double exact_val = Func(x);

        printf("| %-10.4Lf | %-28.18Lf | %-28.18Lf | %-18d |\n",
               x, taylor_sum, exact_val, iter);
    }

    printf("-------------------------------------------------------------------------------------------------\n");
    return 0;
}

