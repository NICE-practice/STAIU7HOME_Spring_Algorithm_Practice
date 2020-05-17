#include "nice_xo.h"

void trasform(char **a, char *buf, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = buf + n * i;
    }
}

int main(void)
{
    // XOgame 5x5
    int successful_tests = 0;

    // test 3x3 first
    char test_3x3_1[3][3];

    // new game
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3_1[i][j] = ' ';

    char *p_test_3x3_1[3];
    trasform(p_test_3x3_1, *test_3x3_1, 3);

    // test 1 3x3
    if (xogame(p_test_3x3_1, 3, 'X') == 4)
        successful_tests++;
    else
        printf("TEST 3x3 1 FAILED\n");

    // test 2 3x3
    test_3x3_1[1][1] = 'X';
    test_3x3_1[0][0] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 6)
        successful_tests++;
    else
        printf("TEST 3x3 2 FAILED\n");

    // test 3 3x3
    test_3x3_1[2][0] = 'X';
    test_3x3_1[0][2] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 1)
        successful_tests++;
    else
        printf("TEST 3x3 3 FAILED\n");

    // test 4 3x3
    test_3x3_1[0][1] = 'X';
    test_3x3_1[2][1] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 5)
        successful_tests++;
    else
        printf("TEST 3x3 4 FAILED\n");

    // test 5 3x3
    test_3x3_1[1][2] = 'X';
    test_3x3_1[2][2] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 3)
        successful_tests++;
    else
        printf("TEST 3x3 5 FAILED\n");

    // new game
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3_1[i][j] = ' ';

    // test 6 3x3
    test_3x3_1[1][1] = 'X';
    test_3x3_1[2][0] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 8)
        successful_tests++;
    else
        printf("TEST 3x3 6 FAILED\n");

    // test 7 3x3
    test_3x3_1[2][2] = 'X';
    test_3x3_1[0][0] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 3)
        successful_tests++;
    else
        printf("TEST 3x3 7 FAILED\n");

    // test 8 3x3
    test_3x3_1[1][0] = 'X';
    test_3x3_1[1][2] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 1)
        successful_tests++;
    else
        printf("TEST 3x3 8 FAILED\n");

    // test 9 3x3
    test_3x3_1[0][1] = 'X';
    test_3x3_1[2][1] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 2)
        successful_tests++;
    else
        printf("TEST 3x3 9 FAILED\n");

    // new game
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3_1[i][j] = ' ';

    // test 10 3x3
    test_3x3_1[1][1] = 'X';
    test_3x3_1[1][2] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 0)
        successful_tests++;
    else
        printf("TEST 3x3 10 FAILED\n");

    // test 11 3x3
    test_3x3_1[0][0] = 'X';
    test_3x3_1[2][2] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 2)
        successful_tests++;
    else
        printf("TEST 3x3 11 FAILED\n");

    // test 12 3x3
    test_3x3_1[0][2] = 'X';
    test_3x3_1[0][1] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 6)
        successful_tests++;
    else
        printf("TEST 3x3 12 FAILED\n");

    // new game
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3_1[i][j] = ' ';

    // test 13 3x3
    test_3x3_1[1][1] = 'X';
    test_3x3_1[0][1] = 'O';
    test_3x3_1[0][0] = 'X';
    test_3x3_1[2][1] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 8)
        successful_tests++;
    else
        printf("TEST 3x3 13 FAILED\n");

    // new game
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3_1[i][j] = ' ';

    // test 14 3x3
    test_3x3_1[1][1] = 'X';
    test_3x3_1[0][0] = 'O';
    test_3x3_1[2][0] = 'X';
    test_3x3_1[0][2] = 'O';
    test_3x3_1[2][2] = 'X';
    test_3x3_1[1][2] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 7)
        successful_tests++;
    else
        printf("TEST 3x3 14 FAILED\n");

    // test 3x3 second
    char test_3x3_2[3][3];

    // new game
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3_2[i][j] = ' ';

    char *p_test_3x3_2[3];
    trasform(p_test_3x3_2, *test_3x3_2, 3);

    // test 15 3x3
    test_3x3_2[1][0] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 1)
        successful_tests++;
    else
        printf("TEST 3x3 15 FAILED\n");

    // tsst 16 3x3
    test_3x3_2[1][1] = 'O';
    test_3x3_2[1][2] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 6)
        successful_tests++;
    else
        printf("TEST 3x3 16 FAILED\n");

    // test 17 3x3
    test_3x3_2[2][0] = 'O';
    test_3x3_2[0][2] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 8)
        successful_tests++;
    else
        printf("TEST 3x3 17 FAILED\n");

    // test 18 3x3
    test_3x3_2[2][2] = 'O';
    test_3x3_2[0][0] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 7)
        successful_tests++;
    else
        printf("TEST 3x3 18 FAILED\n");

    // new game
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3_2[i][j] = ' ';

    // test 19 3x3
    test_3x3_2[1][1] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 0)
        successful_tests++;
    else
        printf("TEST 3x3 19 FAILED\n");

    // test 20 3x3
    test_3x3_2[0][0] = 'O';
    test_3x3_2[2][2] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 6)
        successful_tests++;
    else
        printf("TEST 3x3 20 FAILED\n");

    // test 21 3x3
    test_3x3_2[2][0] = 'O';
    test_3x3_2[1][0] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 5)
        successful_tests++;
    else
        printf("TEST 3x3 21 FAILED\n");

    // test 22 3x3
    test_3x3_2[1][2] = 'O';
    test_3x3_2[0][1] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 7)
        successful_tests++;
    else
        printf("TEST 3x3 22 FAILED\n");

    // new game
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3_2[i][j] = ' ';

    // test 23 3x3
    test_3x3_2[1][1] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 0)
        successful_tests++;
    else
        printf("TEST 3x3 23 FAILED\n");

    // test 24 3x3
    test_3x3_2[0][0] = 'O';
    test_3x3_2[2][0] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 2)
        successful_tests++;
    else
        printf("TEST 3x3 24 FAILED\n");

    // test 25 3x3
    test_3x3_2[0][2] = 'O';
    test_3x3_2[0][1] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 7)
        successful_tests++;
    else
        printf("TEST 3x3 25 FAILED\n");
    // test 26 3x3
    test_3x3_2[2][1] = 'O';
    test_3x3_2[1][0] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 5)
        successful_tests++;
    else
        printf("TEST 3x3 26 FAILED\n");

    // new game
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3_2[i][j] = ' ';

    // test 27 3x3
    test_3x3_2[0][0] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 1)
        successful_tests++;
    else
        printf("TEST 3x3 27 FAILED\n");

    // test 28 3x3
    test_3x3_2[1][1] = 'O';
    test_3x3_2[2][0] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 3)
        successful_tests++;
    else
        printf("TEST 3x3 28 FAILED\n");

    // test 29 3x3
    test_3x3_2[1][0] = 'O';
    test_3x3_2[1][2] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 1)
        successful_tests++;
    else
        printf("TEST 3x3 29 FAILED\n");

    // test 30 3x3
    test_3x3_2[0][1] = 'O';
    test_3x3_2[2][1] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 8)
        successful_tests++;
    else
        printf("TEST 3x3 30 FAILED");

    // new game
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3_2[i][j] = ' ';

    // test 31 3x3
    test_3x3_2[0][0] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 1)
        successful_tests++;
    else
        printf("TEST 3x3 31 FAILED\n");

    // test 32 3x3
    test_3x3_2[1][1] = 'O';
    test_3x3_2[0][2] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 1)
        successful_tests++;
    else
        printf("TEST 3x3 32 FAILED");


    // XOgame 5x5
    int successful_tests1 = 0;

    // test 5x5 first
    char test_5x5_1[5][5];

    // new game
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_1[i][j] = ' ';

    char *p_test_5x5_1[5];
    trasform(p_test_5x5_1, *test_5x5_1, 5);

    // test 5x5 1
    if (xogame(p_test_5x5_1, 5, 'X') == 12)
        successful_tests1++;
    else
        printf("TEST 5x5 1 FAILED\n");

    // test 5x5 2
    test_5x5_1[2][2] = 'X';
    test_5x5_1[0][0] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 4)
        successful_tests1++;
    else
        printf("TEST 5x5 2 FAILED\n");

    // test 5x5 3
    test_5x5_1[0][4] = 'X';
    test_5x5_1[1][3] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 2)
        successful_tests1++;
    else
        printf("TEST 5x5 3 FAILED\n");

    // test 5x5 4
    test_5x5_1[0][2] = 'X';
    test_5x5_1[1][2] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 10)
        successful_tests1++;
    else
        printf("TEST 5x5 4 FAILED\n");

    // test 5x5 5
    test_5x5_1[2][0] = 'X';
    test_5x5_1[2][1] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 1)
        successful_tests1++;
    else
        printf("TEST 5x5 5 FAILED\n");

    // test 5x5 6
    test_5x5_1[0][1] = 'X';
    test_5x5_1[3][0] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 3)
        successful_tests1++;
    else
        printf("TEST 5x5 6 FAILED\n");

    // test 5x5 7
    test_5x5_1[0][3] = 'X';
    test_5x5_1[3][1] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 5)
        successful_tests1++;
    else
        printf("TEST 5x5 7 FAILED\n");

    // test 5x5 8
    test_5x5_1[1][0] = 'X';
    test_5x5_1[3][2] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 6)
        successful_tests1++;
    else
        printf("TEST 5x5 8 FAILED\n");

    // test 5x5 9
    test_5x5_1[1][1] = 'X';
    test_5x5_1[3][3] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 19)
        successful_tests1++;
    else
        printf("TEST 5x5 9 FAILED\n");

    // test 5x5 10
    test_5x5_1[3][4] = 'X';
    test_5x5_1[4][0] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 9)
        successful_tests1++;
    else
        printf("TEST 5x5 10 FAILED\n");

    // test 5x5 11
    test_5x5_1[1][4] = 'X';
    test_5x5_1[4][1] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 13)
        successful_tests1++;
    else
        printf("TEST 5x5 11 FAILED\n");

    // test 5x5 12
    test_5x5_1[2][3] = 'X';
    test_5x5_1[4][2] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 14)
        successful_tests1++;
    else
        printf("TEST 5x5 12 FAILED\n");

    // test 5x5 13
    test_5x5_1[2][4] = 'X';
    test_5x5_1[4][4] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 23)
        successful_tests1++;
    else
        printf("TEST 5x5 13 FAILED\n");

    // test 5x5 14
    test_5x5_1[4][4] = ' ';
    test_5x5_1[4][2] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 24)
        successful_tests1++;
    else
        printf("TEST 5x5 14 FAILED\n");

    // new game
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_1[i][j] = ' ';

    // test 5x5 15
    test_5x5_1[2][2] = 'X';
    test_5x5_1[0][2] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 0)
        successful_tests1++;
    else
        printf("TEST 5x5 15 FAILED\n");

    // test 5x5 16
    test_5x5_1[0][0] = 'X';
    test_5x5_1[1][1] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 20)
        successful_tests1++;
    else
        printf("TEST 5x5 16 FAILED\n");

    // test 5x5 17
    test_5x5_1[4][0] = 'X';
    test_5x5_1[3][1] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 10)
        successful_tests1++;
    else
        printf("TEST 5x5 17 FAILED\n");

    // test 5x5 18
    test_5x5_1[3][0] = 'X';
    test_5x5_1[2][1] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 1)
        successful_tests1++;
    else
        printf("TEST 5x5 18 FAILED\n");

    // test 5x5 19
    test_5x5_1[0][1] = 'X';
    test_5x5_1[3][0] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 3)
        successful_tests1++;
    else
        printf("TEST 5x5 19 FAILED\n");

    // test 5x5 20
    test_5x5_1[0][3] = 'X';
    test_5x5_1[3][2] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 4)
        successful_tests1++;
    else
        printf("TEST 5x5 20 FAILED\n");

    // test 5x5 21
    test_5x5_1[0][4] = 'X';
    test_5x5_1[3][3] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 19)
        successful_tests1++;
    else
        printf("TEST 5x5 21 FAILED\n");

    // new game
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_1[i][j] = ' ';

    // test 5x5 22
    test_5x5_1[2][2] = 'X';
    test_5x5_1[3][0] = 'O';
    test_5x5_1[0][0] = 'X';
    test_5x5_1[1][0] = 'O';
    test_5x5_1[1][2] = 'X';
    test_5x5_1[3][1] = 'O';
    test_5x5_1[2][1] = 'X';
    test_5x5_1[3][2] = 'O';
    test_5x5_1[0][2] = 'X';
    test_5x5_1[3][3] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 19)
        successful_tests1++;
    else
        printf("TEST 5x5 22 FAILED\n");

    // new game
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_1[i][j] = ' ';

    // test 5x5 23
    test_5x5_1[2][2] = 'X';
    test_5x5_1[0][1] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 0)
        successful_tests1++;
    else
        printf("TEST 5x5 23 FAILED\n");

    // test 5x5 24
    test_5x5_1[0][0] = 'X';
    test_5x5_1[0][2] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 24)
        successful_tests1++;
    else
        printf("TEST 5x5 24 FAILED\n");

    // test 5x5 25
    test_5x5_1[4][4] = 'X';
    test_5x5_1[0][3] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 6)
        successful_tests1++;
    else
        printf("TEST 5x5 25 FAILED\n");

    // test 5x5 26
    test_5x5_1[1][1] = 'X';
    test_5x5_1[0][4] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 18)
        successful_tests1++;
    else
        printf("TEST 5x5 26 FAILED\n");

    // new game
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_1[i][j] = ' ';

    // test 5x5 27
    test_5x5_1[2][2] = 'X';
    test_5x5_1[0][0] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 4)
        successful_tests1++;
    else
        printf("TEST 5x5 27 FAILED\n");

    // test 5x5 28
    test_5x5_1[0][4] = 'X';
    test_5x5_1[1][0] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 20)
        successful_tests1++;
    else
        printf("TEST 5x5 28 FAILED\n");

    // test 5x5 29
    test_5x5_1[4][0] = 'X';
    test_5x5_1[2][0] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 8)
        successful_tests1++;
    else
        printf("TEST 5x5 29 FAILED\n");

    // test 5x5 30
    test_5x5_1[1][3] = 'X';
    test_5x5_1[3][0] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 16)
        successful_tests1++;
    else
        printf("TEST 5x5 30 FAILED\n");

    // new game
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_1[i][j] = ' ';

    // test 5x5 31
    test_5x5_1[2][2] = 'X';
    test_5x5_1[0][0] = 'O';
    test_5x5_1[0][4] = 'X';
    test_5x5_1[4][0] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 2)
        successful_tests1++;
    else
        printf("TEST 5x5 31 FAILED\n");

    // test 5x5 32
    test_5x5_1[0][2] = 'X';
    test_5x5_1[1][0] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 7)
        successful_tests1++;
    else
        printf("TEST 5x5 32 FAILED\n");

    // test 5x5 33
    test_5x5_1[1][2] = 'X';
    test_5x5_1[2][0] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 15)
        successful_tests1++;
    else
        printf("TEST 5x5 33 FAILED\n");

    // test 5x5 34
    test_5x5_1[3][2] = 'X';
    test_5x5_1[3][0] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 22)
        successful_tests1++;
    else
        printf("TEST 5x5 34 FAILED\n");

    // new game
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_1[i][j] = ' ';

    // test 5x5 35
    test_5x5_1[2][2] = 'X';
    test_5x5_1[0][0] = 'O';
    test_5x5_1[0][4] = 'X';
    test_5x5_1[4][0] = 'O';
    test_5x5_1[0][2] = 'X';
    test_5x5_1[4][2] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 10)
        successful_tests1++;
    else
        printf("TEST 5x5 35 FAILED\n");

    // test 5x5 36
    test_5x5_1[2][0] = 'X';
    test_5x5_1[1][0] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 11)
        successful_tests1++;
    else
        printf("TEST 5x5 36 FAILED\n");

    // test 5x5 37
    test_5x5_1[2][1] = 'X';
    test_5x5_1[3][0] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 13)
        successful_tests1++;
    else
        printf("TEST 5x5 37 FAILED\n");

    // test 5x5 38
    test_5x5_1[2][3] = 'X';
    test_5x5_1[3][1] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 14)
        successful_tests1++;
    else
        printf("TEST 5x5 38 FAILED\n");

    // test 5x5 second
    char test_5x5_2[5][5];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_2[i][j] = ' ';

    char *p_test_5x5_2[5];
    trasform(p_test_5x5_2, *test_5x5_2, 5);

    // test 5x5 39
    test_5x5_2[2][2] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 0)
        successful_tests1++;
    else
        printf("TEST 5x5 39 FAILED\n");

    // test 5x5 40
    test_5x5_2[0][0] = 'O';
    test_5x5_2[0][2] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 4)
        successful_tests1++;
    else
        printf("TEST 5x5 40 FAILED\n");

    // test 5x5 41
    test_5x5_2[0][4] = 'O';
    test_5x5_2[1][2] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 5)
        successful_tests1++;
    else
        printf("TEST 5x5 41 FAILED\n");

    // test 5x5 42
    test_5x5_2[1][0] = 'O';
    test_5x5_2[3][2] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 22)
        successful_tests1++;
    else
        printf("TEST 5x5 42 FAILED\n");

    // test 5x5 43
    test_5x5_2[4][2] = 'O';
    test_5x5_2[0][1] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 15)
        successful_tests1++;
    else
        printf("TEST 5x5 43 FAILED\n");

    // test 5x5 44
    test_5x5_2[3][0] = 'O';
    test_5x5_2[1][1] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 3)
        successful_tests1++;
    else
        printf("TEST 5x5 44 FAILED\n");

    // test 5x5 45
    test_5x5_2[0][3] = 'O';
    test_5x5_2[2][1] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 8)
        successful_tests1++;
    else
        printf("TEST 5x5 45 FAILED\n");

    // test 5x5 46
    test_5x5_2[1][3] = 'O';
    test_5x5_2[3][1] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 21)
        successful_tests1++;
    else
        printf("TEST 5x5 46 FAILED\n");

    // test 5x5 47
    test_5x5_2[4][1] = 'O';
    test_5x5_2[1][4] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 10)
        successful_tests1++;
    else
        printf("TEST 5x5 47 FAILED\n");

    // test 5x5 48
    test_5x5_2[2][0] = 'O';
    test_5x5_2[2][3] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 20)
        successful_tests1++;
    else
        printf("TEST 5x5 48 FAILED\n");

    // new game
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_2[i][j] = ' ';

    // test 5x5 49
    test_5x5_2[0][0] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 12)
        successful_tests1++;
    else
        printf("TEST 5x5 49 FAILED\n");

    // test 5x5 50
    test_5x5_2[2][2] = 'O';
    test_5x5_2[0][4] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 2)
        successful_tests1++;
    else
        printf("TEST 5x5 50 FAILED\n");

    // test 5x5 51
    test_5x5_2[0][2] = 'O';
    test_5x5_2[1][0] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 7)
        successful_tests1++;
    else
        printf("TEST 5x5 51 FAILED\n");

    // test 5x5 52
    test_5x5_2[1][2] = 'O';
    test_5x5_2[2][0] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 17)
        successful_tests1++;
    else
        printf("TEST 5x5 52 FAILED\n");

    // test 5x5 53
    test_5x5_2[3][2] = 'O';
    test_5x5_2[4][2] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 1)
        successful_tests1++;
    else
        printf("TEST 5x5 53 FAILED\n");

    // test 5x5 54
    test_5x5_2[0][1] = 'O';
    test_5x5_2[3][0] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 20)
        successful_tests1++;
    else
        printf("TEST 5x5 54 FAILED\n");

    // new game
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_2[i][j] = ' ';

    // test 5x5 55
    test_5x5_2[0][0] = 'X';
    test_5x5_2[2][2] = 'O';
    test_5x5_2[1][0] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 4)
        successful_tests1++;
    else
        printf("TEST 5x5 55 FAILED\n");

    // test 5x5 56
    test_5x5_2[0][4] = 'O';
    test_5x5_2[2][0] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 20)
        successful_tests1++;
    else
        printf("TEST 5x5 56 FAILED\n");

    // test 5x5 57
    test_5x5_2[4][0] = 'O';
    test_5x5_2[3][0] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 8)
        successful_tests1++;
    else
        printf("TEST 5x5 57 FAILED\n");

    // test 5x5 58
    test_5x5_2[1][3] = 'O';
    test_5x5_2[0][1] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 16)
        successful_tests1++;
    else
        printf("TEST 5x5 58 FAILED\n");

    // new game
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_2[i][j] = ' ';

    // test 5x5 59
    test_5x5_2[0][4] = 'X';
    test_5x5_2[2][2] = 'O';
    test_5x5_2[1][4] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 0)
        successful_tests1++;
    else
        printf("TEST 5x5 59 FAILED\n");

    // test 5x5 60
    test_5x5_2[0][0] = 'O';
    test_5x5_2[2][4] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 24)
        successful_tests1++;
    else
        printf("TEST 5x5 60 FAILED\n");

    // test 5x5 61
    test_5x5_2[4][4] = 'O';
    test_5x5_2[3][4] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 6)
        successful_tests1++;
    else
        printf("TEST 5x5 61 FAILED\n");

    // test 5x5 62
    test_5x5_2[1][1] = 'O';
    test_5x5_2[0][1] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 18)
        successful_tests1++;
    else
        printf("TEST 5x5 62 FAILED\n");

    // new game
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_2[i][j] = ' ';

    // test 5x5 63
    test_5x5_2[0][0] = 'X';
    test_5x5_2[2][2] = 'O';
    test_5x5_2[0][4] = 'X';
    test_5x5_2[0][2] = 'O';
    test_5x5_2[1][2] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 10)
        successful_tests1++;
    else
        printf("TEST 5x5 63 FAILED\n");

    // new game
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_2[i][j] = ' ';

    // test 5x5 64
    test_5x5_2[2][2] = 'X';
    test_5x5_2[0][0] = 'O';
    test_5x5_2[2][0] = 'X';
    test_5x5_1[0][4] = 'O';
    test_5x5_2[2][1] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 1)
        successful_tests1++;
    else
        printf("TEST 5x5 64 FAILED\n");

    // test 5x5 65
    test_5x5_2[0][1] = 'O';
    test_5x5_2[1][1] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 2)
        successful_tests1++;
    else
        printf("TEST 5x5 65 FAILED\n");

    // test 5x5 66
    test_5x5_2[0][2] = 'O';
    test_5x5_2[1][0] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 3)
        successful_tests1++;
    else
        printf("TEST 5x5 66 FAILED\n");

    // test 5x5 67
    test_5x5_2[0][3] = 'O';
    test_5x5_2[4][0] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 4)
        successful_tests1++;
    else
        printf("TEST 5x5 67 FAILED\n");

    // new game
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_2[i][j] = ' ';

    // test 5x5 68
    test_5x5_2[2][2] = 'X';
    test_5x5_2[0][0] = 'O';
    test_5x5_2[0][4] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 20)
        successful_tests1++;
    else
        printf("TEST 5x5 68 FAILED\n");

    // test 5x5 69
    test_5x5_1[4][0] = 'O';
    test_5x5_2[2][1] = 'X';
    test_5x5_2[1][0] = 'O';
    test_5x5_2[4][4] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 10)
        successful_tests1++;
    else
        printf("TEST 5x5 69 FAILED\n");

    // new game
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_2[i][j] = ' ';

    // test 5x5 70
    test_5x5_2[2][2] = 'X';
    test_5x5_2[0][0] = 'O';
    test_5x5_2[2][0] = 'X';
    test_5x5_2[1][0] = 'O';
    test_5x5_2[0][2] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 21)
        successful_tests1++;
    else
        printf("TEST 5x5 70 FAILED\n");

    // new game
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_2[i][j] = ' ';

    // test 5x5 71
    test_5x5_2[0][0] = 'X';
    test_5x5_2[2][2] = 'O';
    test_5x5_2[1][1] = 'X';
    test_5x5_2[2][1] = 'O';
    test_5x5_2[1][2] = 'X';
    test_5x5_2[2][3] = 'O';
    test_5x5_2[1][3] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 11)
        successful_tests1++;
    else
        printf("TEST 5x5 71 FAILED\n");
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_2[i][j] = ' ';

    // test 5x5 72
    test_5x5_2[2][0] = 'X';
    test_5x5_2[2][2] = 'O';
    test_5x5_2[1][1] = 'X';
    test_5x5_2[2][1] = 'O';
    test_5x5_2[1][2] = 'X';
    test_5x5_2[2][3] = 'O';
    test_5x5_2[1][3] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 0)
        successful_tests1++;
    else
        printf("TEST 5x5 72 FAILED\n");

    // test 5x5 73
    test_5x5_2[0][0] = 'O';
    test_5x5_2[3][2] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 1)
        successful_tests1++;
    else
        printf("TEST 5x5 73 FAILED\n");

    // new game
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_2[i][j] = ' ';

    // test 5x5 74
    test_5x5_2[2][2] = 'X';
    test_5x5_2[0][0] = 'O';
    test_5x5_2[0][2] = 'X';
    test_5x5_2[1][0] = 'O';
    test_5x5_2[2][0] = 'X';
    test_5x5_2[4][1] = 'O';
    test_5x5_2[4][2] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 1)
        successful_tests1++;
    else
        printf("TEST 5x5 74 FAILED\n");

    // test 5x5 75
    test_5x5_2[4][2] = ' ';
    test_5x5_2[3][2] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 22)
        successful_tests1++;
    else
        printf("TEST 5x5 75 FAILED\n");

    // new game
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_2[i][j] = ' ';

    // test 5x5 76
    test_5x5_2[2][2] = 'X';
    test_5x5_2[0][0] = 'O';
    test_5x5_2[2][0] = 'X';
    test_5x5_2[1][0] = 'O';
    test_5x5_2[2][1] = 'X';
    test_5x5_2[4][1] = 'O';
    test_5x5_2[2][3] = 'X';
    test_5x5_2[3][1] = 'O';
    test_5x5_2[3][2] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 14)
        successful_tests1++;
    else
        printf("TEST 5x5 76 FAILED\n");

    // new game
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_2[i][j] = ' ';

    // test 5x5 77
    test_5x5_2[0][0] = 'X';
    test_5x5_2[2][2] = 'O';
    test_5x5_2[0][1] = 'X';
    test_5x5_2[1][1] = 'O';
    test_5x5_2[0][2] = 'X';
    test_5x5_2[1][2] = 'O';
    test_5x5_2[3][2] = 'X';
    test_5x5_2[1][3] = 'O';
    test_5x5_2[3][3] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 1)
        successful_tests1++;
    else
        printf("TEST 5x5 77 FAILED\n");

    // new game
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_2[i][j] = ' ';

    // test 5x5 78
    test_5x5_2[2][2] = 'X';
    test_5x5_2[3][2] = 'O';
    test_5x5_2[2][0] = 'X';
    test_5x5_2[1][1] = 'O';
    test_5x5_2[0][2] = 'X';
    test_5x5_2[1][3] = 'O';
    test_5x5_2[0][4] = 'X';
    test_5x5_2[1][4] = 'O';
    test_5x5_2[4][2] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 0)
        successful_tests1++;
    else
        printf("TEST 5x5 78 FAILED\n");

    // new game
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_2[i][j] = ' ';

    // test 5x5 79
    test_5x5_2[2][2] = 'X';
    test_5x5_2[3][2] = 'O';
    test_5x5_2[1][0] = 'X';
    test_5x5_2[1][1] = 'O';
    test_5x5_2[0][1] = 'X';
    test_5x5_2[1][3] = 'O';
    test_5x5_2[3][1] = 'X';
    test_5x5_2[1][4] = 'O';
    test_5x5_2[3][3] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 23)
        successful_tests1++;
    else
        printf("TEST 5x5 79 FAILED\n");

    // test 5x5 80
    // new game
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_2[i][j] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == -1)
        successful_tests1++;
    else
        printf("TEST 5x5 80 FAILED\n");

    // test 5x5 80
    // new game
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_1[i][j] = ' ';

    // test 5x5 81
    test_5x5_1[2][2] = 'X';
    test_5x5_1[0][0] = 'O';
    test_5x5_1[0][4] = 'X';
    test_5x5_1[4][1] = 'O';
    test_5x5_1[0][2] = 'X';
    test_5x5_1[1][0] = 'O';
    test_5x5_1[1][2] = 'X';
    test_5x5_1[2][0] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 17)
        successful_tests1++;
    else
        printf("TEST 5x5 81 FAILED %d\n", xogame(p_test_5x5_1, 5, 'O'));


    printf("%d / 32 TESTS 3x3 SUCCESSFUL\n", successful_tests);
    printf("%d / 81 TESTS 5x5 SUCCESSFUL\n", successful_tests1);
    return 0;
}

