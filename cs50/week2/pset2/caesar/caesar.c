#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// prototypes
// prototypes
// prototypes
// prototypes
// prototypes
// prototypes


void change_string(string text, long num);
char change_char(char ch, long num);

int main(int argc, string argv[])
{

    if (argc == 2)
    {
        long num = atoi(argv[1]);
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        change_string(plaintext, num);

    }

    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

// change full text

void change_string(string text, long num)
{

    for (int i = 0; text[i] != '\0'; i++)
    {
        char new_char = change_char(text[i], num);
        printf("%c", new_char);

    }
    printf("\n");

}

// change char

char change_char(char ch, long num)
{
    if (ch >= 'A' && ch <= 'Z')
    {

        ch = ((int) ch + num - 65) % 26;
        char c = ch + 65;
        return c;

    }

    else if (ch >= 'a' && ch <= 'z')
    {

        ch = ((int) ch + num - 97) % 26;
        char c = ch + 97;
        return c;

    }

    else
    {
        return ch;
    }
}