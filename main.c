#include <stdio.h>
#include "cml.h"

int main() {
    matrix *m = matrix_new(2,6);
    matrix_ask_data(m);
    matrix_print(m);
}
