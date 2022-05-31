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

void matrix_fill_random(matrix *m) {
    for (int i = 0; i < m->rows * m->cols; i++) {
        m->data[i] = rand() % 100;
    }
}



void matrix_print_row(const matrix *m, int row) {
    for (int i = 0; i < m->cols; i++) {
        printf("%d\t", m->data[row * m->cols + i]);
    }
    printf("\n");
}

void matrix_print_col(const matrix *m, int col) {
    for (int i = 0; i < m->rows; i++) {
        printf("%d\t", m->data[i * m->cols + col]);
    }
    printf("\n");
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

int matrix_row_sum(const matrix *m, int row) {
    int sum = 0;
    for (int i = 0; i < m->cols; i++) {
        sum += m->data[row * m->cols + i];
    }
    return sum;
}

int matrix_col_sum(const matrix *m, int col) {
    int sum = 0;
    for (int i = 0; i < m->rows; i++) {
        sum += m->data[i * m->cols + col];
    }
    return sum;
}

int matrix_max_row(matrix *m, int row) {
    int max = m->data[row * m->cols];
    for (int i = 0; i < m->cols; i++) {
        if (m->data[row * m->cols + i] > max) {
            max = m->data[row * m->cols + i];
        }
    }
    return max;
}


cell matrix_max_row_pos(const matrix *m, int row) {
    cell max = {m->data[row * m->cols], row * m->cols};
    for (int i = 0; i < m->cols; i++) {
        if (m->data[row * m->cols + i] > max.value) {
            max.value = m->data[row * m->cols + i];
            max.pos = row * m->cols + i;
        }
    }
    return max;
}

cell matrix_min_row_pos(const matrix *m, int row) {
    cell min = {m->data[row * m->cols], row * m->cols};
    for (int i = 0; i < m->cols; i++) {
        if (m->data[row * m->cols + i] < min.value) {
            min.value = m->data[row * m->cols + i];
            min.pos = row * m->cols + i;
        }
    }
    return min;
}

cell matrix_max_col_pos(const matrix *m, int col) {
    cell max = {m->data[col], col};
    for (int i = 0; i < m->rows; i++) {
        if (m->data[i * m->cols + col] > max.value) {
            max.value = m->data[i * m->cols + col];
            max.pos = i * m->cols + col;
        }
    }
    return max;
}

cell matrix_min_col_pos(const matrix *m, int col) {
    cell min = {m->data[col], col};
    for (int i = 0; i < m->rows; i++) {
        if (m->data[i * m->cols + col] < min.value) {
            min.value = m->data[i * m->cols + col];
            min.pos = i * m->cols + col;
        }
    }
    return min;
}

int matrix_max_col(matrix *m, int col) {
    int max = m->data[col];
    for (int i = 0; i < m->rows; i++) {
        if (m->data[i * m->cols + col] > max) {
            max = m->data[i * m->cols + col];
        }
    }
    return max;
}

int matrix_min_row(matrix *m, int row) {
    int min = m->data[row * m->cols];
    for (int i = 0; i < m->cols; i++) {
        if (m->data[row * m->cols + i] < min) {
            min = m->data[row * m->cols + i];
        }
    }
    return min;
}

int matrix_min_col(matrix *m, int col) {
    int min = m->data[col];
    for (int i = 0; i < m->rows; i++) {
        if (m->data[i * m->cols + col] < min) {
            min = m->data[i * m->cols + col];
        }
    }
    return min;
}

int matrix_max(matrix *m) {
    int max = m->data[0];
    for (int i = 0; i < m->rows * m->cols; i++) {
        if (m->data[i] > max) {
            max = m->data[i];
        }
    }
    return max;
}

int matrix_min(matrix *m) {
    int min = m->data[0];
    for (int i = 0; i < m->rows * m->cols; i++) {
        if (m->data[i] < min) {
            min = m->data[i];
        }
    }
    return min;
}

int matrix_sum(matrix *m) {
    int sum = 0;
    for (int i = 0; i < m->rows * m->cols; i++) {
        sum += m->data[i];
    }
    return sum;
}

int matrix_average(matrix *m) {
    return matrix_sum(m) / (m->rows * m->cols);
}

int matrix_product(matrix *m) {
    int product = 1;
    for (int i = 0; i < m->rows * m->cols; i++) {
        product *= m->data[i];
    }
    return product;
}

int matrix_product_row(const matrix *m, int row) {
    int product = 1;
    for (int i = 0; i < m->cols; i++) {
        product *= m->data[row * m->cols + i];
    }
    return product;
}

int matrix_product_col(const matrix *m, int col) {
    int product = 1;
    for (int i = 0; i < m->rows; i++) {
        product *= m->data[i * m->cols + col];
    }
    return product;
}

int matrix_product_diagonal(matrix *m) {
    int product = 1;
    for (int i = 0; i < m->rows; i++) {
        product *= m->data[i * m->cols + i];
    }
    return product;
}

int matrix_product_antidiagonal(matrix *m) {
    int product = 1;
    for (int i = 0; i < m->rows; i++) {
        product *= m->data[(m->rows - i - 1) * m->cols + i];
    }
    return product;
}

int matrix_avg_row(matrix *m, int row) {
    return matrix_row_sum(m, row) / m->cols;
}

int matrix_avg_col(matrix *m, int col) {
    return matrix_col_sum(m, col) / m->rows;
}

void array_fill(array *a, int value) {
    for (int i = 0; i < a->length; i++) {
        a->data[i] = value;
    }
}

void matrix_free(matrix *m) {
    free(m->data);
    free(m);
}

array *array_new(int length) {
    array *a = malloc(sizeof(array));
    a->length = length;
    a->data = malloc(sizeof(int) * length);
    array_fill(a, 0);
    return a;
}

array *matrix_get_row(matrix *m, int row) {
    array *a = array_new(m->cols);
    for (int i = 0; i < m->cols; i++) {
        a->data[i] = m->data[row * m->cols + i];
    }
    return a;
}

array *matrix_get_col(matrix *m, int col) {
    array *a = array_new(m->rows);
    for (int i = 0; i < m->rows; i++) {
        a->data[i] = m->data[i * m->cols + col];
    }
    return a;
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

