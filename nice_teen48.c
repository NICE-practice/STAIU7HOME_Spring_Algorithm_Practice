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

void print(int m[4][4])
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
    int d[4][4], l[4][4], r[4][4], u[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            d[i][j] = matrix.matrix[i][j];
            l[i][j] = matrix.matrix[i][j];
            r[i][j] = matrix.matrix[i][j];
            u[i][j] = matrix.matrix[i][j];
        }
    }

    int score_d = 0, score_l = 0, score_r = 0, score_u = 0;
    char flag_d = 0, flag_l = 0, flag_r = 0, flag_u = 0;

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
    print(d);
    printf("%d\n\n", flag_d);
    print(l);
    printf("%d\n\n", flag_l);
    print(r);
    printf("%d\n\n", flag_r);
    print(u);
    printf("%d\n\n", flag_u);


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

    print(d);
    printf("%d\n\n", score_d);
    print(l);
    printf("%d\n\n", score_l);
    print(r);
    printf("%d\n\n", score_r);
    print(u);
    printf("%d\n\n", score_u);


    return 0;
}

int main()
{
    matrix_t matrix;
    matrix.rows = 4;
    matrix.columns = 4;

    int a[4][4] = {{2,0,0,0},{2,0,0,4},{0,2,0,0},{0,0,0,0}};
    int *d[4];
    trasform(d, *a, 4);


    matrix.matrix = d;

    teen48game(matrix);

    return 0;
}
