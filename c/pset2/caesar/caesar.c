//include
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

//key
int key(int argc, string argv[1])
{
    //reject inputs with anything other than two arguments
    if (argc != 2)
    {
        return 1;
        printf("Usage: ./caesar k");
    }
    else if
    {

    //ask user for plaintext input
       printf("plaintext: ");
        string plaintext =  get_string();
        int cipherShift = atoi(argv[1]);

       for (int i = 0, i < strlen(plaintext); i++)
        {
            cipherText = ("%c", plaintext[i] + cipherShift);
            printf(cipherText);
        }
    else
    {
        cipherText
    }
    return cipherText[i] = plaintext[i];
    }
}