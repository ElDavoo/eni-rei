#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "cml.h"

// Common Matrix Library



matrix *matrix_new(int rows, int cols) {
    matrix *m = malloc(sizeof(matrix));
    m->rows = rows;
    m->cols = cols;
    m->data = malloc(sizeof(double) * rows * cols);
    matrix_fill(m, 0);
    return m;
}

void matrix_fill(matrix *m, int value) {
    for (int i = 0; i < m->rows * m->cols; i++) {
        m->data[i] = value;
    }
}

matrix *matrix_new_ask_dimensions() {
    printf("Enter the number of rows: ");
    int rows = read_int();
    printf("Enter the number of columns: ");
    int cols = read_int();
    return matrix_new(rows, cols);
}

void matrix_ask_data(matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("Enter the value of element (%d, %d): ", i, j);
            m->data[i * m->cols + j] = read_int();
        }
    }
}

void matrix_print(matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d\t", m->data[i * m->cols + j]);
        }
        printf("\n");
    }
}

char *read_line() {
    char *line = malloc(sizeof(char) * 100);
    fgets(line, 100, stdin);
    return line;
}

// Read int using strtol
int read_int() {
    char *input = read_line();
    int result = strtol(input, NULL, 10);
    free(input);
    return result;
}

