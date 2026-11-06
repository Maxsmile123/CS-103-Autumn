#include "stdlib.h"
#include "stdio.h"
#include "math.h"

//NOTE: path to file should be an argument while starting .exe program
int main(int argc, char *argv[]) {
    int input[128], curr_number = 0, size_of_vector = 1, added = 0, rank;
    char c;
    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    int **mat = (int **) malloc(sizeof(int *));
    int *v = (int *) malloc(sizeof(int));
    if (mat == NULL || v == NULL) {
        printf("Memory malloc failed\n");
        fclose(f);
        return 1;
    }
    while ((c = fgetc(f)) != EOF) {
        if (c >= '0' && c <= '9') {
            curr_number = curr_number * 10 + (c - '0');
        } else {
            if (size_of_vector == added) {
                if (size_of_vector == 1) {
                    size_of_vector = 2;
                } else {
                    size_of_vector *= size_of_vector;
                }
                v = (int *) realloc(v, sizeof(int) * size_of_vector);
                if (v == NULL) {
                    printf("Memory realloc failed\n");
                    fclose(f);
                    return 1;
                }
            }
            v[added] = curr_number;
            added++;
            curr_number = 0;
        }
    }
    if (size_of_vector == added) {
        if (size_of_vector == 1) {
            size_of_vector = 2;
        } else {
            size_of_vector *= size_of_vector;
        }
        v = (int *) realloc(v, sizeof(int) * size_of_vector);
        if (v == NULL) {
            printf("Memory realloc failed\n");
            fclose(f);
            return 1;
        }
    }
    v[added] = curr_number;
    added++;
    curr_number = 0;

    rank = sqrt(added);
    printf("Rank: %d, added: %d\n", rank, added);
    int mx = v[0], mn = v[0], num_of_mn_cols = 0;
    for (int i = 0; i < rank; i++) {
        mat[i] = (int *) malloc(sizeof(int) * rank);
        if (mat[i] == NULL) {
            printf("Memory malloc failed\n");
            return 1;
        }
        for (int j = 0; j < rank; j++) {
            mat[i][j] = v[i * rank + j];
            if (mat[i][j] > mx) {
                mx = mat[i][j];
            }
            if (mat[i][j] < mn) {
                mn = mat[i][j];
                num_of_mn_cols = 1;
            } else if (mat[i][j] == mn) {
                ++num_of_mn_cols;
            }
        }
    }
    for (int i = 0; i < rank; i++) {
        for (int j = 0; j < rank; j++) {
            if (mat[i][j] == mx) {
                mat[i][j] = num_of_mn_cols;
            }
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
