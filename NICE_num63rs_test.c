#include "NICE_num63rs.h"

int main(void)
{
    int test_border_1_5_60 = numbers_game(1, 5);
    if (test_border_1_5_60 == 60)
        printf("Test 1: succes\n");
    else
        printf("Test 1: fail\n");

    int test_min_isequal_max_3_3_3 = numbers_game(3, 3);
    if (test_min_isequal_max_3_3_3 == 3)
        printf("Test 2: succes\n");
    else
        printf("Test 2: fail\n");

    int test_min_is1less_max_10_11_110 = numbers_game(10, 11);
    if (test_min_is1less_max_10_11_110 == 110)
        printf("Test 3: succes\n");
    else
        printf("Test 3: fail\n");

    int test_usual_1_10_2520 = numbers_game(1, 10);
    if (test_usual_1_10_2520 == 2520)
        printf("Test 4: succes\n");
    else
        printf("Test 4: fail\n");
    return 0;
}
