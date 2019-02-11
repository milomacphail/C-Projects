#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>



int main(void){

    string input = get_string();

    int length = strlen(input);

    //for (int first; letter < length; first++)
    //{
    //}
    printf("%c", toupper(input[0]));

    for(int letter = 0; letter<length; letter++){
       if (input[letter] == ' ' && input[letter + 1] != ' ')
       {
            printf("%c", toupper(input[letter + 1]));
    }

}
    printf("\n");
}
    //printf("Hello, %s.\n", enter );
