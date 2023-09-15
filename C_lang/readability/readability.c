#include <cs50.h>
#include <stdio.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    string text = get_string("Text:\n");

    int letters = count_letters(text); // variable for storing numbers of
    int words = count_words(text);
    int sentences = count_sentences(text);


    double index = 0;
    double L = 0; // average number of letters per 100 words
    double S = 0; // average number of sentences per 100 words



    L = ((double)letters / (double)words) * 100;
    S = ((double)sentences / (double)words) * 100;


    index = (0.0588 * L) - (0.296 * S) - 15.8;

    if ((int) round (index) >= 16)
    {
        printf("Grade 16+\n");
    }
    else if ((int) round (index) < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }

}

int count_letters(string text)
{
    int suml = 0;
    // we can use isupper and islower adding the ctype.h header
    // this will automate more this, but lets prettend theres no library
    // still i will compute the code here

    for (int i = 0; text[i] != '\0'; i++)
    {
        /*
        if (text[i] == isupper(text[i]) || text[i] == islower(text[i]))
        {
            suml ++;
        }
        */
       // i will use another way where i dont have the ctype library



       if((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
       {
            suml++;
       }

      /*

       if(((int)text[i] >= 65 && (int)text[i] <= 90) || (((int)text[i] >= 97 && (int)text[i] <= 122)))
       {
            suml++;
       }
       */
    }
    return suml;
}

int count_words(string text)
{
    int sumw = 1; // NOTE there's always going to be at least one word.

    /* we can asess this in two ways counting by spaces " " or with the association of decimal value
        that will mean we have to concanate the word: (int)text[i], and then comparing with the dec value
        which is 32, or also comparing the characters with the symbol of space SP
    */

   for(int j = 0; text[j] != '\0'; j++)
   {
        if (text[j] == ' ')
        {
            sumw++;
        }
   }

    return sumw;
}

int count_sentences(string text)
{
    int sums = 0;

    for(int k = 0; text[k] != '\0'; k++)
    {
        if(text[k] == '.' || text[k] == '?' || text[k] == '!')
        {
            sums++;
        }
    }

    return sums;
}
