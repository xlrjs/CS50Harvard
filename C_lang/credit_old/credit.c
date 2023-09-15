#include <cs50.h>
#include <stdio.h>
#include <math.h>
int main(void) 
{
    long n; // the variable for the credit card number

    do 
    {
        n = get_long("Number:"); // prompt for asking the number
    } 
    
    while (n < 4000000000000 || n > 5600000000000000); // conditional to avoid other numbers
    long def = 100000000000000000; // the max amount of characters, also the lenght of digits
    long m = n % 100000000000000000; // just to check credit numbers
     //printf("%li\n",m); // tocheck

    long c; // counter for forLoop  to define the times will go through the function
    int sum = 0; // initial sum
    for (c = 100; c < def;) // for loop
    {
        long op = n % c;
         //printf("%li\n",op);

        int opi = op / (c / 10); // operation to extrac just the requiered digit
         //printf("%i\n",opi); // to check
        int op2 = opi * 2; // to start the first part of algorithm where every other digit multiplies by 2
            if (op2 > 9) // conditional in the sum of the algorithm
            {   
                int sumi = 0; // internal sum if conditional is true
                for (int c1 = 10; c1 < 101;) // loop for add the internal condition
                {
                    int inl = op2 % c1;
                    int op3 = inl / (c1 / 10);
                    sumi = sumi + op3; // internal sum rewrited
                    c1 = c1 * 10;
                }
                sum = sum + sumi;
            }
            else
            {
                sum = sum + op2; // sum while condition is not true
            }
         //printf("suma: %i\n",sum); // to check
        c = c * 10 * 10; // this is the counter who actually jumps every other digit by 2
    }//exit loop for every other digit by 2

    long c3;
    int sum1 = 0;
    for (c3 = 10; c3 < def;) // second loop for numbers not multiplied by 2
    {
        long op4 = n % c3;
        int opi2 = op4 / (c3 / 10);
        sum1 = sum1 + opi2;
        c3 = c3 * 10 * 10;
    }
     //printf("suma part2 %i\n",sum1); // to check

    int checksum = 0;
    checksum = sum + sum1;

     //printf("sumatotal %i\n", checksum); // to check the function


    if (checksum % 10 == 0)
    {
        //amex
        if ((n > 340000000000000 && n < 350000000000000) || (n > 370000000000000 && n < 380000000000000))
        {
            printf("AMEX\n");
        }
        
        else if (n > 5100000000000000 && n < 5600000000000000)
        {
            printf("MASTERCARD\n");
        }
        else if ((n > 4000000000000 && n < 5000000000000) || (n > 4000000000000000 && n < 5000000000000000))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}