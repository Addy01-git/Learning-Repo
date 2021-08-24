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

    for (int i = 0; i < n; i++)
    {
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

        // goes to next line

        printf("\n");
    }

}