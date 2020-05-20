#include <stdio.h>

int split(const char *string, char **matrix, const char symbol)
{
    int number = 0;
    int i = 0, col = 0;

    while (string[i])
    {
        if (string[i] == symbol)
        {
            matrix[number++][col] = '\0';
            col = 0;
        }
        else
        {
            matrix[number][col++] = string[i];
        }

        i++;
    }
    matrix[number][col] = '\0';

    return number + 1;
}
