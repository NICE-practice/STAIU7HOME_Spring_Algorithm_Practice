#include <stdio.h>

#define ARG 13
#define LEN_ARRAY 1000

long long sequence_game(int array[])
{
    long long number = 1;
    
    for (int i = 0; i < ARG; i++)
        number = number * array[i];
    
    long long number_additional = number;
    
    for (int i = ARG; i < LEN_ARRAY; i++)
    {
        if (array[i - ARG] == 0)
        {
            number_additional = 1;
            
            for (int j = i - (ARG - 1); j < i; j++)
                number_additional = number_additional * array[j];
        }
        else
        {
            number_additional = number_additional / array[i - ARG];
        }
        
        number_additional *= array[i];
        
        if (number_additional > number)
            number = number_additional;
    }
    
    return number;
}
