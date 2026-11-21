#pragma once

#include <float.h>
#include <stdint.h>
#include <stdio.h>

long double Func(long double x) {
	return (3 * x - 5) / (x * x - 4 * x + 3);
}

int Task() {
	const int n = 10;
	const int k = 10;
	long double eps = 1.0L;

	while (1.0L + eps / 2 > 1.0L) {
		eps /= 2;
	}

	printf("x     Ряд Тейлора            Значение функции       Число итераций\n");

	for (int i = 0; i <= n; i++) {
		long double x = 0.5L * i / n;
		long double power = 1.0L;
		long double fraction = 2.0L / 3;
		long double term = (1 + fraction) * power;
		long double sum = 0.0L;
		int count = 0;

		while (count < 100 && 2 * term > eps * k) {
			sum -= term;
			count++;
			power *= x;
			fraction /= 3;
			term = (1 + fraction) * power;
		}

		printf("%.2Lf  %.18Lf  %.18Lf  %d\n", x, sum, Func(x), count);
	}

	return 0;
}
