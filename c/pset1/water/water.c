#include <stdio.h>
#include <cs50.h>

int main(void){
    int minutes = get_int("Minutes:");

    {
        printf("Bottles:%i\n", (minutes * 12));
    }

}