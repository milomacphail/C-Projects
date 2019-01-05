#include<stdio.h>
#include<cs50.h>
#include<string.h>

int main (void)
{
    int result = compareStrings("this", "that");
    printf("%i", result);

}


int compareStrings (char* str1, char* str2)
{

for (int i = 0; i < str1; i++)
{

        int result = ((str1[i] - 'a') % 26 + 'a') - ((str2[i] -'a') % 26 + 'a');
        printf("%i ", result);
}
    return 1;
}




