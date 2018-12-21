#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    //if there are not two arguments return error
    if (argc != 2)
    {
        fprintf(stderr, "Please enter one argument");
        return 1;
    }

    //open file and create raw_file

    FILE* raw_file = fopen(argv[1], "r");

    //create buffer
    char* buffer = malloc([512]);

    //jpeg counter
    int counter = 0;

    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] &0xf0 == 0xe0)) === true;

    //read in blocks of 512 bytes, checking for jpeg opener

    fread(buffer, 1, 512, raw_file);

}