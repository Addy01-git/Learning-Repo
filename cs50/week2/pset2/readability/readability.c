#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// prototype
// prototype
// prototype
// prototype
// prototype
// prototype
// prototype
// prototype
// prototype
// prototype

float calc(string str);

int main(void)
{
    string str = get_string("Text: ");
    float grade = calc(str);

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }

    else if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }

    else
    {
        printf("Grade %d\n", (int) round(grade));
    }
}

float calc(string str)
{
    int letters = 0;
    int words = 0;
    int sentences = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            letters++;
        }

        else if ((str[i] == '!') || (str[i] == '?') || (str[i] == '.'))
        {
            sentences++;
        }

        else if (str[i] == ' ')
        {
            words++;
        }
    }

    words += 1;

    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;

    return 0.0588 * L - 0.296 * S - 15.8;

}


