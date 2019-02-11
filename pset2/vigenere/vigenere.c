//included libraries
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>





//Get the Key
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }

    string key = (argv[1]);
    int keyLength = strlen(key);
    int keyCode = 0;
    for (int j = 0; j < keyLength; j++)
    if (!isalpha(key[j]))
            {
                printf("Keys may only use letters. Use an acceptable key value.\n");
                return 1;
            }

//Get the plaintext to encode
    string p = get_string("plaintext: ");

//Print cipher text at beginning of each response
    printf("ciphertext: ");
        for (int i = 0, length = strlen(p) ; i < length ; i++)
            {
            if (islower(p[i]))
            {
                printf("%c", (p[i] - 'a' + tolower(key[keyCode]) - 'a') % 26 + 'a');
                keyCode = (keyCode + 1) % keyLength;

            }

            else if(isupper(p[i]))

            {
                printf("%c", (p[i] - 'A' + toupper(key[keyCode]) - 'A') % 26 + 'A');
                keyCode = (keyCode + 1) % keyLength;

            }
            else

            {
                printf("%c", p[i]);
            }

        }

    //Print the ciphertext/exit program
    printf("\n");
    return 0;
}
//Cipher code c[i] = (p[i-'a' + k)% 26+ 'a' || "A";



