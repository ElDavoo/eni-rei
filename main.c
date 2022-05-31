#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cml.h"

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

// Given a matrix a[n][m] and two integers k and g
// such that k<g<n and k<m.
// Find the sum of the rows of elements between k and g
// Find the average of the rows of elements between k and g
// Find the average of the column k
void ex7(const matrix *m) {
    // FIXME unclear: if k<g<n, than k and g must be
    // column and row indexes.
    // however, it's later written that
    // we must find elements between k and g,
    // assuming they are elements index.
    // So are they row/column indexes or element indexes?
    printf("\nExercise 7\n");
    int k = (rand() % (m->rows - 1)) + 1;
    int g = (rand() % (m->rows - k - 1)) + k + 1;
    printf("k: %d, g: %d\n", k, g);
    // FIXME unclear: sum of each row or some of all selected rows?
    for (int i = k; i <= g; i++) {
        int sum = matrix_row_sum(m, i);
        printf("Sum of row %d: %d\n", i, sum);
        int avg = sum / m->cols;
        printf("Average of row %d: %d\n", i, avg);
    }
    int avg = matrix_avg_col(m, k);
    printf("Average of column %d: %d\n", k, avg);

    printf("\n");

}

int main() {
    srand(time(NULL));

    matrix *m = matrix_new(rand() % 5 + 2,rand() % 5 + 2);
    matrix_fill_random(m);
    matrix_print(m);

    ex6(m);
    ex7(m);

    matrix_free(m);


}