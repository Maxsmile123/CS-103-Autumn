#pragma once

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int Task() {
    FILE* input = fopen("input.txt", "r");
    if (input == NULL) {
        return 1;
    }

    int size = 0;
    if (fscanf(input, "%d", &size) != 1 || size < 1) {
        fclose(input);
        return 1;
    }

    size_t width = (size_t)size;
    if (width > SIZE_MAX / sizeof(int32_t) / width) {
        fclose(input);
        return 1;
    }

    int32_t* matrix = (int32_t*)malloc(width * width * sizeof(*matrix));
    if (matrix == NULL) {
        fclose(input);
        return 1;
    }

    for (size_t index = 0; index < width * width; ++index) {
        if (fscanf(input, "%" SCNd32, &matrix[index]) != 1) {
            fclose(input);
            free(matrix);
            return 1;
        }
    }
    fclose(input);

    const char* separator = "";
    for (int offset = 0; offset < size; ++offset) {
        int diagonal = size - 1 - offset;
        for (int row = diagonal; row >= 0; --row) {
            printf("%s%" PRId32, separator, matrix[(size_t)row * width + (size_t)(diagonal - row)]);
            separator = " ";
        }
        for (int row = offset + 1; row < size; ++row) {
            int col = size - (row - offset);
            printf(" %" PRId32, matrix[(size_t)row * width + (size_t)col]);
        }
    }
    putchar('\n');
    free(matrix);
    return 0;
}
