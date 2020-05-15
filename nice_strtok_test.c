#include <stdio.h>
#include "nice_strtok.h"

int main(void)
{
    int successful_tests = 0;
    char const delim[] = "\n ,.!?";
    int check_i;
    char *pword;

    // Test 1
    char str_test_1[] = "   Iu7game..,developers are??,\nthe\nbest!!!!";
    int check_pword_1[] = { 3, 13, 24, 31, 35};
    check_i = 0;
    
    pword = strtok(str_test_1, delim);
    while (pword)
    {
        if (*pword == str_test_1[check_pword_1[check_i]])
            successful_tests++;
        else
            printf("Test 1_%d failed\n", check_i);

        pword = strtok(NULL, delim);
        check_i++;
    }

    // Test 2
    char str_test_2[] = "\n   \n....\n,,,,\n?.!";
    
    pword = strtok(str_test_2, delim);
    
    if (pword == NULL)
        successful_tests++;
    else
        printf("Test 2_0 faild\n");

    // Test 3
    char str_test_3[] = "";
    
    pword = strtok(str_test_3, delim);
    if (pword == NULL)
        successful_tests++;
    else
        printf("Test 3_0 faild\n");


    printf("%d / 7 TESTS SUCCESSFUL\n", successful_tests);

        return 0;
}
