#include <stdio.h>
#include <cs50.h>
#include<math.h>

//initialize counter
int main(void)
{
float change;
do
{
    change=get_float("Need change for?: ");
}
while (change <= 0);

//change float to int
int money = round(change * 100);

int counter = 0;

while (money >= 25)
{
    money -= 25;
    counter ++;
};
while (money < 25 && money >= 10)
{
    money -= 10;
    counter ++;
};
while (money < 10 && money >= 5)
{
    money -= 5;
    counter ++;
};
while (money > 0)
{
    money -= 1;
    counter ++;
};

printf("%i\n", counter);
}
