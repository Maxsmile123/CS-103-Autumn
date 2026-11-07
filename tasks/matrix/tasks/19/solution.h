#pragma once

#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t **Matrix;

// Освобождаем строки матрицы, затем массив указателей
static void FreeMatrix(Matrix matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }

    free(matrix);
}

int Task(void)
{
    // 1. Открываем входной файл
    FILE *file = fopen("input.txt", "r");

    if (file == NULL)
    {
        return 1;
    }

    // 2. Читаем размер квадратной матрицы
    int size;

    if (fscanf(file, "%d", &size) != 1 ||
        size < 1 || size > 8)
    {
        fclose(file);
        return 1;
    }

    // 3. Выделяем память для указателей на строки
    Matrix matrix = (Matrix)malloc(size * sizeof(*matrix));

    if (matrix == NULL)
    {
        fclose(file);
        return 1;
    }

    // 4. Выделяем память для каждой строки
    for (int i = 0; i < size; i++)
    {
        matrix[i] = (int32_t *)malloc(
            size * sizeof(*matrix[i]));

        if (matrix[i] == NULL)
        {
            FreeMatrix(matrix, i);
            fclose(file);
            return 1;
        }
    }

    // 5. Читаем элементы матрицы из файла
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (fscanf(file, "%" SCNd32,
                       &matrix[i][j]) != 1)
            {
                FreeMatrix(matrix, size);
                fclose(file);
                return 1;
            }
        }
    }

    fclose(file);

    // 6. Заменяем диагональ максимумами строк
    for (int i = 0; i < size; i++)
    {
        int32_t row_max = matrix[i][0];

        for (int j = 1; j < size; j++)
        {
            if (matrix[i][j] > row_max)
            {
                row_max = matrix[i][j];
            }
        }

        matrix[i][i] = row_max;
    }

    // 7. Выводим размеры и изменённую матрицу
    printf("%d %d\n", size, size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%" PRId32 " ", matrix[i][j]);
        }

        printf("\n");
    }

    // 8. Освобождаем память
    FreeMatrix(matrix, size);

    return 0;
}
