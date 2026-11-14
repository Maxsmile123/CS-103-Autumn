#include <stdio.h>
#define SIZE 4
#define SIZEOFINDEXARRAY 16

void ArrayPrinter(const int Matrix[][SIZE], const int array_of_i[SIZEOFINDEXARRAY],
                  const int array_of_j[SIZEOFINDEXARRAY]);
int main() {
    const int Matrix[SIZE][SIZE] = {{1, 3, 4, 10}, {2, 5, 9, 11}, {6, 8, 12, 15}, {7, 13, 14, 16}};
    const int array_of_i[SIZEOFINDEXARRAY] = {0, 1, 0, 0, 1, 2, 3, 2, 1, 0, 1, 2, 3, 3, 2, 3};
    const int array_of_j[SIZEOFINDEXARRAY] = {0, 0, 1, 2, 1, 0, 0, 1, 2, 3, 3, 2, 1, 2, 3, 3};
    ArrayPrinter(Matrix, array_of_i, array_of_j);
    puts(" ");
    return 0;
}

void ArrayPrinter(const int Matrix[][SIZE], const int array_of_i[SIZEOFINDEXARRAY],
                  const int array_of_j[SIZEOFINDEXARRAY]) {
    static int i_index = 0;
    static int j_index = 0;
    for (i_index; i_index < SIZEOFINDEXARRAY; i_index++) {
        printf(" %d ", Matrix[array_of_i[i_index]][array_of_j[j_index]]);
        j_index++;
    }
}