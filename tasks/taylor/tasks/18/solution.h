#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

long double Func(long double x) {
    return ((1.0L + x * x) / 2.0L) * atanl(x) - x / 2.0L;
}

long double get_machine_epsilon(void) {
    long double eps = 1.0L;
    while (1.0L + eps / 2.0L > 1.0L) {
        eps /= 2.0L;
    }
    return eps;
}

long double calculate_taylor(long double x, long double eps, long double coeff_k, int *iterations) {
    long double term = (x * x * x) / 3.0L;
    long double sum = term;
    int step = 1;

    while (fabsl(term) > eps * coeff_k && step < 100) {
        step++;
        term = -term * x * x * (2.0L * step - 3.0L) / (2.0L * step + 1.0L);
        sum += term;
    }

    *iterations = step;
    return sum;
}

int Task() {
    int partitions = 8;
    long double coeff_k = 1.0L;

    if (scanf("%d", &partitions) == 1) {
        if (partitions <= 0) {
            return 1;
        }
    }

    long double left_border = 0.1L;
    long double right_border = 0.6L;
    long double step_x = (right_border - left_border) / (long double)partitions;
    long double machine_eps = get_machine_epsilon();

    printf("+--------------+------------------------+------------------------+------------+\n");
    printf("|      x       |     Taylor series      |     Exact Func(x)      | Iterations |\n");
    printf("+--------------+------------------------+------------------------+------------+\n");

    for (int i = 0; i <= partitions; i++) {
        long double current_x = left_border + (long double)i * step_x;
        int iterations = 0;
        long double taylor_val = calculate_taylor(current_x, machine_eps, coeff_k, &iterations);
        long double exact_val = Func(current_x);

        printf("| %12.6Lf | %22.16Lf | %22.16Lf | %10d |\n",
               current_x, taylor_val, exact_val, iterations);
    }

    printf("+--------------+------------------------+------------------------+------------+\n");
    return 0;
}
