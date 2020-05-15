#include <stdio.h>

int is_in_delims(const char *str, int ch);

char *strtok(char *string, char const *delim)
{
    char *pointer = NULL;
    int i = 0;
    static char *pos = NULL;
    if (string != NULL)
        pos = string;
    for (; pos[i]; i++)
    {
        if (!is_in_delims(delim, pos[i]) && pointer == NULL)
            pointer = &pos[i];
        if (pointer != NULL && is_in_delims(delim, pos[i]))
            pos[i--] = '\0';
    }
    pos = &pos[++i];
    return pointer;
}
int is_in_delims(const char *str, int ch)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == ch)
            return 1;
    return 0;
}
