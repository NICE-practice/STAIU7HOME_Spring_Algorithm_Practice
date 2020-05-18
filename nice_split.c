#include <stdio.h>

int split(const char *string, char **matrix, const char symbol)
{
    int number = 0;
    int i = 0, k = 0;

    while (string[i])
    {
        if (string[i] != symbol)
        {
            matrix[number][k] = string[i];
            k++;
        }
        else if ((string[i] == symbol) && (i != 0) && (string[i - 1] != symbol))
        {
            matrix[number][k] = '\0';
            number++;
            k = 0;
        }

        i++;
    }

    if ((string[i - 1] != symbol) && (i != 0))
        number++;

    return number;
}
