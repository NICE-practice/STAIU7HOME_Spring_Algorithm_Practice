#include <stdio.h>
#include "nice_split.h"

void trasform(char **a, char *buf, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = buf + n * i;
    }
}

int main(void)
{
    int correct = 0;

    const char str_test_1[] = "  A   b c  ";
    const char str_test_2[] = "llAllbllcll";
    const char str_test_3[] = "   tes     ";
    const char str_test_4[] = "???";
    const char str_test_5[] = "";

    char d[5][5] = { 0 };
    char *matrix[5];

    trasform(matrix, *d, 5);

    //Test1 with 3 words and separator ' '
    if (split(str_test_1, matrix, ' ') == 3 &&
            matrix[0][0] == 'A' && matrix[1][0] == 'b' && matrix[2][0] == 'c')
        correct++;
    else
        printf("Test 1 failed\n");

    //Test2 with 3 words and separator 'l'
    if (split(str_test_2, matrix, 'l') == 3 &&
            matrix[0][0] == 'A' && matrix[1][0] == 'b' && matrix[2][0] == 'c')
        correct++;
    else
        printf("Test 2 failed\n");

    //Test3 with only one word and separator ' '
    if (split(str_test_3, matrix, 'l') == 3 &&
            matrix[0][0] == 't' && matrix[0][1] == 'e' && matrix[0][2] == 's' && matrix[0][3] == '\0')
        correct++;
    else
        printf("Test 3 failed\n");

    //Test4 with no words and separator '?'
    if (split(str_test_4, matrix, '?') == 0)
        correct++;
    else
        printf("Test 4 failed\n");

    //Test5 with empty string
    if (split(str_test_5, matrix, ' ') == 0)
        correct++;
    else
        printf("Test 5 failed\n");

    printf("%d / 5 TESTS SUCCESSFUL\n", correct);

    return 0;
}
