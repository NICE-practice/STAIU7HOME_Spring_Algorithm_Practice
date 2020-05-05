int numbers_game(int min, int max)
{
    int number = min;
    for (int i = min + 1; i < max; ++i)
    {
        int numer_process = number, i_process = i;
        while(numer_process && i_process)
            if (numer_process < i_process)
                i_process %= numer_process;
            else
                numer_process %= i_process;
        int k = (numer_process == 0) ? i_process : numer_process;
        number = (number / k) * i;
    }
    return number;
}
