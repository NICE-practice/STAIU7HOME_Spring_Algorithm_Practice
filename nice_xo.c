#include <stdio.h>

int xogame(char **bf, const int field_size, const char symb)
{
    int arr[25];
    int my_marks = 0, enemys_marks = 0;
    int turn;

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
                if ((arr[8] == 1) && (arr[0] == 0))
                    return 0;
                if ((arr[0] == 1) && (arr[8] == 0))
                    return 8;
                if ((arr[6] == 1) && (arr[2] == 0))
                    return 2;
                if (((arr[0] == -1) && (arr[1] == -1)) || ((arr[5] == -1) && (arr[8] == -1)))
                    return 2;
                if (((arr[0] == -1) && (arr[3] == -1)) || ((arr[7] == -1) && (arr[8] == -1)))
                    return 6;
                if ((arr[0] == -1) && (arr[2] == -1))
                    return 1;
                if ((arr[0] == -1) && (arr[6] == -1))
                    return 3;
                if ((arr[2] == -1) && (arr[8] == -1))
                    return 5;
            }
            if (enemys_marks == 3)
            {
                if ((arr[2] == 1) && (arr[6] == 0))
                    return 6;
                if ((arr[2] == 0) && (arr[6] == 1))
                    return 2;
                if (((arr[2] == 1) && (arr[8] == 1) && (arr[5] == 0)) || ((arr[3] == 1) && (arr[4] == 1) && (arr[5] == 0)))
                    return 5;
                if (((arr[6] == 1) && (arr[8] == 1) && (arr[7] == 0)) || ((arr[1] == 1) && (arr[4] == 1) && (arr[7] == 0)))
                    return 7;
                if ((arr[0] == 1) && (arr[2] == 1) && (arr[1] == 0))
                    return 1;
                if (((arr[0] == 1) && (arr[6] == 1) && (arr[3] == 0)) || ((arr[4] == 1) && (arr[5] == 1) && (arr[3] == 0)))
                    return 3;

                if (arr[7] == -1)
                    return 5;
                if (arr[3] == -1)
                    return 1;
                if (arr[5] == -1)
                    return 7;
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
                        if (arr[i] == -1)
                            return (8 - i);
                    return 6;

                }
                else
                {
                    if (arr[0] + arr[1] + arr[2] == -2)
                        for (int i = 0; i < 3; i++)
                            if (arr[i] == 0)
                                return i;
                    if (arr[2] + arr[5] + arr[8] == -2)
                        for (int i = 2; i < 9; i += 3)
                            if (arr[i] == 0)
                                return i;
                    if (arr[6] + arr[7] + arr[8] == -2)
                        for (int i = 6; i < 9; i++)
                            if (arr[i] == 0)
                                return i;
                    if (arr[0] + arr[3] + arr[6] == -2)
                        for (int i = 0; i < 7; i += 3)
                            if (arr[i] == 0)
                                return i;
                    if (arr[0] + arr[2] + arr[6] + arr[8] == -2)
                        return 1;
                    return 6;
                }
            }
            else
            {
                if ((arr[0] + arr[1] + arr[2] == 2) || (arr[0] + arr[1] + arr[2] == -2))
                    for (int i = 0; i < 3; i++)
                        if (arr[i] == 0)
                            return i;
                if ((arr[2] + arr[5] + arr[8] == 2) || (arr[2] + arr[5] + arr[8] == -2))
                    for (int i = 2; i < 9; i += 3)
                        if (arr[i] == 0)
                            return i;
                if ((arr[6] + arr[7] + arr[8] == 2) || (arr[6] + arr[7] + arr[8] == -2))
                    for (int i = 6; i < 9; i++)
                        if (arr[i] == 0)
                            return i;
                if ((arr[0] + arr[3] + arr[6] == 2) || (arr[0] + arr[3] + arr[6] == -2))
                    for (int i = 0; i < 9; i += 3)
                        if (arr[i] == 0)
                            return i;
                if ((arr[0] + arr[4] + arr[8] == 2) || (arr[0] + arr[4] + arr[8] == -2))
                    for (int i = 0; i < 9; i += 4)
                        if (arr[i] == 0)
                            return i;
                if ((arr[0] + arr[4] + arr[8] == 2) || (arr[0] + arr[4] + arr[8] == -2))
                    for (int i = 0; i < 9; i += 4)
                        if (arr[i] == 0)
                            return i;
                if ((arr[2] + arr[4] + arr[6] == 2) || (arr[2] + arr[4] + arr[6] == -2))
                    for (int i = 0; i < 9; i += 4)
                        if (arr[i] == 0)
                            return i;
                for (int i = 0; i < 9; i++)
                    if (arr[i] == 0)
                        return i;
            }

        }
    }
    return 0;
}
