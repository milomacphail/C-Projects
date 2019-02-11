///included libraries
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//Get the Key
int main(int argc, char *argv[1])
{
    if (argc != 2)
    {

        printf("Usage: ./caesar k\n");
        return 1;
    }

    int k = atoi(argv[1]);

    if (k < 0)
    {
        printf("Use an acceptable key value.\n");
        return 1;
    }

//Get the plaintext to encode
    string p = get_string("plaintext: ");

//Print cipher text at beginning of each response
    printf("ciphertext: ");
        for (int i = 0, length = strlen(p); i < length ; i++)
            {
            if (islower(p[i]))
            {

                printf("%c", (p[i] - 'a' + k) % 26 + 'a');


            }

            else if(isupper(p[i]))

            {

                printf("%c", (p[i] - 'A' + k) % 26 + 'A');


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


