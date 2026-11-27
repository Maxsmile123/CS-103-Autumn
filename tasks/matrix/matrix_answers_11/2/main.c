#include <stdio.h>
#include <stdlib.h>

int change_array(double** matrix, size_t size, size_t step){
    int top = 0;
    int bottom = size - 1;
    int left = 0;
    int right = size - 1;
    int i, j;
    int k = 0;
    size_t total = size*size;

    double* new_order = malloc(size*size*sizeof(double));
    while (top <= bottom && left <= right){
        for (j = left; j <= right; j++){
            new_order[k++] = matrix[top][j];
        }
        top++;

        for (i = top; i <= bottom; i++){
            new_order[k++] = matrix[i][right];
        }
        right--;

        if (top <= bottom){
            for (j = right; j >= left; j--){
                new_order[k++] = matrix[bottom][j];
            }
            bottom--;
        }

        if (left <= right){
            for (i = bottom; i >= top; i--){
                new_order[k++] = matrix[i][left];
            }
            left++;
        }
    }

    top = 0;
    bottom = size - 1;
    left = 0;
    right = size - 1;
    k = 0;
    step = step % total;

    while (top <= bottom && left <= right){
        for (j = left; j <= right; j++){
            matrix[top][j] = new_order[(k + total - step)%total];
            k++;
        }
        top++;
        for (i = top; i <= bottom; i++){
            matrix[i][right] = new_order[(k + total - step)%total];
            k++;
        }
        right--;
        if (top <= bottom){
            for (j = right; j >= left; j--){
                matrix[bottom][j] = new_order[(k + total - step)%total];
                k++;
            }
        bottom--;
        }  
        if (left <= right){
            for (i = bottom; i >= top; i--){
                matrix[i][left] = new_order[(k + total - step)%total];
                k++;
            }
        left++;
        }
    }

    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            printf("%8.2lf", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int main(void){
    size_t size;
    int i, j;
    size_t step;
    
    printf("Enter size of matrix: ");
    scanf_s("%zu", &size);

    double** matrix = malloc(size*sizeof(double*));
    if (matrix == NULL){
        printf("Memmory error");
        return 1;
    }
    for(i = 0; i < size; i++){
        matrix[i] = malloc(size*sizeof(double));
        if (matrix[i] == NULL){
            printf("Memmory error");
            return 1;
        }
    }

    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            printf("Enter matirx element [%d][%d]: \n", i+1, j+1);
            scanf_s("%lf", &matrix[i][j]);
        }
    }

    printf("Enter step: ");
    scanf_s("%zu", &step);
    
    change_array(matrix, size, step);

    return 0;
}