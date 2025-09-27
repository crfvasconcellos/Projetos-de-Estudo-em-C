
#include "float_vector.h"
#include <stdlib.h>
#include <stdio.h>


struct float_vector {
    int capacity; // num máximo de elementos
    int size; // qtde de elementos armazenados atualmente
    float *data;  // vetor de floats
};


/**
 * @brief Cria (aloca) um vetor de floats com uma dada capacidade.
 * 
 * @param capacity Capacidade do vetor. 
 * @return FloatVector* Um vetor de floats alocado/criado.
 */
FloatVector *create(int capacity) {
    FloatVector *vec = (FloatVector*) calloc(1, sizeof(FloatVector));
    vec->size = 0;
    vec->capacity = capacity;
    vec->data = (float*) calloc(capacity, sizeof(float));
    
    return vec;
}


void destroy(FloatVector **vec_ref) {
    FloatVector *vec = *vec_ref;

    free(vec->data);
    free(vec);
    *vec_ref = NULL;
}


int size(const FloatVector * vec){
    return vec->size;
}

int capacity(const FloatVector * vec){
    return vec->capacity;
}

float at(const FloatVector *vec, int index){
    if (index < 0 || index >= vec->size) {
        fprintf(stderr, "ERROR in 'at'\n");
        fprintf(stderr, "Index [%d] is out of bounds: [0, %d]\n", index, vec->size - 1);
        exit(EXIT_FAILURE); // termina o programa com um código de erro
        // EXIT_FAILURE ==> stdlib.h
    }

    return vec->data[index];
}

float get(const FloatVector *vec, int index) {
    return vec->data[index];
}



void append(FloatVector *vec, float val) {
    if (vec->size == vec->capacity) {
        fprintf(stderr, "ERROR in 'append'\n");
        fprintf(stderr , "Vector is full'\n");
        exit(EXIT_FAILURE);
    }

    vec->data[vec->size] = val;
    vec->size++;
}


void print(const FloatVector *vec) {
    puts("----------------------------");
    printf("Size: %d\n", vec->size);
    printf("Capacity: %d\n", vec->capacity);
    puts("---");

    for (int i = 0; i < vec->size; i++) {
        printf("[%d] = %f\n", i, vec->data[i]);
    }
    puts("----------------------------\n");
}
