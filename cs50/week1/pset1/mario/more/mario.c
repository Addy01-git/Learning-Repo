#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int n;

    do
    {

        n = get_int("Height: ");

    }
    while (!(n <= 8 && n >= 1));


    int space = n - 1;

    // outer loop

    for (int i = 0; i < n; i++)
    {

        // inner loop

        for (int j = 0; j < n; j++)
        {
            if (i + j >= n - 1)
            {
                // print #

                printf("#");

            }
            else
            {
                // print nothing

                printf(" ");
            }

        }

        printf("  ");

        for (int j = 0; j < n; j++)
        {
            if (i >= j)
            {
                printf("#");
            }

        }
        printf("\n");
    }

}