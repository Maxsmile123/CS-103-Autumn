#pragma once

#include <errno.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const long double SEGMENT_START = 0.0L;
static const long double SEGMENT_END = 1.0L;
static const int MAX_ITERATIONS = 100;
static const long MIN_PARTITIONS = 1;
static const long MAX_PARTITIONS = 1000;
enum { INPUT_BUFFER_SIZE = 256 };

long double Func(long double x) {
    return sinl(x);
}

static long double CalculateTaylorSin(long double x, long double precision, int *iterations_used) {
    long double term = x;
    long double sum = term;
    const long double x_squared = x * x;
    int term_index = 0;

    while (fabsl(term) >= precision && term_index < MAX_ITERATIONS) {
        const int next_power = 2 * term_index + 3;
        term *= -x_squared / ((next_power - 1) * next_power);
        sum += term;
        ++term_index;
    }

    *iterations_used = term_index;
    return sum;
}

static bool ReadLine(char *buffer, int buffer_size) {
    if (fgets(buffer, buffer_size, stdin) == NULL) {
        return false;
    }
    if (strchr(buffer, '\n') == NULL && !feof(stdin)) {
        int symbol = getchar();
        while (symbol != '\n' && symbol != EOF) {
            symbol = getchar();
        }
        buffer[0] = '\0';
    }
    return true;
}

static bool IsOnlyWhitespace(const char *text) {
    while (*text == ' ' || *text == '\t' || *text == '\n' || *text == '\r') {
        ++text;
    }
    return *text == '\0';
}

static bool ReadLongInRange(const char *prompt, long min_value, long max_value, long *value) {
    char buffer[INPUT_BUFFER_SIZE];
    while (true) {
        printf("%s", prompt);
        if (!ReadLine(buffer, INPUT_BUFFER_SIZE)) {
            return false;
        }
        char *parse_end = NULL;
        errno = 0;
        const long parsed = strtol(buffer, &parse_end, 10);
        if (parse_end != buffer && IsOnlyWhitespace(parse_end) && errno == 0 &&
            parsed >= min_value && parsed <= max_value) {
            *value = parsed;
            return true;
        }
        printf("Нужно целое число от %ld до %ld.\n", min_value, max_value);
    }
}

static bool ReadPositiveLongDouble(const char *prompt, long double *value) {
    char buffer[INPUT_BUFFER_SIZE];
    while (true) {
        printf("%s", prompt);
        if (!ReadLine(buffer, INPUT_BUFFER_SIZE)) {
            return false;
        }
        char *parse_end = NULL;
        errno = 0;
        const long double parsed = strtold(buffer, &parse_end);
        if (parse_end != buffer && IsOnlyWhitespace(parse_end) && errno == 0 &&
            isfinite(parsed) && parsed > 0) {
            *value = parsed;
            return true;
        }
        printf("Нужно положительное конечное число.\n");
    }
}

static void PrintTableBorder(void) {
    printf("+-----+--------+----------------------+----------------------+------------+----------+\n");
}

int Task(void) {
    long partitions = 0;
    long double eps_multiplier = 0;

    if (!ReadLongInRange("Введите n (число разбиений отрезка): ", MIN_PARTITIONS, MAX_PARTITIONS, &partitions) ||
        !ReadPositiveLongDouble("Введите k (множитель точности EPS * k): ", &eps_multiplier)) {
        printf("\nВвод прерван.\n");
        return 1;
    }

    const long double precision = LDBL_EPSILON * eps_multiplier;
    const long double step = (SEGMENT_END - SEGMENT_START) / partitions;

    printf("Таблица значений ряда Тейлора и функции sin(x)\n");
    PrintTableBorder();
    printf("|  i  |   x    |    Ряд Тейлора       |       sin(x)         |  |разница|  | итераций |\n");
    PrintTableBorder();

    for (long i = 0; i <= partitions; ++i) {
        const long double x = SEGMENT_START + i * step;
        int iterations = 0;
        const long double approximate = CalculateTaylorSin(x, precision, &iterations);
        const long double exact = Func(x);

        printf("| %3ld | %6.3Lf | %20.17Lf | %20.17Lf | %10.3Le | %8d |\n",
               i, x, approximate, exact, fabsl(approximate - exact), iterations);
    }
    PrintTableBorder();
    return 0;
}
