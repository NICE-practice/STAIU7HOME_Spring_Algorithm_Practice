#include "nice_7equeence.h"
#include <stdio.h>

int main(void)
{
    int successful_tests = 0;

    int array[1000] = { 0 };
    long long result1 = sequence_game(array);
    if (result1 == 0)
    {
        successful_tests++;
    }
    else
    {
        printf("Test zeroes failed\n");
    }

    for (int i = 0; i < 13; i++)
        array[i] = -1;
    long long result2 = sequence_game(array);
    if (result2 == 0)
    {
        successful_tests++;
    }
    else
    {
        printf("Test zeroes against negative failed\n");
    }

    for (int i = 13; i < 1000; i++)
        array[1] = 1;
    long long result3 = sequence_game(array);
    if (result3 == 1)
    {
        successful_tests++;
    }
    else
    {
        printf("Test positive against negative failed\n");
    }

    array[0] = -2;
    for (int i = 1; i < 1000; i++)
        array[i] = -1;
    long long result4 = sequence_game(array);
    if (result4 == -1)
    {
        successful_tests++;
    }
    else
    {
        printf("Test only negative failed\n");
    }

    for (int i = 0; i < 1000; i++)
        array[i] *= -1;
    long long result5 = sequence_game(array);
    if (result5 == 2)
    {
        successful_tests++;
    }
    else
    {
        printf("Test only positive failed\n");
    }

    for (int i = 0; i < 1000; i++)
    {
        if (i % 2)
            array[i] = -3;
        else
            array[i] = 3;
    }
    long long result6 = sequence_game(array);
    if (result6 == 1594323)
    {
        successful_tests++;
    }
    else
    {
        printf("Test alternating failed\n");
    }

    printf("%d / 6 TESTS SUCCESSFUL\n", successful_tests);
    return 0;
}
