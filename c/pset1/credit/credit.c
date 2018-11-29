#include <stdio.h>
#include <cs50.h>

#define MAX16 5599999999999999
#define MIN16 4000000000000000

#define MAX15 379999999999999
#define MIN15 340000000000000

#define MAX13 4999999999999
#define MIN13 4000000000000

int main (void)
{
    long long card = get_long_long("Please enter a credit card number: ");
    printf("%lld\n", card);
    int length = 0;
    if (card >= MIN16 && card <= MAX16)
    {
        printf("Card may be Visa or MasterCard.\n");
        length = 16;
    }
    else if (card >= MIN15 && card <= MAX15)
    {
        printf("Card may be AMEX\n");
        length = 15;
    }
    else if (card >= MIN13 && card <= MAX13)
    {
        printf("Card may be VISA\n");
        length = 13;
    }
    else {
        printf("INVALID CARD\n");
        return 0;
    }
    int timesTwo = 0;
    int noTimes = 0;
    int final = 0;

    for (; length > 0; length --)
    {
        int digit = card % 10;
        printf("Length: %i\tDigit: %i\n", length, digit);
        card = card/10;
        if (length%2 == 0)
        {
            int temp = digit *2;
            timesTwo += temp % 10 + temp /10;
        }
        else
        {
            noTimes += digit;
        }
    }
    printf("timesTwo: %i\tnoTimes:%i\n", timesTwo, noTimes);
}

