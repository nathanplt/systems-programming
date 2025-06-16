#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector Vector;

Vector* make_vector(int size_);
int get_size(Vector *v);
int get_capacity(Vector *v);
void push_back(Vector *v, int x);
void pop_back(Vector *v);
void print(Vector *v);
void destroy_vector(Vector *v);

#endif
