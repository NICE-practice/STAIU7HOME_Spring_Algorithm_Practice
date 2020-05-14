#ifndef NICE_TEEN48_H
#define NICE_TEEN48_H

typedef struct
{
    int rows;
    int columns;
    int **matrix;
} matrix_t;

int max_row(int a[6][6], int i, int n);
int max_col(int a[6][6], int j, int n);
char teen48game(matrix_t matrix);

#endif // NICE_TEEN48_H
