#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    float change;
    int changeInCents;
    int coins = 0;
    int remain = 0;
    int quarter = 25, dime = 10, nickel = 5, penny = 1;

    do
    {
        change = get_float("Change owed: ");
    }
    while (change <= 0);

    changeInCents = round(change * 100);

    do
    {
        if (changeInCents >= quarter)
        {
            coins = coins + (changeInCents / quarter);

            if (changeInCents % quarter != 0)
            {
                changeInCents = changeInCents % quarter;
            }
            else
            {
                printf("%i\n", coins);
                break;
            }
        }
        if (changeInCents >= dime)
        {
            coins = coins + (changeInCents / dime);
            if (changeInCents % dime != 0)
            {
                changeInCents = changeInCents % dime;
            }
            else
            {
                printf("%i\n", coins);
                break;
            }
        }
        if (changeInCents >= nickel)
        {
            coins = coins + (changeInCents / nickel);
            if (changeInCents % nickel != 0)
            {
                changeInCents = changeInCents % nickel;
            }
            else
            {
                printf("%i\n", coins);
                break;
            }
        }
        if (changeInCents >= penny)
        {
            coins = coins + (changeInCents / penny);

            if (changeInCents % penny != 0)
            {
                changeInCents = changeInCents % penny;
            }
            else
            {
                printf("%i\n", coins);
                break;
            }
        }

    }
    while (true);

}
