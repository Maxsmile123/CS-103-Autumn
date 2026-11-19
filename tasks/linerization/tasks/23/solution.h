#pragma once

#include <stdint.h>
#include <stdio.h>

typedef int32_t** Matrix;

int Task() 
    {
    int n;

    scanf("%d", &n);

    if (n < 1 || n > 7)
    {
        return 0;
    }

    int matrix[n][n];
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    while (top <= bottom && left <= right)
    {
        for (int j = left; j <= right; j++)
        {
            printf("%d ", matrix[top][j]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            printf("%d ", matrix[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
            {
                printf("%d ", matrix[bottom][j]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }
    printf("\n");
        
    return 0;
}
