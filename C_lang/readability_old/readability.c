#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text:  ");
    int letters = count_letters(text);
    // printf("letters: %i\n", letters);
    int words = count_words(text);
    // printf("words: %i\n", words);
    int sentences = count_sentences(text);
    // printf("sentences:  %i \n", sentences);

    double avl = ( (double)letters / (double)words) * 100;
    // printf("%f \n", avl);
    double avs = ((double)sentences / (double)words ) * 100;
    double index = (0.0588 * avl) - (0.296 * avs) - 15.8;


    if (index < 1.0 )
    {
        printf("Before Grade 1\n");
    }
    else if ((int) round(index) >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    printf("Grade %i\n", (int) round(index));


}

int count_letters(string text)
{
    int i = 0;
    int j = 0;
    while (text[i] != '\0')
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            j++;
        }
        i++;

    }
    return j;
}

int count_words(string text)
{
    int k = 0;
    int l = 1;
    while(text[k] != '\0')
    {
        if (text[k] == ' ')
        {
            l++;
        }
        k++;
    }
     return l;
}

int count_sentences(string text)
{
    int m = 0;
    int o = 0;
    while (text[m] != '\0')
    {
        if (text[m] == '.' || text[m] == '?' || text[m] == '!')
        {
            o++;
        }
        m++;
    }
    return o;
}