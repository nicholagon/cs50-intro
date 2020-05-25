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
    // printf("change: %i\n", changeInCents);
    do
    {
        if (changeInCents >= quarter)
        {
            coins = coins + (changeInCents / quarter);
            // printf("- coins: %i\n", coins);
            if (changeInCents % quarter != 0)
            {
                changeInCents = changeInCents % quarter;
            }
        }
        if (changeInCents >= dime)
        {
            coins = coins + (changeInCents / dime);
            // printf("- coins: %i\n", coins);
            if (changeInCents % dime != 0)
            {
                changeInCents = changeInCents % dime;
            }
        }
        if (changeInCents >= nickel)
        {
            coins = coins + (changeInCents / nickel);
            // printf("- coins: %i\n", coins);
            if(changeInCents % nickel != 0)
            {
                changeInCents = changeInCents % nickel;
            }
        }
        if (changeInCents >= penny)
        {
            coins = coins + (changeInCents / penny);
            // printf("- coins: %i\n", coins);
            if (changeInCents % penny != 0)
            {
                changeInCents = changeInCents % penny;
            }
        }

        // printf("changeInCents: %i, coins: %i", changeInCents, coins);
        printf("%i\n", coins);

    }
    while (remain > 0);

}
