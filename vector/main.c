#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Not enough arguments, run as: ./vector_test [size] [elements]\n");
        return 1;
    }

    int vector_size = atoi(argv[1]);
    if (argc < vector_size + 2) {
        printf("Not enough elements\n");
        return 1;
    } else if (argc > vector_size + 2) {
        printf("Too many elements\n");
        return 1;
    }

    Vector *v = make_vector(vector_size);
    for (int i=0; i<vector_size; i++) {
        push_back(v, atoi(argv[i + 2]));
    }
    print(v);
    printf("Final capacity: %d\n", get_capacity(v));
    destroy_vector(v);
    return 0;
}
