#include "nice_teen48.h"
#include <stdio.h>

void trasform(int **a, int *buf, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = buf + n * i;
    }
}

int main(void)
{
    int correct = 0;
    matrix_t matrix;
    matrix.rows = 4;
    matrix.columns = 4;
    int *d[4];

    //Tests with ld = 0
    //Test 1
    int a1[4][4] = {{0,0,0,0},
                   {8,4,2,16},
                   {0,8,4,2},
                   {0,4,8,0}};

    trasform(d, *a1, 4);
    matrix.matrix = d;
    if (teen48game(matrix) == 'd')
        correct++;
    else
        printf("Test 1 failed\n");

    //Test 2
    int a2[4][4] = {{0,0,0,0},
                   {8,4,2,16},
                   {4,8,4,2},
                   {0,0,16,0}};

    trasform(d, *a2, 4);
    matrix.matrix = d;
    if (teen48game(matrix) == 'l')
        correct++;
    else
        printf("Test 2 failed\n");

    //No spaces
    //Test 3
    int a3[4][4] = {{2,2,2,2},
                   {2,2,2,2},
                   {2,2,2,2},
                   {2,2,2,2}};

    trasform(d, *a3, 4);
    matrix.matrix = d;
    if (teen48game(matrix) == 'd')
        correct++;
    else
        printf("Test 3 failed\n");

    //Moves to all sides
    //Test 4
    int a4[4][4] = {{0,0,2,2},
                   {0,2,2,2},
                   {0,0,2,2},
                   {8,2,0,2}};

    trasform(d, *a4, 4);
    matrix.matrix = d;
    if (teen48game(matrix) == 'd')
        correct++;
    else
        printf("Test 4 failed\n");

    //First priority loses to second
    //Test 5
    int a5[4][4] = {{4,4,4,4},
                    {8,8,8,8},
                    {32,32,32,32},
                    {64,64,64,64}};
    trasform(d, *a5, 4);
    matrix.matrix = d;
    if (teen48game(matrix) == 'l')
        correct++;
    else
        printf("Test 5 failed\n");

    //First priority wins
    //Test 6
    int a6[4][4] = {{0,0,0,0},
                    {0,0,0,2},
                    {0,0,0,16},
                    {8,2,2,16}};

    trasform(d, *a6, 4);
    matrix.matrix = d;
    if (teen48game(matrix) == 'd')
        correct++;
    else
        printf("Test 6 failed\n");

    //Third priority wins
    //Test 7
    int a7[4][4] = {{2,4,2,0},
                    {4,8,16,32},
                    {8,16,32,64},
                    {16,32,64,128}};
    trasform(d, *a7, 4);
    matrix.matrix = d;
    if (teen48game(matrix) == 'r')
        correct++;
    else
        printf("Test 7 failed\n");

    //Fourth priority left
    //Test 8
    int a8[4][4] = {{0,0,0,0},
                    {4,8,16,32},
                    {8,16,32,64},
                    {16,32,64,128}};
    trasform(d, *a8, 4);
    matrix.matrix = d;
    if (teen48game(matrix) == 'u')
        correct++;
    else
        printf("Test 8 failed\n");


    printf("%d/8 tests passed", correct);
    return 0;
}
