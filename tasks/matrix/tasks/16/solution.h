#pragma once

#include "stdlib.h"
#include "stdio.h"
#include "math.h"

int main(int argc, char *argv[])
{
    int input[64];
    int acc = 0;
    int curr_number = 0;
    int has_digit = 0;
    char c;

    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
        {
            curr_number = curr_number * 10 + (c - '0');
            has_digit = 1;
        }
        else
        {
            if (has_digit)
            {
                input[acc++] = curr_number;
                curr_number = 0;
                has_digit = 0;
            }
        }
    }
    if (has_digit)
    {
        input[acc++] = curr_number;
    }

    int powed = (int)sqrt(acc);
    if (powed == 0)
    {
        return 0;
    }

    int **v = (int **)malloc(powed * sizeof(int *));
    if (v == NULL)
    {
        return 1;
    }
    for (int i = 0; i < powed; ++i)
    {
        int *curr_row = (int *)malloc(sizeof(int) * powed);
        if (curr_row == NULL)
        {
            return 1;
        }
        for (int j = 0; j < powed; ++j)
        {
            *(curr_row + j) = input[i * powed + j];
        }
        v[i] = curr_row;
    }

    for (int i = 0; i < powed; ++i)
    {
        int temp = v[i][i];
        v[i][i] = v[i][powed - 1 - i];
        v[i][powed - 1 - i] = temp;
    }

    for (int i = 0; i < powed; ++i)
    {
        for (int j = 0; j < powed; ++j)
        {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < powed; ++i)
    {
        free(v[i]);
    }
    free(v);

    return 0;
}
