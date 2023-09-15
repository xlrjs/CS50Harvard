#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // first three bytes of JPEGs are  0xff 0xd8 0xff
    // the fourth byte, can be any of: 0xe0, 0xe1 0xe2... 0xef.  the fourth byte's fist four bits are 1110
    // the start of a JPEG demarks the end of the previous
    // cameras are FAT file systems, whose "block size" is 512 bytes  512B
    // blocks = round((int) photosize / 512) if photosize is an odd number still will use the same space as an even
    // this space is call "slack space" this is used for forensic

    // accept ecactly one command-line argument
    // if not executed with one command-line remind the user the correct usage, main should return 1
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    //open memory card
    FILE *file_input = fopen(argv[1], "r"); // file is the var name of the card
    if (file_input == NULL)                   // if file couldn't be open
    {
        printf("Could not open %s.\n", argv[1]); // this could be like printf("Could not open %s.\n", filename); if we define filename as char *filename = arv[1];
        return 1;
    }

    //Allocate memory for the file
    BYTE buffer[512];

    int count = 0;

    FILE *image_output = NULL;

    char (*image_name) = malloc(8 * sizeof(char));

    // itirate over all the file
    while(fread(buffer, 1, 512, file_input)) // this will iterate until EOF
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count > 0)
            {
                fclose(image_output);
            }

            sprintf(image_name, "%03i.jpg", count);

            image_output = fopen(image_name, "w");

            count ++;
        }

        if (image_output != NULL)
        {
            fwrite(buffer, 1, 512, image_output);
        }

    }
    free(image_name);
    fclose(image_output);
    fclose(file_input);

    return 0;
}