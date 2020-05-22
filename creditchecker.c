#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
    long long card;
    int numlength;
    int finallength;
// the variables for powered 10, ex. scope12 = 10^12
    long long scope12;
    long long scope13;
    long long scope14;
    long long scope15;
    long long scope16;
//when extracted the digit of the number we need to hold it and if number >= 10, we need to split it on digits again
    int tempnum;
    int tempnum1;
    int tempnum2;
//how many digits in number - card
    int numberofdigits;
    int i;
    int number1 = 0;
    int number2 = 0;
//modulo of different card lenghts, ex. res16 in case card has 16 digits, res16 = card % scope16
    long long res16;
    long long res15;
    long long res14;
    long long res13;
    long long res12;
//totalsum used for checking if the last digit is 0
    int totalsum = 0;
//simple way of powering 10
    scope12 = pow(10, 12);
    scope13 = pow(10, 13);
    scope14 = pow(10, 14);
    scope15 = pow(10, 15);
    scope16 = pow(10, 16);
//getting the card and checking if it's within the scope
    card = get_long_long("enter the card number: ");
    if ((card % scope12 == card) || ((card > scope16) || (card % scope14 == card)))
    {
        printf("INVALID\n");
        exit(0);
    }
// getting the length of the card and defining the type
    numberofdigits = floor(log10(card)) + 1;
    res16 = card % scope16;
    res15 = card % scope15;
    res14 = card % scope14;
    res13 = card % scope13;
    res12 = card % scope12;
// case when number has 16 digits 
    if (numberofdigits == 16)
    {
        res16 = res16 - res15;
        res16 = res16 / scope15;
        res15 = res15 - res14;
        res15 = res15 / scope14;

        if ((res16 == 5) && ((res15 >= 1) && (res15 <= 5)))
        {
            char typecard[] = "MASTERCARD";
            printf("MASTERCARD\n");
        }
        else if (res16 == 4)
        {
            char typecard[] = "VISA";
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
            exit(0);
        }

    }
// case when number has 15 digits
    else if (numberofdigits == 15)
    {
        res15 = res15 - res14;
        res15 = res15 / scope14;
        res14 = res14 - res13;
        res14 = res14 / scope13;
        if ((res15 == 3) && ((res14 == 4) || (res14 == 7)))
        {
            char typecard[] = "AMEX";
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
            exit(0);
        }

    }
// case when the card has 13 digits
    else if (numberofdigits == 13)
    {
        res13 = res13 - res12;
        res13 = res13 / scope12;
        if (res13 == 4)
        {
            char typecard[] = "VISA";
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
            exit(0);
        }
    }
// for the first number from the end
    for (i = 1; i <= numberofdigits; i += 2)
    {
        number1 = number1 + (floor((card % (long long int)(pow(10, i))) / (pow(10, (i - 1)))));
    }
// for the second number from the end
    for (i = 2; i <= numberofdigits; i += 2)
    {
        tempnum = (2 * (floor((card % (long long int)(pow(10, i))) / (pow(10, (i - 1))))));
// if the bumber is decimal, split it on several numbers and get the result
        if (tempnum >= 10)
        {
            tempnum1 = (tempnum % 10);
            tempnum2 = ((tempnum % 100) - tempnum1) / 10;
            number2 = number2 + tempnum1 + tempnum2;
        }
        else
        {
            number2 = number2 + tempnum;
        }

    }
// getting the total sum of the card and checking if it has 0 as the last number
    totalsum = number2 + number1;
    if ((totalsum % 10) == 0)
    {
        return 0;
    }

    else
    {
        printf("INVALID\n");
        exit(0);
    }
}