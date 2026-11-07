#pragma once
#include <stdio.h>
#include <math.h>
#define MAX_SIZE 7

int Task() {
    int input_buffer[MAX_SIZE * MAX_SIZE];
    int count = 0;
    int val;

    while (count < MAX_SIZE * MAX_SIZE && scanf("%d", &val) == 1) {
        input_buffer[count++] = val;
    }

    if (count == 0) {
        return 0;
    }

    int N = (int)sqrt(count);
    if (N * N != count || N > MAX_SIZE) {
        return 1; 
    }

    int matrix[MAX_SIZE][MAX_SIZE];
    int idx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = input_buffer[idx++];
        }
    }

    for (int d = N - 1; d >= -(N - 1); d--) {
        int min_i = (0 > -d) ? 0 : -d;
        int max_i = ((N - 1) < (N - 1 - d)) ? (N - 1) : (N - 1 - d);
        int step = (N - 1) - d;

        if (step % 2 != 0) {
            for (int i = min_i; i <= max_i; i++) {
                printf("%d ", matrix[i][i + d]);
            }
        } else {
            for (int i = max_i; i >= min_i; i--) {
                printf("%d ", matrix[i][i + d]);
            }
        }
    }
    printf("\n");

    return 0;
}