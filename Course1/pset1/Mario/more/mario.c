#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int Height = 0;
    do
    {
        Height = get_int("Please Enter the Height of the pyramid, has to be between 1 and 8\n") ;
        //printf("Height : %i\n", Height);
    }
   while ((Height < 1) || (Height >= 9)); // to get a valid user input, an integer between 1 and 8
   for (int i = 1; i <= Height ; i++)  //loop for the number of rows
   {
       for (int j = 1; j <= (Height - i); j++) // to print the whitespaces
       {
            printf(" ");
       }
       int k = i;  //to print the #
      while (k > 0)
      {
           printf("#");
           k--;

      }
        printf("  ");
      int l = i; //to print the # on the second half
      while (l > 0)
      {
          printf("#");
          l--;
      }
      printf("\n");
   }

}
