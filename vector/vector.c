#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

struct Vector {
    size_t size;
    size_t capacity;
    int *data;
};

Vector* make_vector(int size_) {
    Vector *v = (Vector *) malloc(sizeof(Vector));
    v->size = 0;
    v->capacity = 4;
    v->data = (int *) malloc(sizeof(int) * size_);
    return v;
}

int get_size(Vector *v) {
    return v->size;
}

int get_capacity(Vector *v) {
    return v->capacity;
}

void push_back(Vector *v, int x) {
    int size = v->size;
    if (size == v->capacity) {
        v->capacity *= 2;
        v->data = (int *) realloc(v->data, sizeof(int) * v->capacity);
    }
    v->data[v->size++] = x;
}

void pop_back(Vector *v) {
    if (v->size > 0)
        v->size--;
}

void print(Vector *v) {
    for (int i=0; i<v->size; i++) {
        printf("%d ", v->data[i]);
    }
    printf("\n");
}

void destroy_vector(Vector *v) {
    free(v->data);
    free(v);
}
