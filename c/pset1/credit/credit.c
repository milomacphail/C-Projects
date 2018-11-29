#include <stdio.h>
#include <cs50.h>

#define MCMAX16 5599999999999999
#define MCMIN16 5100000000000000

#define VMAX16 4111111111111111
#define VMIN16 4000000000000000

#define AMMAX115 379999999999999
#define AMMIN115 370000000000000

#define AMMAX215 349999999999999
#define AMMIN215 340000000000000

#define MAX13 4999999999999
#define MIN13 4000000000000

int main(void)
{
    long long card = get_long_long("Please enter a credit card number: ");
    int length = 0;
    if (card >= MCMIN16 && card <= MCMAX16)
    {
        printf("MASTERCARD\n");
        length = 16;

    }
    else if (card >= VMIN16 && card <= VMAX16)
    {
        printf("VISA\n");
        length = 16;

    }
    else if ((card >= AMMIN115 && card <= AMMAX115) || (card >= AMMIN215 && card <= AMMAX215))
    {
        printf("AMEX\n");
        length = 15;
    }
    else if (card >= MIN13 && card <= MAX13)
    {
        printf("VISA\n");
        length = 13;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
    int timesTwo = 0;
    int noTimes = 0;
    int firstDigit = 0;
    int secondDigit = 0;
    for (; length > 0; length --)
    {
        int digit = card % 10;
        //printf("Length: %i\tDigit: %i\n", length, digit);
        card = card / 10;
        if (length % 2 == 0)
        {

            int temp = digit * 2;
            timesTwo += temp % 10 + temp / 10;
        }
        else
        {
            noTimes += digit;
        }
    }
    //printf("timesTwo: %i\tnoTimes:%i\n", timesTwo, noTimes);
    int final = timesTwo + noTimes;

}

