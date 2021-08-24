#include <stdio.h>
#include <cs50.h>
#include <math.h>

long get_card_no(void);
void check_card(long, int);
int get_len(long);

// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment


int main(void)
{

    long num = get_card_no();
    int len = get_len(num);
    check_card(num, len);
}

long get_card_no(void)
{

    long num;
    do
    {
        num = get_long("Number: ");
    }
    while (num < 1000000000);
    return num;
}


void check_card(long num, int len)
{

    long copy = num;
    int arr[len];
    int flag = 0;
    int sum1 = 0;
    int sum2 = 0;

    for (int i = 0; (i < len) && (copy != 0); i++)
    {

        int digit = copy % 10;
        copy = copy / 10;
        arr[len - i - 1] = digit;
    }

    for (int i = len - 2; i >= 0; i -= 2)
    {

        int sum0 = 0;
        if (2 * arr[i] > 9)
        {
            sum1 += (2 * arr[i]) % 10 + (2 * arr[i]) / 10;
        }
        else
        {
            sum1 += 2 * arr[i];
        }
    }


    for (int i = len - 1; i >= 0; i -= 2)
    {
        sum2 += arr[i];
    }

    int res = (sum1 + sum2);

    if (res % 10 == 0)
    {
        flag = 1;
    }

    if ((flag == 1) && (arr[0] == 4) && ((len == 16) || (len == 13)))
    {
        printf("VISA\n");
    }

    else if ((flag == 1) && arr[0] == 5 && arr[1] >= 1 && arr[1] <= 5 && len == 16)
    {
        printf("MASTERCARD\n");
    }

    else if ((flag == 1) && arr[0] == 3 && (arr[1] == 4 || arr[1] == 7) && len == 15)
    {
        printf("AMEX\n");
    }

    else
    {
        printf("INVALID\n");
    }
}

int get_len(long num)
{

    return log10(num) + 1;
}