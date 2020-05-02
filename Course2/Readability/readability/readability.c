#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void index(float L, float S);           // function to calculate the grade
void counter(string text, int arr[]);  // function for counting the number of letters, words and sentences

int main(void)
{
    float avg_lpw, avg_spw;  // average number of letters per 100 words and aberage number of sentnces per 100 words
    int arr[] = {0, 1, 0};

    string text = get_string("Please input your text here : \n");
    counter(text, arr);

    avg_lpw = (arr[0]) * 100 / (arr[1]) ;
    avg_spw = (arr[2]) * 100 / (arr[1]) ;

    index(avg_lpw, avg_spw) ;


}

void index(float L, float S)
{
    float Grade = 0.0588 * L - 0.296 * S - 15.8;
    Grade = round(Grade) ;

    if (Grade < 1)
    {
        printf("Before Grade 1\n");
    }

    if ((Grade >= 1) && (Grade < 16))
    {
        printf("Grade %.0f\n", Grade);
    }

    if (Grade >= 16)
    {
        printf("Grade 16+\n");
    }


}

void counter(string text, int arr[])                //array argument is passed to enable return of multiple values
{
    int num_l = 0, num_wrds = 1, num_sent = 0;

    for (int i = 0; i < strlen(text); i++) // to count number of words, letters and sentences
    {
        if ((islower(text[i])) || (isupper(text[i]))) // condition for counting the number of letters
        {
            num_l += 1 ;
        }

        if (isspace(text[i]) || ((text[i] == 39) && (text[i - 1] == 73))) //condition for counting the number of words
        {
            num_wrds += 1 ;
        }

        if ((text[i] == 33) || (text[i] == 46) || (text[i] == 63)) // condition for counting the number of sentences
        {
            num_sent += 1 ;
        }
    }
    arr[0] = num_l;
    arr[1] = num_wrds;
    arr[2] = num_sent;
}