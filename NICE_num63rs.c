#include <stdio.h>

int numbers_game(int min, int max)
{
    int number = min;
    
    for (int i = min + 1; i <= max; ++i)
    {
        int number_process = number, i_process = i;
        
        while(number_process && i_process)
        {
            if (number_process < i_process)
                i_process %= number_process;
            else
                number_process %= i_process;
        }
        
        int gcd_num_i = (number_process == 0) ? i_process : number_process;
        
        number = (number / gcd_num_i) * i;
    }
    return number;
}
