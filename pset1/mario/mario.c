//included resources
#include <stdio.h>
#include <cs50.h>

//main function
int main(void)
{
int n;

do
{
    n = get_int("Enter height: ");
}
while (n < 0 || n > 23);
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n -1 - i; j++)

            {
                printf(" ");
            }
        for (int k = 0; k < i+2; k++)
        {
        printf("#");
        }
    printf("\n");
    }
}
