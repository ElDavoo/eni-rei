#ifndef ENI_REI_CML_H
#define ENI_REI_CML_H

char *read_line();
int read_int();

typedef struct {
    int rows;
    int cols;
    int *data;
} matrix;

matrix *matrix_new(int rows, int cols);
void matrix_fill(matrix *m, int value);
matrix *matrix_new_ask_dimensions();
void matrix_ask_data(matrix *m);
void matrix_print(matrix *m);

#endif //ENI_REI_CML_H
