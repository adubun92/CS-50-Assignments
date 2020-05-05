#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void Encrypt(int key, string text);


int main(int argc, string argv[])

{
    if (argc != 2)  //to check there is only one command line input
    {
        printf("Usage: %s\n", argv[0]);
        return 1;
    }
    else 
    {
        for (int i = 0; i < strlen(argv[1]); i++)  //check the key input at command line is a valid digit input
        {
            if (isdigit(argv[1][i]))
            {
                continue;
            }
            else
            {
                printf("Usage: %s\n", argv[0]);
                return 1;
            }
        }
        //printf("succes\n");
        printf("%s\n", argv[1]);
        string ptext = get_string("plain text\n");
        int key;
        key = atoi(argv[1]);
        Encrypt(key, ptext);
        //return 0;
    }

}

void Encrypt(int key, string text) //function to cipher the input
{
    int n = strlen(text);
    int c[n];

    for (int i = 0; i < n; i++)
    {
        if (islower(text[i]))      //if letter is small letter
        {
            c[i] = (text[i] + key % 26);
            if (c[i] > 122)
            {
                c[i] = c[i] - 26;
            }
        }
        else if (isupper(text[i]))  //if letter is capital letter
        {
            c[i] = (text[i] + key % 26);
            if (c[i] > 90)
            {
                c[i] = c[i] - 26;
            }
        }
        else  // if letter is not an alphabet
        {
            c[i] = text[i];
        }
    }
    //c[n] = "/0";
    printf("plaintext: %s \n", text);
    printf("ciphertext: ");
    for (int j = 0; j < n ; j++)
    {
        printf("%c", c[j]);
    }
    printf("\n");
}