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

    //create raw_file
    FILE* raw_file = fopen(argv[1], "r");

    //if file doesn't exist, return NULL
     if (raw_file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 1;
    }

    //create outfile
    FILE* image = NULL;

    //create buffer
    unsigned char buffer [512];

    //set flag to indicate if image is found
    bool isImage = false;

    //jpeg counter
    int counter = 0;

    //create jpgarray
    char jpgName[10];

    //read in blocks of 512 bytes, checking for jpeg opener
    while (fread(buffer, 512, 1, raw_file) == 1)
    {
    //check if we are at start of jpeg
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
            if(isImage == true)
            {
              fclose(image);
            }

            else
            {
                isImage = true;
            }

            // Write to outfile and increment counter for jpeg
            sprintf(jpgName, "%03i.jpg", counter);
            image = fopen(jpgName, "w");
            counter++;
    }

            if (isImage == true)
            {
                fwrite(&buffer, 512, 1, image);
            }

    }

      fclose(raw_file);
      fclose(image);
      return 0;
}
