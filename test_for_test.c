#include <stdio.h>

int first_check(int arr[25], int field_size, int how);
int xogame(char **bf, const int field_size, const char symb)
{
    int arr[25];
    int my_marks = 0, enemys_marks = 0;
    int turn, result;

    for (int i = 0; i < field_size; i++)
        for (int j = 0; j < field_size; j++)
        {
            if (bf[i][j] == symb)
            {
                arr[i * field_size + j] = 1;
                my_marks++;
            }
            else if (bf[i][j] == ' ')
                arr[i * field_size + j] = 0;
            else
            {
                arr[i * field_size + j] = -1;
                enemys_marks++;
            }
        }
    if (my_marks == enemys_marks)
        turn = 1;
    else
        turn = 2;


    if (field_size == 3)
    {
        if (turn == 1)
        {
            if (enemys_marks == 0)
                return 4;
            if (enemys_marks == 1)
            {
                    if ((arr[5] == -1) || (arr[7] == -1))
                        return 0;
                    if ((arr[0] == -1) || arr[8] == -1)
                        return 6;
                    if ((arr[1] == -1) || (arr[3] == -1) || (arr[2] == -1) || (arr[6] == -1))
                        return 8;
            }
            if (enemys_marks == 2)
            {
                result = first_check(arr, field_size, 1);
                if (result >= 0)
                    return result;
                result = first_check(arr, field_size, -1);
                if (result >= 0)
                    return result;
            }
            if (enemys_marks == 3)
            {
                result = first_check(arr, field_size, 1);
                if (result >= 0)
                    return result;
                if (arr[7] == -1)
                    return 5;
                return 1;
            }
            if (enemys_marks == 4)
                for (int i = 0; i < 9; i++)
                    if (arr[i] == 0)
                        return i;
        }
        else
        {
            if (enemys_marks == 1)
            {
                if (arr[4] == -1)
                    return 0;
                else
                    return 4;
            }
            if (enemys_marks == 2)
            {
                if (arr[4] == -1)
                {
                    for (int i = 1; i < 8; i++)
                        if ((arr[i] == -1) && (i != 4))
                            return (8 - i);
                    return 6;

                }
                else
                {
                    //оборона
                    result = first_check(arr, field_size, -1);
                    if (result >= 0)
                        return result;
                    //крестики только по бокам
                    return 6;
                }
            }
            else
            {
                result = first_check(arr, field_size, 1);
                if (result >= 0)
                    return result;
                result = first_check(arr, field_size, -1);
                if (result >= 0)
                    return result;
                for (int i = 0; i < 9; i++)
                    if (arr[i] == 0)
                        return i;
            }
        }
    }
    else
    {
        if (turn == 1)
        {
            if (enemys_marks == 0)
                return 12;
            if (enemys_marks == 1)
            {
                //главная дианональ
                int flag = 1;
                for (int i = 0; i < field_size; i++)
                    if (arr[i*field_size + i] == -1)
                        flag = 0;
                if (flag)
                    return 0;
                return 4;
            }
            if (enemys_marks == 2)
            {
                //главная дианональ
                int flag = 1;
                for (int i = 0; i < field_size; i++)
                    if (arr[i*field_size + i] == -1)
                        flag = 0;
                if (flag)
                    return 24;
                //побочная
                flag = 1;
                for (int i = 0; i < field_size; i++)
                    if (arr[i*field_size + (field_size - i - 1)] == -1)
                        flag = 0;
                if (flag)
                    return 20;
                //центральный столбец
                flag = 1;
                for (int i = 0; i < field_size; i++)
                    if (arr[i*field_size + 2] == -1)
                        flag = 0;
                if (flag)
                    return 2;
            }
            if (enemys_marks == 3)
            {
                //главная дианональ
                int flag = 1;
                for (int i = 0; i < field_size; i++)
                    if (arr[i*field_size + i] == -1)
                        flag = 0;
                if (flag)
                    return 6;
                //побочная
                flag = 1;
                for (int i = 0; i < field_size; i++)
                    if (arr[i*field_size + (field_size - i - 1)] == -1)
                        flag = 0;
                if (flag)
                    return 8;
                //ценртальный столбец
                flag = 1;
                for (int i = 0; i < field_size; i++)
                    if (arr[i*field_size + 2] == -1)
                        flag = 0;
                if (flag)
                    return 7;
                //центральная строка
                flag = 1;
                for (int i = 0; i < field_size; i++)
                    if (arr[i + field_size*2] == -1)
                        flag = 0;
                if (flag)
                    return 10;
            }
            if (enemys_marks == 4)
            {
                result = first_check(arr, field_size, 1);
                if (result >= 0)
                    return result;
                //ценртальный столбец
                int flag = 1;
                for (int i = 0; i < field_size; i++)
                    if (arr[i*field_size + 2] == -1)
                        flag = 0;
                if (flag)
                    return 17;
                //центральная строка
                flag = 1;
                for (int i = 0; i < field_size; i++)
                    if (arr[i + field_size*2] == -1)
                        flag = 0;
                if (flag)
                    return 11;
                //случайный пустой
                for (int i = 0; i < field_size*field_size; i++)
                    if (arr[i] == 0)
                        return i;
            }
            if (enemys_marks == 5)
            {
                result = first_check(arr, field_size, 1);
                if (result >= 0)
                    return result;
                result = first_check(arr, field_size, -1);
                if (result >= 0)
                    return result;
                //центральная строка
                int flag = 1;
                for (int i = 0; i < field_size; i++)
                    if (arr[i + field_size*2] == -1)
                        flag = 0;
                if (flag)
                    return 13;
                //случайный пустой
                for (int i = 0; i < field_size*field_size; i++)
                    if (arr[i] == 0)
                        return i;
            }
            else
            {
                result = first_check(arr, field_size, 1);
                if (result >= 0)
                    return result;
                result = first_check(arr, field_size, -1);
                if (result >= 0)
                    return result;
                for (int i = 0; i < field_size * field_size; i++)
                    if (arr[i] == 0)
                        return i;
            }
        }
        else
        {
            if (enemys_marks == 1)
            {
                if (arr[12] == 0)
                    return 12;
                else
                    return 0;
            }
            if (enemys_marks == 2)
            {
                if (arr[12] == 1)
                {
                    //главная дианональ
                    int flag = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i*field_size + i] == -1)
                            flag = 0;
                    if (flag)
                        return 0;
                    //побочная
                    flag = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i*field_size + (field_size - i - 1)] == -1)
                            flag = 0;
                    if (flag)
                        return 4;
                    //ценртальный столбец
                    return 2;
                }
                else
                {
                    if (arr[4] == 0)
                        return 4;
                    else
                        return 20;
                }
            }
            if (enemys_marks == 3)
            {
                if (arr[12] == 1)
                {
                    //главная дианональ
                    int flag = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i*field_size + i] == -1)
                            flag = 0;
                    if (flag)
                        return 24;
                    //побочная
                    flag = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i*field_size + (field_size - i - 1)] == -1)
                            flag = 0;
                    if (flag)
                        return 20;
                    //ценртальный столбец
                    flag = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i*field_size + 2] == -1)
                            flag = 0;
                    if (flag)
                        return 7;
                    //центральная строка
                    return 10;
                }
                else
                {
                    //верхняя строка
                    int flag = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i] == -1)
                            flag = 0;
                    if (flag)
                        return 1;
                    //левый столбец
                    flag = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i*field_size] == -1)
                            flag = 0;
                    if (flag)
                        return 5;
                    //нижняя строка
                    return 21;
                }
            }
            if (enemys_marks == 4)
            {
                result = first_check(arr, field_size, -1);
                if (result >= 0)
                    return result;
                if (arr[12] == 1)
                {
                    //главная дианональ
                    int flag = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i*field_size + i] == -1)
                            flag = 0;
                    if (flag)
                        return 6;
                    //побочная
                    flag = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i*field_size + (field_size - i - 1)] == -1)
                            flag = 0;
                    if (flag)
                        return 8;
                    //ценртальный столбец
                    flag = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i*field_size + 2] == -1)
                            flag = 0;
                    if (flag)
                        return 17;
                    //центральная строка
                    flag = 1;
                    for (int i = 10; i < 15; i++)
                        if (arr[i] == -1)
                            flag = 0;
                    if (flag)
                        return 11;
                }
                else
                {
                    //верхняя строка
                    int flag = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i] == -1)
                            flag = 0;
                    if (flag)
                        return 2;
                    //левый столбец
                    flag = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i*field_size] == -1)
                            flag = 0;
                    if (flag)
                        return 10;
                    //нижняя строка
                    flag = 1;
                    for (int i = 20; i < 25; i++)
                        if (arr[i] == -1)
                            flag = 0;
                    if (flag)
                        return 22;
                }
                for (int i = 0; i < field_size * field_size; i++)
                    if (arr[i] == 0)
                        return i;
            }
            if (enemys_marks == 5)
            {
                //победа
                result = first_check(arr, field_size, 1);
                if (result >= 0)
                    return result;
                //поражение
                result = first_check(arr, field_size, -1);
                if (result >= 0)
                    return result;

                if (arr[12] == 1)
                {
                    //центральная строка
                    int flag = 1;
                    for (int i = 10; i < 15; i++)
                        if (arr[i] == -1)
                            flag = 0;
                    if (flag)
                        return 1;
                }
                else
                {
                    //верхняя строка
                    int flag = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i] == -1)
                            flag = 0;
                    if (flag)
                        return 3;
                    //левый столбец
                    flag = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i*field_size] == -1)
                            flag = 0;
                    if (flag)
                        return 15;
                    //нижняя строка
                    flag = 1;
                    for (int i = 20; i < 25; i++)
                        if (arr[i] == -1)
                            flag = 0;
                    if (flag)
                        return 23;
                }
                for (int i = 0; i < field_size * field_size; i++)
                    if (arr[i] == 0)
                        return i;

            }
            else
            {
                result = first_check(arr, field_size, 1);
                if (result >= 0)
                    return result;
                result = first_check(arr, field_size, -1);
                if (result >= 0)
                    return result;
                for (int i = 0; i < field_size * field_size; i++)
                    if (arr[i] == 0)
                        return i;
            }
        }
    }
    return 0;
}
int first_check(int arr[25], int field_size, int how)
{
    int result = -1;
    int sum_column, sum_row;
    int sum_diagonal_main = 0, sum_diagonal_bok = 0;

    for (int i = 0; i < field_size; i++)
    {
        sum_column = 0;
        sum_row = 0;
        for (int j = 0; j < field_size; j++)
        {
            sum_column += arr[i + field_size * j];
            sum_row += arr[i * field_size + j];
            if (i == j)
                sum_diagonal_main += arr[i * field_size + j];
            if (i == field_size - 1 - j)
                sum_diagonal_bok += arr[i * field_size + j];
        }
        if (sum_column == how * (field_size - 1))
            for (int str = 0; str < field_size; str++)
                if (arr[i + str * field_size] == 0)
                    return i + str * field_size;
        if (sum_row == how * (field_size - 1))
            for (int col = 0; col < field_size; col++)
                if (arr[i * field_size + col] == 0)
                    return i * field_size + col;
    }
    if (sum_diagonal_main == how * (field_size - 1))
        for (int i = 0; i < field_size; i++)
            if (arr[i*field_size + i] == 0)
                return i*field_size + i;
    if (sum_diagonal_bok == how * (field_size - 1))
        for (int i = 0; i < field_size; i++)
            if (arr[i*field_size + (field_size - i - 1)] == 0)
                return i*field_size + (field_size - i - 1);
    return result;
}

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

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3_2[i][j] = ' ';

    char *p_test_3x3_2[3];
    trasform(p_test_3x3_2, *test_3x3_2, 3);

    // test 15 3x3
    test_3x3_2[1][0] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 4)
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

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3_2[i][j] = ' ';

    // test 27 3x3
    test_3x3_2[0][0] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 4)
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

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3_2[i][j] = ' ';

    // test 31 3x3
    test_3x3_2[0][0] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 4)
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

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_1[i][j] = ' ';

    // test 5x5 22
    test_5x5_1[2][2] = 'X';
    test_5x5_1[0][1] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 0)
        successful_tests1++;
    else
        printf("TEST 5x5 22 FAILED\n");

    // test 5x5 23
    test_5x5_1[0][0] = 'X';
    test_5x5_1[0][2] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 24)
        successful_tests1++;
    else
        printf("TEST 5x5 23 FAILED\n");

    // test 5x5 24
    test_5x5_1[4][4] = 'X';
    test_5x5_1[0][3] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 6)
        successful_tests1++;
    else
        printf("TEST 5x5 24 FAILED\n");

    // test 5x5 25
    test_5x5_1[1][1] = 'X';
    test_5x5_1[0][4] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 18)
        successful_tests1++;
    else
        printf("TEST 5x5 25 FAILED\n");

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_1[i][j] = ' ';

    // test 5x5 26
    test_5x5_1[2][2] = 'X';
    test_5x5_1[0][0] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 4)
        successful_tests1++;
    else
        printf("TEST 5x5 26 FAILED\n");

    // test 5x5 27
    test_5x5_1[0][4] = 'X';
    test_5x5_1[1][0] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 20)
        successful_tests1++;
    else
        printf("TEST 5x5 27 FAILED\n");

    // test 5x5 28
    test_5x5_1[4][0] = 'X';
    test_5x5_1[2][0] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 8)
        successful_tests1++;
    else
        printf("TEST 5x5 28 FAILED\n");

    // test 5x5 29
    test_5x5_1[1][3] = 'X';
    test_5x5_1[3][0] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 16)
        successful_tests1++;
    else
        printf("TEST 5x5 29 FAILED\n");

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_1[i][j] = ' ';

    // test 5x5 30
    test_5x5_1[2][2] = 'X';
    test_5x5_1[0][0] = 'O';
    test_5x5_1[0][4] = 'X';
    test_5x5_1[4][0] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 2)
        successful_tests1++;
    else
        printf("TEST 5x5 30 FAILED\n");

    // test 5x5 31
    test_5x5_1[0][2] = 'X';
    test_5x5_1[1][0] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 7)
        successful_tests1++;
    else
        printf("TEST 5x5 31 FAILED\n");

    // test 5x5 32
    test_5x5_1[1][2] = 'X';
    test_5x5_1[2][0] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 17)
        successful_tests1++;
    else
        printf("TEST 5x5 32 FAILED\n");

    // test 5x5 33
    test_5x5_1[3][2] = 'X';
    test_5x5_1[3][0] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 22)
        successful_tests1++;
    else
        printf("TEST 5x5 33 FAILED\n");

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_1[i][j] = ' ';

    // test 5x5 34
    test_5x5_1[2][2] = 'X';
    test_5x5_1[0][0] = 'O';
    test_5x5_1[0][4] = 'X';
    test_5x5_1[4][0] = 'O';
    test_5x5_1[0][2] = 'X';
    test_5x5_1[4][2] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 10)
        successful_tests1++;
    else
        printf("TEST 5x5 34 FAILED\n");

    // test 5x5 35
    test_5x5_1[2][0] = 'X';
    test_5x5_1[1][0] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 11)
        successful_tests1++;
    else
        printf("TEST 5x5 35 FAILED\n");

    // test 5x5 36
    test_5x5_1[2][1] = 'X';
    test_5x5_1[3][0] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 13)
        successful_tests1++;
    else
        printf("TEST 5x5 36 FAILED\n");

    // test 5x5 37
    test_5x5_1[2][3] = 'X';
    test_5x5_1[3][1] = 'O';
    if (xogame(p_test_5x5_1, 5, 'X') == 14)
        successful_tests1++;
    else
        printf("TEST 5x5 37 FAILED\n");

    // test 5x5 second
    char test_5x5_2[5][5];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5_2[i][j] = ' ';

    char *p_test_5x5_2[5];
    trasform(p_test_5x5_2, *test_5x5_2, 5);

    // test 5x5 38
    test_5x5_2[2][2] = 'X';
    if (xogame(p_test_5x5_2, 5, 'O') == 0)
        successful_tests1++;
    else
        printf("TEST 5x5 38 FAILED\n");

    printf("%d / 32 TESTS 3x3 SUCCESSFUL\n", successful_tests);
    printf("%d / 40 TESTS 5x5 SUCCESSFUL\n", successful_tests1);
    return 0;
}

