#ifndef ENI_REI_CML_H
#define ENI_REI_CML_H

char *read_line();
int read_int();

typedef struct {
    int rows;
    int cols;
    int *data;
} matrix;

// Array with length information
typedef struct {
    int length;
    int *data;
} array;

// Cell, e.g. value + position
typedef struct {
    int value;
    int pos;
} cell;

matrix *matrix_new(int rows, int cols);
void matrix_fill(matrix *m, int value);
void matrix_fill_random(matrix *m);
void matrix_ask_data(matrix *m);
void matrix_print(matrix *m);
void matrix_print_row(const matrix *m, int row);
void matrix_print_col(const matrix *m, int col);

void matrix_free(matrix *m);
int matrix_product_antidiagonal(matrix *m);
int matrix_row_sum(const matrix *m, int row);
int matrix_col_sum(const matrix *m, int col);
int matrix_avg_row(matrix *m, int row);
int matrix_avg_col(matrix *m, int col);
int matrix_product_diagonal(matrix *m);
int matrix_product_col(const matrix *m, int col);
int matrix_sum_diagonal(matrix *m);
int matrix_sum_antidiagonal(matrix *m);

int matrix_max_row(matrix *m, int row);
int matrix_max_col(matrix *m, int col);
int matrix_min_row(matrix *m, int row);
int matrix_min_col(matrix *m, int col);
int matrix_product_row(const matrix *m, int row);
int matrix_product_col(const matrix *m, int col);
cell matrix_max_row_pos(const matrix *m, int row);
cell matrix_max_col_pos(const matrix *m, int col);
cell matrix_min_row_pos(const matrix *m, int row);
cell matrix_min_col_pos(const matrix *m, int col);
cell matrix_product_row_pos(const matrix *m, int row);
cell matrix_product_col_pos(const matrix *m, int col);



matrix *matrix_new_ask_dimensions();

#endif //ENI_REI_CML_H
