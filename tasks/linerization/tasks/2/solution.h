#pragma once

#include "stdlib.h"
#include "stdio.h"
#include "math.h"

int main(int argc, char *argv[]) {
    int input[64];
    int acc = 0;
    int curr_number = 0;
    char c;
    while ((c = getchar()) != '\n') {
        if (c >= '0' && c <= '9') {
            curr_number = curr_number * 10 + (c - '0');
        } else {
            input[acc++] = curr_number;
            curr_number = 0;
        }
    }
    input[acc++] = curr_number;
    int powed = (int) sqrt(acc);
    int **v = (int **) malloc(powed * sizeof(int *));
    if (v == NULL) {
        return 1;
    }
    for (int i = 0; i < powed; ++i) {
        int *curr_row = malloc(sizeof(int) * powed);
        for (int j = 0; j < powed; ++j) {
            *(curr_row + j) = input[i * powed + j];
        }
        v[i] = curr_row;
    }
    int **v_print = (int **) malloc(powed * sizeof(int *));
    for (int i = 0; i < powed; ++i) {
        v_print[i] = malloc(sizeof(int) * powed);
    }
    int idx_to_add = 0;
    for (int j = powed - 1; j >= 0; --j) {
        int copy_i = 0, copy_j = j;
        while ((powed - 1) - j >= copy_i) {
            v_print[copy_i][copy_j] = v[idx_to_add / powed][idx_to_add % powed];
            ++copy_i;
            ++copy_j;
            ++idx_to_add;
        }
    }
    for (int i = 1; i < powed; ++i) {
        int copy_i = i, copy_j = 0;
        while (copy_j <= (powed - 1) - i) {
            v_print[copy_i][copy_j] = v[idx_to_add / powed][idx_to_add % powed];
            ++copy_i;
            ++copy_j;
            ++idx_to_add;
        }
    }
    for (int i = 0; i < powed; ++i) {
        for (int j = 0; j < powed; ++j) {
            printf("%d ", v_print[i][j]);
        }
        printf("\n");
    }
    return 0;
}
