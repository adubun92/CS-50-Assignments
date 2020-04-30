#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    float dollars;
    do
    {
       dollars = get_float("Input the amount of change you are owed\n");
    }
    while (dollars < 0.0); // check a valid input

    int num_coins = 0;
    int cents = round(dollars * 100);
    //cents = cents % 100;

    if (cents >= 25)
    {
        num_coins = num_coins + floor(cents / 25);
        cents = cents % 25;
    }
    if ((cents >= 10) && (cents < 25))
    {
        num_coins = num_coins + floor(cents / 10);
        cents = cents % 10;
    }
    if ((cents >= 5) && (cents < 10))
    {
        num_coins = num_coins + floor(cents / 5);
        cents = cents % 5;
    }
    num_coins = num_coins + cents;
    printf("%i\n", num_coins);
}