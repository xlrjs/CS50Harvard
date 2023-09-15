#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // TODO: Prompt for start size

    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    // TODO: Prompt for end size

    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold

    int years = 0;

    if (end == start)
    {
        years = 0;
    }
    else
    {
        int population = start;

        for (years = 0; population < end; years++)
        {
            population = population + (population / 3) - (population / 4);
            //printf("%i/n", population);
        }


    }
    // TODO: Print number of years

    printf("Years: %i\n", years);
}
