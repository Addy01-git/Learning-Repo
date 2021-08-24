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
// prototypes
// prototypes
// prototypes
// prototypes
// prototypes
// prototypes


void change_string(string text, string code);
char change_char(char ch, string code);
bool check_code(string code);

int main(int argc, string argv[])
{
    string code = argv[1];
    if (argc == 2 && strlen(code) == 26)
    {
        if (!check_code(code))
        {
            return 1;
        }
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        change_string(plaintext, code);

    }

    else if (argc == 2)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }

    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

void change_string(string text, string code)
{

    for (int i = 0; text[i] != '\0'; i++)
    {
        char ch = change_char(text[i], code);
        printf("%c", ch);
    }
    printf("\n");
}


char change_char(char ch, string code)
{

    if (ch >= 'A' && ch <= 'Z')
    {
        for (int i = 0; code[i] != '\0'; i++)
        {
            code[i] = toupper(code[i]);
        }
        int c = (int) ch - 65;
        return code[c];
    }

    else if (ch >= 'a' && ch <= 'z')
    {
        for (int i = 0; code[i] != '\0'; i++)
        {
            code[i] = tolower(code[i]);
        }
        int c = (int) ch - 97;
        return code[c];
    }

    else
    {
        return ch;
    }
}

bool check_code(string code)
{
    int check_array[26] = { [ 0 ... 25 ] = 0 };
    for (int i = 0; code[i] != '\0'; i++)
    {
        if (!isalpha(code[i]))
        {
            return false;
        }
        code[i] = tolower(code[i]);
    }

    for (int i = 0; code[i] != '\0'; i++)
    {
        int index = (int) code[i] - 97;
        if (check_array[index] == 1)
        {
            return false;
        }

        else
        {
            check_array[index] = 1;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        printf("%i", check_array[i]);
    }

    return true;
}