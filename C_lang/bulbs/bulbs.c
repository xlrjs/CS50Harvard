#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8; // whats this for?? still not get it

void print_bulb(int bit);

int main(void)
{
    // TODO
    string Message = get_string("Message: ");

    // create message into decimal
    // we have to separate characters of the message
    for (int i = 0; Message[i] != '\0'; i++)
    {
        // we have to define here the decimal conversion
        int decc = 0;

        decc = (int)Message[i]; // decimal conversion

        int bin[] = {0, 0, 0, 0, 0, 0, 0, 0}; // array for translating to binary

        //printf("Decimal: %i\n", decc);

        for (int j = 7; j >= 0; j--) // function to allocate the on bulbs on reverse
        {

            if (decc % 2 == 1) // allocating on bulbs
            {
                bin[j] = 1;
            }

            decc = decc / 2;

        }

        for (int k = 0; k < 8 ; k++) // printing bulbs in good way
        {
            print_bulb(bin[k]);
        }

        printf("\n"); // good

    }

}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
