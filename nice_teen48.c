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

int max_row(int a[6][6], int i, int n)
{
    int max = 0, max_j = 0;
    for (int j = 0; j < n; j++)
        if (a[i][j] > max)
        {
            max_j = j;
            max = a[i][j];
        }
    for (int j = 1; j < max_j; j++)
        if (a[i][j] != 0)
            max = 0;

    return max;
}
int max_col(int a[6][6], int j, int n)
{
    int max = 0, max_i = 0;;
    for (int i = 0; i < n; i++)
        if (a[i][j] > max)
        {
            max_i = i;
            max = a[i][j];
        }
    for (int i = max_i; i > 0; i--)
        if (a[i][j] != 0)
            max = 0;

    return max;
}
char teen48game(matrix_t matrix)
{
    char swipe = 0;
    int d[6][6], l[6][6], r[6][6], u[6][6];
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.rows; j++)
        {
            d[i][j] = matrix.matrix[i][j];
            l[i][j] = matrix.matrix[i][j];
            r[i][j] = matrix.matrix[i][j];
            u[i][j] = matrix.matrix[i][j];
        }
    }

    int score_d = 0, score_l = 0, score_r = 0, score_u = 0;
    char flag_d = 0, flag_l = 0, flag_r = 0, flag_u = 0;

    if (d[matrix.rows - 1][0] == 0)
    {
        int max_c = max_col(d, 0, matrix.rows);
        int max_r = max_row(d, matrix.rows - 1, matrix.rows);
        if ((max_c != 0) && (max_c >= max_r))
        {
            swipe = 'd';
            return swipe;
        }
        else if ((max_r != 0) && (max_r > max_c))
        {
            swipe = 'l';
            return swipe;
        }
    }
    // turn
    for (int k = 0; k < matrix.rows; k++)
    {
        for (int i = 0; i < matrix.rows - 1; i++)
        {
            for (int j = 0; j < matrix.rows; j++)
            {
                if (d[i][j] != 0 && d[i + 1][j] == 0)
                {
                    int buf = d[i][j];
                    d[i][j] = d[i + 1][j];
                    d[i + 1][j] = buf;
                    flag_d = 1;
                }
            }
        }
        for (int i = 0; i < matrix.rows; i++)
        {
            for (int j = matrix.rows - 1; j > 0; j--)
            {
                if (l[i][j] != 0 && l[i][j - 1] == 0)
                {
                    int buf = l[i][j];
                    l[i][j] = l[i][j - 1];
                    l[i][j - 1] = buf;
                    flag_l = 1;
                }
            }
        }
        for (int i = 0; i < matrix.rows; i++)
        {
            for (int j = 0; j < matrix.rows - 1; j++)
            {
                if (r[i][j] != 0 && r[i][j + 1] == 0)
                {
                    int buf = r[i][j];
                    r[i][j] = r[i][j + 1];
                    r[i][j + 1] = buf;
                    flag_r = 1;
                }
            }
        }
        for (int i = matrix.rows - 1; i > 0 ; i--)
        {
            for (int j = 0; j < matrix.rows; j++)
            {
                if (u[i][j] != 0 && u[i - 1][j] == 0)
                {
                    int buf = u[i][j];
                    u[i][j] = u[i - 1][j];
                    u[i - 1][j] = buf;
                    flag_u = 1;
                }
            }
        }
    }

    // score
    for (int i = matrix.rows - 1; i > 0; i--)
    {
        for (int j = 0; j < matrix.rows; j++)
        {
            if (d[i][j] == d[i - 1][j])
            {
                d[i][j] += d[i - 1][j];
                d[i - 1][j] = 0;
                score_d += d[i][j];
            }
        }
    }
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.rows - 1; j++)
        {
            if (l[i][j] == l[i][j + 1])
            {
                l[i][j] += l[i][j + 1];
                l[i][j + 1] = 0;
                score_l += l[i][j];
            }
        }
    }
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = matrix.rows; j > 0; j--)
        {
            if (r[i][j] == r[i][j - 1])
            {
                r[i][j] += r[i][j - 1];
                r[i][j - 1] = 0;
                score_r += r[i][j];
            }
        }
    }
    for (int i = 0; i < matrix.rows - 1; i++)
    {
        for (int j = 0; j < matrix.rows; j++)
        {
            if (u[i][j] == u[i + 1][j])
            {
                u[i][j] += u[i + 1][j];
                u[i + 1][j] = 0;
                score_u += u[i][j];
            }
        }
    }

    if (((flag_d == 1) && (score_d >= score_l)) || \
            ((flag_d == 0) && (score_d >= score_l) && (score_d != 0)))
        swipe = 'd';
    else if (((flag_d == 1) && (flag_l == 1) && (score_l > score_d)) || \
        ((flag_d == 0) && (flag_l == 1) && (score_d == 0)) || \
             ((flag_l == 0) && (flag_r == 1) && (score_l != 0)) || \
             ((flag_l == flag_r) && (score_l == score_r)))
        swipe = 'l';
    else if ((flag_d == 0) && (flag_l == 0) && (flag_r == 1))
        swipe = 'r';
    else if ((flag_d == 0) && (flag_l == 0) && (flag_r == 0) && (flag_u == 1))
        swipe = 'u';

    return swipe;
}

int main()
{
    matrix_t matrix;
    matrix.rows = 4;
    matrix.columns = 4;

    int a[4][4] = {{0,0,0,0},
                   {8,4,2,16},
                   {16,8,4,2},
                   {32,16,8,4}};
    int *d[4];
    trasform(d, *a, 4);


    matrix.matrix = d;

    char p = teen48game(matrix);

    printf("SWIPE %c", p);
    return 0;
}


