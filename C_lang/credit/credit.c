#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long n; // Number credit card

    n = get_long("Number:");

    if (n > 4000000000000 && n < 5600000000000000)
    {
        long valuecomp = 1000000000000000000; // the max amount of value will work for this
        //printf("Credit card: %li \n", n);

        int gsum = 0; //general sum
        long digit = 0; // variable for extracting the digit
        int sumint = 0; // internal sum for digit extracting


        for (long i = 100;  i < valuecomp; i = i * 100) // i counter,  for make more sense, we have to remember the count is backwards
        {
            digit = (n % i) / (i / 10); // extracting digits, the las division is for extracting just the initial number of the module

            // printf(" %li\n" , digit); //extracted digit

            int digitMult = digit * 2; // the digit is multiplied

            // printf("digit multiplied: %i \n", digitMult);

            if (digitMult > 9) // separating digits when multiplied
            {
                int sumMult = 0;
                for (int j = 10 ; j <= 100; j = j * 10) // separating digits
                {
                    int dual = (digitMult % j) / (j / 10);
                    //printf("dual: %i \n", dual);

                    sumMult = sumMult + dual;

                }
                //printf("suma digits multiplied %i \n", sumMult);

                sumint = sumint + sumMult;
            }

            else
            {
                sumint = sumint + digitMult;
            }

            //printf("internal sum multiplied digits : %i \n", sumint);

        }

        // now we have to make the operation for the non multiplied digits
        int nonMul = 0;
        int sumNon = 0;

        for (long k = 10; k < valuecomp; k = k * 100)
        {
            nonMul = (n % k) / (k / 10);
            //printf("non multiplied numbers: %i \n", nonMul);

            sumNon = sumNon + nonMul;
            //printf("number non multiplied sum: %i \n", sumNon);
        }

        gsum = sumint + sumNon;
        //printf("general sum for checksum:  %i\n", gsum);

        int checksum = gsum;

        if (checksum % 10 == 0)
        {
            //printf("valid card bitch!! \n");
            // now we have to print the output corresponding to the types of cards
            if ((n > 340000000000000 && n < 350000000000000) || (n > 370000000000000 && n < 380000000000000))
            {
                printf("AMEX\n");
            }

            else if (n > 5100000000000000 && n < 5600000000000000)
            {
                printf("MASTERCARD\n");
            }
            else  if ((n > 400000000000 && n < 5000000000000) || (n > 400000000000000 && n < 5000000000000000))
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

    else
    {
        printf("INVALID\n");
    }

}