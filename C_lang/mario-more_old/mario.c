#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height:");

    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {

        for (int j = 1; j < n - i; j++)
        {
            printf(" ");

        }

        printf("#");

        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        printf("  ");

        for (int l = -1; l < i; l++)
        {
            printf("#");

        }

        printf("\n");


    }
}