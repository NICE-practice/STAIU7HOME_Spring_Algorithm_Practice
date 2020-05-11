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
                    //крестики только по углам
                    if ((arr[0] == 1) || (arr[2] == 1) || (arr[6] == 1) || (arr[8] == 1))
                        return 1;
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
    int successful_tests = 0;
    char test_3x3_1[3][3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3_1[i][j] = ' ';

    char *p_test_3x3_1[3];
    trasform(p_test_3x3_1, *test_3x3_1, 3);
    // test 1
    if (xogame(p_test_3x3_1, 3, 'X') == 4)
        successful_tests++;
    else
        printf("TEST 1 FAILED\n");
    // test 2
    test_3x3_1[1][1] = 'X';
    test_3x3_1[0][0] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 6)
        successful_tests++;
    else
        printf("TEST 2 FAILED\n");
    // test 3
    test_3x3_1[2][0] = 'X';
    test_3x3_1[0][2] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 1)
        successful_tests++;
    else
        printf("TEST 3 FAILED\n");
    // test 4
    test_3x3_1[0][1] = 'X';
    test_3x3_1[2][1] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 5)
        successful_tests++;
    else
        printf("TEST 4 FAILED\n");
    // test 5
    test_3x3_1[1][2] = 'X';
    test_3x3_1[2][2] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 3)
        successful_tests++;
    else
        printf("TEST 5 FAILED\n");

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3_1[i][j] = ' ';
    // test 6
    test_3x3_1[1][1] = 'X';
    test_3x3_1[2][0] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 8)
        successful_tests++;
    else
        printf("TEST 6 FAILED\n");
    // test 7
    test_3x3_1[2][2] = 'X';
    test_3x3_1[0][0] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 3)
        successful_tests++;
    else
        printf("TEST 7 FAILED\n");
    // test 8
    test_3x3_1[1][0] = 'X';
    test_3x3_1[1][2] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 1)
        successful_tests++;
    else
        printf("TEST 8 FAILED\n");
    // test 9
    test_3x3_1[0][1] = 'X';
    test_3x3_1[2][1] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 2)
        successful_tests++;
    else
        printf("TEST 9 FAILED\n");

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3_1[i][j] = ' ';
    // test 10
    test_3x3_1[1][1] = 'X';
    test_3x3_1[1][2] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 0)
        successful_tests++;
    else
        printf("TEST 10 FAILED\n");
    // test 11
    test_3x3_1[0][0] = 'X';
    test_3x3_1[2][2] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 2)
        successful_tests++;
    else
        printf("TEST 11 FAILED\n");
    // test 12
    test_3x3_1[0][2] = 'X';
    test_3x3_1[0][1] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 6)
        successful_tests++;
    else
        printf("TEST 12 FAILED\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3_1[i][j] = ' ';
    // test 13
    test_3x3_1[1][1] = 'X';
    test_3x3_1[0][1] = 'O';
    test_3x3_1[0][0] = 'X';
    test_3x3_1[2][1] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 8)
        successful_tests++;
    else
        printf("TEST 13 FAILED\n");
    // test 14
    test_3x3_1[1][1] = 'X';
    test_3x3_1[0][0] = 'O';
    test_3x3_1[2][0] = 'X';
    test_3x3_1[0][2] = 'O';
    test_3x3_1[2][2] = 'X';
    test_3x3_1[1][2] = 'O';
    if (xogame(p_test_3x3_1, 3, 'X') == 7)
        successful_tests++;
    else
        printf("TEST 14 FAILED\n %d",xogame(p_test_3x3_1, 3, 'X'));//!!!!!
    char test_3x3_2[3][3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3_2[i][j] = ' ';

    char *p_test_3x3_2[3];
    trasform(p_test_3x3_2, *test_3x3_2, 3);
    // test 13
    test_3x3_2[1][0] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 4)
        successful_tests++;
    else
        printf("TEST 15 FAILED\n");
    // tsst 14
    test_3x3_2[1][1] = 'O';
    test_3x3_2[1][2] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 6)
        successful_tests++;
    else
        printf("TEST 16 FAILED\n");
    // test 15
    test_3x3_2[2][0] = 'O';
    test_3x3_2[0][2] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 8)
        successful_tests++;
    else
        printf("TEST 17 FAILED\n");
    // test 16
    test_3x3_2[2][2] = 'O';
    test_3x3_2[0][0] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 7)
        successful_tests++;
    else
        printf("TEST 18 FAILED\n");

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3_2[i][j] = ' ';
    // test 17
    test_3x3_2[1][1] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 0)
        successful_tests++;
    else
        printf("TEST 19 FAILED\n");
    // test 18
    test_3x3_2[0][0] = 'O';
    test_3x3_2[2][2] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 6)
        successful_tests++;
    else
        printf("TEST 20 FAILED\n");
    // test 19
    test_3x3_2[2][0] = 'O';
    test_3x3_2[1][0] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 5)
        successful_tests++;
    else
        printf("TEST 21 FAILED\n");
    // test 20
    test_3x3_2[1][2] = 'O';
    test_3x3_2[0][1] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 7)
        successful_tests++;
    else
        printf("TEST 22 FAILED\n");

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3_2[i][j] = ' ';
    // test 21
    test_3x3_2[1][1] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 0)
        successful_tests++;
    else
        printf("TEST 23 FAILED\n");
    // test 22
    test_3x3_2[0][0] = 'O';
    test_3x3_2[2][0] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 2)
        successful_tests++;
    else
        printf("TEST 24 FAILED\n");
    // test 23
    test_3x3_2[0][2] = 'O';
    test_3x3_2[0][1] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 7)
        successful_tests++;
    else
        printf("TEST 25 FAILED\n");
    // test 24
    test_3x3_2[2][1] = 'O';
    test_3x3_2[1][0] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 5)
        successful_tests++;
    else
        printf("TEST 26 FAILED\n");

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3_2[i][j] = ' ';
    // test 25
    test_3x3_2[0][0] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 4)
        successful_tests++;
    else
        printf("TEST 27 FAILED\n");
    // test 26
    test_3x3_2[1][1] = 'O';
    test_3x3_2[2][0] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 3)
        successful_tests++;
    else
        printf("TEST 28 FAILED\n");
    // test 27
    test_3x3_2[1][0] = 'O';
    test_3x3_2[1][2] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 1)
        successful_tests++;
    else
        printf("TEST 29 FAILED\n");
    // test 28
    test_3x3_2[0][1] = 'O';
    test_3x3_2[2][1] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 8)
        successful_tests++;
    else
        printf("TEST 30 FAILED");

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3_2[i][j] = ' ';
    // test 31
    test_3x3_2[0][0] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 4)
        successful_tests++;
    else
        printf("TEST 31 FAILED\n");
    // test 32
    test_3x3_2[1][1] = 'O';
    test_3x3_2[0][2] = 'X';
    if (xogame(p_test_3x3_2, 3, 'O') == 1)
        successful_tests++;
    else
        printf("TEST 32 FAILED");

    printf("%d / 32 TESTS SUCCESSFUL\n", successful_tests);
    return 0;
}


