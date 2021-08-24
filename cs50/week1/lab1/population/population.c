#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start;
    // TODO: Prompt for start size
    do
    {

        start = get_int("Enter start: ");

    }
    while (start < 9);


    // TODO: Prompt for end size
    int end;

    // TODO: Prompt for start size
    do
    {

        end = get_int("Enter end: ");

    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold

    int years = 0;
    int curr_pop = start;

    while (curr_pop < end)
    {
        start = curr_pop;
        curr_pop += (start / 3 - start / 4);
        years ++;
    }

    // TODO: Print number of years
    printf("Years: %i", years);

}