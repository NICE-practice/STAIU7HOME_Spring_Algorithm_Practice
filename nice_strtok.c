#include <stdio.h>

char *strtok(char *string, char const *delim)
{
    char *pointer = NULL;
    int i = 0, k;
    static char *pos = NULL;

    if (string != NULL)
        pos = string;
    for (; pos[i]; i++)
    {
        k = 0;
        for (int j = 0; !k && delim[j]; j++)
            if (delim[j] == pos[i])
                k = 1;
        if (!k && pointer == NULL)
            pointer = &pos[i];
        if (k && pointer != NULL)
            pos[i--] = '\0';
    }
    pos = &pos[i + 1];
    return pointer;
}
