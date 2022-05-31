#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cml.h"

void ex6(const matrix *m);

int main() {
    srand(time(NULL));

    matrix *m = matrix_new(rand() % 5 + 2,rand() % 5 + 2);
    matrix_fill_random(m);
    matrix_print(m);

    ex6(m);

    matrix_free(m);


}

void ex6(const matrix *m) {
    printf("\nExercise 6\n");
    // Print the sum of the elements for each matrix column
    for (int i = 0; i < m->cols; i++) {
        int sum = matrix_col_sum(m, i);
        printf("Sum of column %d: %d\n", i, sum);
    }
    printf("\n");
    // Print the maximum element for each column and its position
    for (int i = 0; i < m->cols; i++) {
        cell c = matrix_max_col_pos(m, i);
        printf("Max element of column %d: %d at position %d\n", i, c.value, c.pos);
    }
    printf("\n");
    // Print the minimum element for each column and its position
    for (int i = 0; i < m->cols; i++) {
        cell c = matrix_min_col_pos(m, i);
        printf("Min element of column %d: %d at position %d\n", i, c.value, c.pos);
    }
    printf("\n");
    // Print the maximum element for each row and its position
    for (int i = 0; i < m->rows; i++) {
        cell c = matrix_max_row_pos(m, i);
        printf("Max element of row %d: %d at position %d\n", i, c.value, c.pos);
        // Now we get the row in which the max element is
        int row = c.pos / m->cols;
        printf("The row in which the max element is: %d\n", row);
        // Now we get the minimum of that column
        cell c2 = matrix_min_col_pos(m, c.pos % m->cols);
        printf("The min element of the row: %d at position %d\n", c2.value, c2.pos);
        printf("\n");
    }
}
