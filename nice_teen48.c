#include <stdio.h>
typedef struct
{
    int rows;
    int columns;
    int **matrix;
} matrix_t;

void trasform(int **a, int *buf, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = buf + n * i;
    }
}

void print(int **m)
{
    for (int i = 0; i < 4; i ++)
    {
        for (int j = 0; j < 4; j++)
            printf("%d", m[i][j]);
        printf("\n");
    }
}

char teen48game(matrix_t matrix)
{
    matrix_t matrix_u, matrix_d, matrix_l, matrix_r;

    matrix_d = matrix_l = matrix_r = matrix_u = matrix;
    int score_d = 0, score_l = 0, score_r = 0, score_u = 0;
    char flag_d = 0, flag_l = 0, flag_r = 0, flag_u = 0;

    // turn
    for (int i = matrix.rows - 1; i > 0; i--)
    {
        for (int j = 0; j < matrix.rows; j++)
        {
            if (matrix_d.matrix[i][j] == 0)
            {
                int buf = matrix_d.matrix[i][j];
                matrix_d.matrix[i][j] = matrix_d.matrix[i - 1][j];
                matrix_d.matrix[i - 1][j] = buf;
                flag_d = 1;
            }
        }
    }
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.rows - 1; j++)
        {
            if (matrix_l.matrix[i][j] == 0)
            {
                int buf = matrix_l.matrix[i][j];
                matrix_l.matrix[i][j] = matrix_l.matrix[i][j + 1];
                matrix_l.matrix[i][j + 1] = buf;
                flag_l = 1;
            }
        }
    }
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = matrix.rows; j > 0; j--)
        {
            if (matrix_r.matrix[i][j] == 0)
            {
                int buf = matrix_r.matrix[i][j];
                matrix_r.matrix[i][j] = matrix_r.matrix[i][j - 1];
                matrix_r.matrix[i][j - 1] = buf;
                flag_r = 1;
            }
        }
    }
    for (int i = 0; i < matrix.rows - 1; i++)
    {
        for (int j = 0; j < matrix.rows; j++)
        {
            if (matrix_u.matrix[i][j] == 0)
            {
                int buf = matrix_u.matrix[i][j];
                matrix_u.matrix[i][j] = matrix_u.matrix[i + 1][j];
                matrix_u.matrix[i + 1][j] = buf;
                flag_u = 1;
            }
        }
    }

    print(matrix_d.matrix);
    printf("\n%d\n", flag_d);
    print(matrix_l.matrix);
    printf("\n%d\n", flag_l);
    print(matrix_r.matrix);
    printf("\n%d\n", flag_r);
    print(matrix_u.matrix);
    printf("\n%d\n", flag_u);


    // score
    for (int i = matrix.rows - 1; i > 0; i--)
    {
        for (int j = 0; j < matrix.rows; j++)
        {
            if (matrix_d.matrix[i][j] == matrix_d.matrix[i - 1][j])
            {
                matrix_d.matrix[i][j] += matrix_d.matrix[i - 1][j];
                matrix_d.matrix[i - 1][j] = 0;
                score_d += matrix_d.matrix[i][j];
            }
        }
    }
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.rows - 1; j++)
        {
            if (matrix_l.matrix[i][j] == 0)
            {
                matrix_l.matrix[i][j] += matrix_l.matrix[i][j + 1];
                matrix_l.matrix[i][j + 1] = 0;
                score_l += matrix_l.matrix[i][j];
            }
        }
    }
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = matrix.rows; j > 0; j--)
        {
            if (matrix_r.matrix[i][j] == 0)
            {
                matrix_r.matrix[i][j] += matrix_r.matrix[i][j - 1];
                matrix_r.matrix[i][j - 1] = 0;
                score_r += matrix_r.matrix[i][j];
            }
        }
    }
    for (int i = 0; i < matrix.rows - 1; i++)
    {
        for (int j = 0; j < matrix.rows; j++)
        {
            if (matrix_u.matrix[i][j] == 0)
            {
                matrix_u.matrix[i][j] = matrix_u.matrix[i + 1][j];
                matrix_u.matrix[i + 1][j] = 0;
                score_u += matrix_u.matrix[i][j];
            }
        }
    }

    print(matrix_d.matrix);
    printf("\n%d\n", score_d);
    print(matrix_l.matrix);
    printf("\n%d\n", score_l);
    print(matrix_r.matrix);
    printf("\n%d\n", score_r);
    print(matrix_u.matrix);
    printf("\n%d\n", score_u);


    return 0;
}

int main()
{
    matrix_t matrix;
    matrix.rows = 4;
    matrix.columns = 4;

    matrix.matrix[0][0] = 0;
    /*matrix.matrix[0][1] = matrix.matrix[0][2] = matrix.matrix[0][3] = 0;
    matrix.matrix[1][0] = matrix.matrix[1][1] = matrix.matrix[1][2] = 0;
    matrix.matrix[1][3] = 4;
    matrix.matrix[2][0] = matrix.matrix[2][2] = matrix.matrix[2][3] = 0;
    matrix.matrix[2][1] = 2;
    matrix.matrix[3][0] =matrix.matrix [3][1] = matrix.matrix[3][2] = matrix.matrix[3][3] = 0;*/

    teen48game(matrix);

    return 0;
}
