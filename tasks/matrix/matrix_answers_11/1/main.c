#include <stdio.h>
#include <stdlib.h>

void change_array(double** matrix, int size){
    int i, j;
    double** old_array = malloc(size * sizeof(double*));

    for (i = 0; i < size; ++i) {
        old_array[i] = malloc(size * sizeof(double));
    }

    for (i = 0; i < size; ++i) {
        for (j = 0; j < size; ++j) {
            old_array[i][j] = matrix[i][j];
        }
    }

    short old_i = 0, old_j = 0;

    int max_s = 2 * (size - 1);
    while (max_s != -1) {
        if (max_s % 2 == 1){ 
                for (i = size - 1; i >= 0; --i) {
                    for (j = size - 1; j >= 0; --j) {
                        if (i+j == max_s) {
                            matrix[i][j] = old_array[old_i][old_j];
                            if (old_j == size - 1){
                                old_i++;
                                old_j = 0;
                            }
                            else{
                                old_j++;
                            }
                        }
                    }
                }
            }
        else{ 
                for (i = 0; i < size; ++i) {
                    for (j = 0; j < size; ++j) {
                        if (i+j == max_s) {
                            matrix[i][j] = old_array[old_i][old_j];
                            if (old_j == size - 1){
                                old_i++;
                                old_j = 0;
                            }
                            else{
                                old_j++;
                            }
                        }
                    }
                }
            }
        max_s--;
    }

    

    for (i = 0; i < size; ++i) {
        for (j = 0; j < size; ++j) {
            printf("%8.2lf", matrix[i][j]);
        }
        printf("\n");
    }
}

int main (void){
    int i, j;
    int n;

    printf("Enter size of matrix: ");
    scanf_s("%d", &n);

    double** matrix = malloc(n * sizeof(double *));
    if (matrix == NULL){
        printf("Memmory error");
        return 1;
    } 

    for (i = 0; i < n; ++i) {
        matrix[i] = malloc(n*sizeof(double));
        if (matrix[i] == NULL){
            printf("Memmory error");
            return 1;
        } 
    }

    for (i = 0; i < n; ++i){
        for (j = 0; j < n; ++j){
            printf("Enter [%d][%d] element of matrix: \n", i+1, j+1);
            scanf_s("%lf", &matrix[i][j]);
        }
    }
    
    change_array(matrix, n);

    return 0;
}