#include<stdio.h>
#include<cs50.h>
#include<string.h>


int main(void){

    string enter = get_string("Please enter your name below: ");

    int length = strlen(enter);

    //for (int first; letter < length; first++)
    //{
    //}

    if (enter[0] != ' ')
    {
    for(int letter = 0; letter<length; letter++){
        if (enter[letter] == ' '){
            if (letter + 1 < length && enter[letter + 1] != ' ')
            {
                printf("This is %c%c.", enter[0], enter[letter + 1]);
            }
        }
    }
    //printf("Hello, %s.\n", enter );

}

}