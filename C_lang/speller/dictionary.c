// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO

    node *cursor = table[hash(word)];

    while(cursor != NULL)
    {
        if(strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }

        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // return toupper(word[0]) - 'A';

    int total_val = 0;
    int div_mod = 0;

    for (int i = 0;  i < strlen(word); i++)
    {
        total_val += tolower(word[i]);
    }

    div_mod = total_val % N;

    return div_mod;

}

int hash_value = 0;
int count_word = 0;

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    if (dictionary == NULL) // check argument is valid
    {
        return false;
    }

    FILE *dictionary_load = fopen(dictionary, "r"); // just loading the file in a pointer,
    if(dictionary_load == NULL)
    {
        return false; // double check to see it's valid dictionary
    }

    char *table_holder = malloc(sizeof(node)); //allocate memory for a hash table


    while (fscanf(dictionary_load, "%s", table_holder) != EOF)//load into a hash table
    {
        if(table_holder == NULL)
        {
            //free(table_holder);
            return false;
        }

        node *words = malloc(sizeof(node)); // we initiate the list

        if(words == NULL)
        {
            //free(words);
            return false;
        }

        strcpy(words->word, table_holder); // assign the value to the list

        hash_value = hash(table_holder);// global variable

        words->next = table[hash_value]; // we pass the value for next node

        table[hash_value] = words; // point again in to the beginning of the list

        count_word++; // to check later the amount of words

    }

    free(table_holder);
    fclose(dictionary_load);

    return true; // loaded successful
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (!&load)
    {
        return 0;
    }

    return count_word;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // free link list.


    for (int i = 0; i < N; i ++)
    {
        node *cursor = table[i];

        while(cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }

    }

    return true;
}
