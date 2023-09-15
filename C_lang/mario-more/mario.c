#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n; // variable for Height

    do
    {
        n = get_int("Height:");
    }
    while (n < 1 || n > 8); // checking numbers comply the criteria

    for (int i = 0; i < n; i++) // gneral loop, this will print a line with the parameters and then jum in another line
    {
        for (int k = 1; k < n - i; k++) /*first we print the spaces,  initiated the k=1  variable dont print in 0 condition is n-i so it prints the number of spaces*/
        {
            printf(" ");
        }

        for (int j = 0; j <= i; j++) // loop for the firs # line, the objective is print  as many lines as the counter i, the variable j will be reseted everytime
        {
            printf("#");
        }
        printf("  ");

        for (int l = 0; l <= i; l++) // printing the second #
        {
            printf("#");
        }

        printf("\n"); // this is the jumping for line

    }
}