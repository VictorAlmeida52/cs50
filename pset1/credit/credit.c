#include <cs50.h>
#include <stdio.h>
#include<string.h>

int main(void)
{
    long cardNumber = 0;



    int counter = 0;
    string res;
    int sum = 0;

    // read card number
    cardNumber = get_long("Validate credit card: ");


    // multiply every other digit by 2
    // adds those products' digits together
    // and finally adds that result to the sum of the digits that weren't multiplied by 2
    long tempCardNumber = cardNumber;
    while (tempCardNumber > 0)
    {
        int lastdigit = tempCardNumber % 10;
        sum = sum + lastdigit ;
        tempCardNumber = tempCardNumber / 100;
    }
    tempCardNumber = cardNumber / 10;
    while (tempCardNumber > 0)
    {
        int secondlastdigit = (tempCardNumber % 10);
        int temp = secondlastdigit * 2;
        sum = sum + (temp % 10) + (temp / 10);
        tempCardNumber = tempCardNumber / 100;
    }

    // get the first two digit
    long init = 0, tempinit = 0;
    tempCardNumber = cardNumber;
    while (tempCardNumber)
    {
        init = tempinit;
        tempinit = tempCardNumber;
        tempCardNumber = tempCardNumber / 10;
    }

    // count
    while (cardNumber != 0)
    {
        cardNumber = cardNumber / 10;
        counter++;
    }

    // verify the checksum to make sure the card is valid
    if (sum % 10 == 0)
    {
        // verifies the type
        if (counter == 15 && (init == 34 || init == 37))
        {
            res = "AMEX\n";
        }
        else if (counter == 16 && (init >= 51 && init <= 55))
        {
            res = "MASTERCARD\n";
        }
        else if ((counter == 13 || counter == 16) && tempinit == 4)
        {
            res = "VISA\n";
        }
        else
        {
            res = "INVALID\n";
        }

    }
    else
    {
        res = "INVALID\n";
    }
    printf("%s", res);

}