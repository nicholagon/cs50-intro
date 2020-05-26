#include <stdio.h>
#include <cs50.h>

int main(void)
{
    bool prevIsTarget = false;
    int totalSum = 0, tempSum = 0;
    long prev = 1, max = 10000000000000000;
    long input = get_long("Number: ");

    for (long i = 10; i <= max; i *= 10)
    {
        if (i == 10 || prevIsTarget == true)
        {
            tempSum = tempSum + ((input % i) / prev);
            prevIsTarget = false;
        }
        else if (prevIsTarget == false)
        {
            int temp = ((input % i) / prev) * 2;
            if (temp >= 10)
            {
                totalSum = totalSum + ((temp / 10) + (temp % 10));
            }
            else
            {
                totalSum = totalSum + temp;
            }
            prevIsTarget = true;
            prev = i;
        }
        prev = i;
    }
    if (0 == (tempSum + totalSum) % 10)
    {
        if ((4 == (input / 1000000000000000)) || (4 == (input / 1000000000000)))
        {
            printf("VISA\n");
        }
        else if (((input / 100000000000000) > 50) && ((input / 100000000000000) < 56))
        {
            printf("MASTERCARD\n");
        }
        else if ((34 == (input / 10000000000000)) || (37 == (input / 10000000000000)))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}