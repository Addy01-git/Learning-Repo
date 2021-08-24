#include <stdio.h>
#include <cs50.h>
#include <math.h>

float calc(void);

int main(void)
{
    int change = calc();

    // storing values of each coin * 100

    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    // counter for how many coins are used

    int quarter_used = 0;
    int dime_used = 0;
    int nickel_used = 0;
    int penny_used = 0;

    quarter_used = change / quarter;
    change = change % quarter;

    dime_used = change / dime;
    change = change % dime;

    nickel_used = change / nickel;
    change = change % nickel;

    penny_used = change / penny;

    int coins = quarter_used + dime_used + nickel_used + penny_used;
    printf("%d\n", coins);
}

// function to get amount
// and change to int

float calc(void)
{

    float num;

    do
    {
        num = get_float("Change owed: ");
    }
    while (num <= 0);

    // change to int

    return round(num * 100);
}