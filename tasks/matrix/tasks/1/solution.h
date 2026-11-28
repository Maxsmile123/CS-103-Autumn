#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
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
    int **matrix = (int **)malloc(size*sizeof(int*));

    for (int j = 0; j < size; j++) {
        matrix[j] = (int*)malloc(size * sizeof(int));    
    }

    char *ptr;

    ptr = strtok(inp, " ");
    for (int j = 0; j<size; ++j) {
        matrix[0][j] = atoi(ptr);
        ptr = strtok(NULL, " ");
    }

    for (int i = 1; i<size; ++i) {
        scanf(" %[^\n]", inp);
        ptr = strtok(inp, " ");
        for (int j = 0; j<size; ++j) {
            matrix[i][j] = atoi(ptr);
            ptr = strtok(NULL, " ");
        }
    }

    puts(" ");

    int j = 0;
    for (int i = size-1; i>=0; --i) {
        int i_n = i;
        int j_n = j;
        while (i_n<=size-1) {
            printf("%d ", matrix[i_n][j_n]);
            ++i_n;
            ++j_n;
        }
    } 

    int i = 0;
    for (int j = 1; j<=size-1; ++j) {
        int i_n = i;
        int j_n = j;
        while (j_n<=size-1) {
            printf("%d ", matrix[i_n][j_n]);
            ++i_n;
            ++j_n;
        }
    } 

    return 0;
}