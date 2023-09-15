#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

/* (A,a,0,1), (B,b,1,3), (C,c,2,3), (D,d,3,2), (E,e,4,1), (F,f,5,4), (G,g,6,2), (H,h,6,4), (I,i,7,1), (J,j,8,8)
(K,k,9,5), (L,l,10,1), (M,m,11,3), (N,n,12,1), (O,o,13,1), (P,p,14,3), (Q,q,15,10), (R,r,16,1), (S,s,17,1),
(T,t,18,1), (U,u,19,1), (V,v,20,1,4), (W,w,21,4), (X,x,22,8), (Y,y,23,4), (Z,z,24,10)
*/
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
   // we need to count the letters in the word
   // the letter in the words will be the max amount

   int score = 0;
   // ascii code says A
   for (int i = 0, len = strlen(word); i < len; i++)
   {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }

        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
   }
    // TODO: Compute and return score for string
    return score;
}
