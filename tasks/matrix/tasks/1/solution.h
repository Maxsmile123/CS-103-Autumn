#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ** makeMatrix(int size);

int Task() {

    char inp[1024];
    int size = 0;
    scanf(" %[^\n]", inp);
    int c = 0;
    while (inp[c] != '\0') {
        if (inp[c] == ' ') {
            size += 1;
        }
        c++;
    }
    size += 1;

    int **matrix_1 = makeMatrix(size);
    int **matrix_2 = makeMatrix(size);
    int **matrix_3 = makeMatrix(size);

    char *ptr;

    ptr = strtok(inp, " ");
    for (int j = 0; j<size; ++j) {
        matrix_1[0][j] = atoi(ptr);
        ptr = strtok(NULL, " ");
    }

    for (int i = 1; i<size; ++i) {
        scanf(" %[^\n]", inp);
        ptr = strtok(inp, " ");
        for (int j = 0; j<size; ++j) {
            matrix_1[i][j] = atoi(ptr);
            ptr = strtok(NULL, " ");
        }
    }

    puts(" ");

    for (int i = 0; i<size; ++i) {
        for (int j = 0; j<size; ++j) {
            matrix_2[j][i] = matrix_1[i][j];
        }
    }

    int i_1 = 0, j_1 = 0, i_2 = 0, j_2 = 0, i_3 = 0, j_3 = 0;
    for (i_3 = 0; i_3<size; ++i_3) {
        for (j_3 = 0; j_3<size; ++j_3) {
            for (i_2 = 0; i_2<size; ++i_2) {
                matrix_3[i_3][j_3] += matrix_1[i_1][j_1]*matrix_2[i_2][j_2];
                j_1++;
            }
            j_1 = 0;
            j_2++;
        }
        i_1++;
        j_2 = 0;
    }

    for (int i = 0; i<size; ++i) {
        for (int j = 0; j<size; ++j) {
            printf("%d ", matrix_3[i][j]);
        }
        puts(" ");
    }

    return 0;
}

int ** makeMatrix(int size) {
    int **matrix = (int **)malloc(size*sizeof(int*));

    for (int j = 0; j < size; j++) {
        matrix[j] = (int*)malloc(size * sizeof(int));    
    }

    return matrix;
}
