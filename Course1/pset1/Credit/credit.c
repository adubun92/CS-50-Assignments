#include <stdio.h>
#include <cs50.h>
int main()
{
long int num, temp;
int digit_count = 0;

do
{
  num = get_long("Credit card Number:\n");
}
while (num < 0); // to get a valid input
temp = num;
while (temp != 0) // to get the number of digits
{
    temp /= 10;
    digit_count ++;
}

printf("The number of digits in the credit card is: %i\n", digit_count);
}

