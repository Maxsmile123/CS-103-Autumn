#pragma once

#include <stdint.h>
#include <stdio.h>

typedef int32_t** Matrix;

int Task() {
    int n;

    if (scanf("%d", &n) != 1 || n < 1 || n > 8)
    {
        return 0;
    }

    int sm = 0;
    int min_i = 0;
    int matrix[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int mx = matrix[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] > mx)
            {
                mx = matrix[i][j];
                min_i = i;
            }
        }
    }

    for (int j = 0; j < n; j++)
    {
        sm += matrix[min_i][j];
    }

    printf("%d ", sm);
    
    return 0;
}
