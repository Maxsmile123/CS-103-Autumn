#pragma once

#include <float.h>
#include <stdint.h>
#include <stdio.h>

long double Func(long double x) {
    long double denom = 1.0L - x;
    return (x * (3.0L - x)) / (denom * denom * denom);
}

int Task() {
    long double eps = 1.0L;
    while (1.0L + eps / 2.0L > 1.0L) {
        eps = eps / 2.0L;
    }

    long double a = 0.0L;
    long double b = 0.5L;
    int parts = 10;
    long double k = 10.0L;
    long double precision = eps * k;
    int max_iter = 100;

    long double step = (b - a) / parts;

    printf("Mashinnoe epsilon: %Le\n", eps);
    printf("Tochnost (eps * k): %Le\n\n", precision);


    printf("-------------------------------------------------------------------------\n");
    printf("|    x    |   Chast. summa ryada   |   Znachenie funkcii    | Iteracii  |\n");
    printf("-------------------------------------------------------------------------\n");

    for (int i = 0; i <= parts; i++) {
        long double x = a + i * step;

        long double exact_val = Func(x);

        long double sum = 0.0L;
        long double x_pow = 1.0L;
        int n = 0;

        if (x == 0.0L) {
            sum = 0.0L;
            n = 1;
        } else {
            while (n < max_iter) {
                n++;
                x_pow = x_pow * x;

                long double term = n * (n + 2) * x_pow;
                sum = sum + term;

                long double abs_term = (term < 0.0L) ? -term : term;
                if (abs_term < precision) {
                    break;
                }
            }
        }

        printf("| %7.2Lf | %22.15Lf | %22.15Lf | %9d |\n", x, sum, exact_val, n);
    }

    printf("-------------------------------------------------------------------------\n");

    return 0;
}
