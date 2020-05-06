#include "nice_num63rs.h"
#include <stdio.h>

int main(void)
{
    int successful_tests = 0;

    int result1 = numbers_game(1, 5);
    if (result1 == 60)
    {
        successful_tests++;
    }
    else
    {
        printf("Test borders failed\n");
    }

    int result2 = numbers_game(3, 3);
    if (result2 == 3)
    {
        successful_tests++;
    }
    else
    {
        printf("Test min is equal to max failed\n");
    }

    int result3 = numbers_game(10, 11);
    if (result3 == 110)
    {
        successful_tests++;
    }
    else
    {
        printf("Test min is one less than max failed\n");
    }

    int result4 = numbers_game(2, 10);
    if (result4 == 2520)
    {
        successful_tests++;
    }
    else
    {
        printf("Test usual failed\n");
    }


    printf("%d / 4 TESTS SUCCESSFUL\n", successful_tests);

    return 0;
}
