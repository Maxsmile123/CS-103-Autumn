#pragma once

#include <stdint.h>
#include <stdio.h>

typedef int32_t** Matrix;

int Task() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        return 1;
    }

    int n;
    if (fscanf(file, "%d", &n) != 1 || n<1 ||n>8) {
        fclose(file);
        return 1;
    }

    int  matrix[8][8];
	for (int i =0; i<n;i++){
	    for(int j = 0; j<n; j++){
               if (fscanf(file, "%d", &matrix[i][j])!=1){
                    fclose(file);
                    return 1;
                }
        }
	}
    fclose(file);

    for (int i =0; i<n; i++){
        int j = n-1-i;
        int *ptr = &matrix[i][j];
        int sum = 0;
        for (int k =0; k<n; k++){
            for(int f = 0; f<n; f++){
                if(i-j == k-f){
                    sum+= matrix[k][f];
                }
            }
        }
        *ptr = sum;
    }

    printf("%d %d\n", n, n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            printf("%d", matrix[i][j]);
            if (j<n-1){
                printf(" ");
            }
        }
        printf("\n");

    }

    return 0;
}
