// Implements a dictionary's functionality                                                                                          // Ways to improve processing time
                                                                                                                                    // Check for prefixes when loading the dictionary
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

// To count the number of words
// being entered in dictionary
unsigned int wordCount = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // To hold the index for current letter
    int index = 0;

    // To count number of misspelled words
    int misspelled = 0;

    // Set trav node pointing to root node
    // These nodes were declared globally
    pointer = init;

    // For every char in the word
    for (int i = 0; i < strlen(word); i++)
    {
        // Get the index for each letter
        index = get_index(word[i]);

        // If the pointer to children at a certain index is NULL
        if (pointer -> letters[index] == NULL)
        {
            // Increment misspelled_words
            misspelled++;

            // Return false exit loop
            return false;
        }
        else
        {
            // Move pointer to next letter
            pointer = pointer -> letters[index];
        }
    }

    // If the pointer to is_word is
    // true, return true to signify
    // the word is in the dictionary
    if (pointer -> isWord)
        return true;

    // Exit function
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open the dictionary file, assign to dict
    FILE *dict = fopen(dictionary, "r");

    // If dict is NULL
    if (dict == NULL)
    {
        // Print error message
        printf("Could not load dictionary\n");

        // Return false upon
        // failed load attempt
        return false;
    }

    // To hold the index for current letter
    int index = 0;

    // A variable to store each
    // char being read in
    char c;

    // Create a root node with a pointer
    init = null_node(pointer);
    pointer = init;

    // Iterate through dictionary to load every word
    while(true)
    {

        c = fgetc(dict);

        // Get index of c
       index = get_index(c);

        // While the end of the word is not being pointed to
        if (c != '\n')
        {
            // If the end of file is reached
            if (feof(dict))
            {
                // Set the pointer to is_word to true
                pointer -> isWord = true;

                // Close the dict file
                fclose(dict);

                // Return true upon successful load
                return true;
            }

            // Make sure the position is
            // between 0 and 26, inclusively
            if(index >= 0 && index <= 26)
            {
                // If the children node @ alpha_index is empty
                if (pointer -> letters[index] == NULL)
                {
                    // malloc a new children node
                    pointer -> letters[index] = null_node(pointer -> letters[index]);
                }

                    // Move pointer to next node
                    pointer = pointer -> letters[index];
            }
        }

        // End of word is reached
        else
        {
            // printf("finished word\n"); set pointer to true
            pointer -> isWord = true;

            // Increment num_words
            wordCount++;

            // Set the trav pointer
            // back to the root node
            pointer = init;
        }
    }

    // If there's an error reading
    // the dictionary
    if (ferror(dict))
    {
        // Close file
        fclose(dict);
        printf("Error reading\n");
        return false;
    }

    // Close file
    fclose(dict);

    // Return true upon
    // loading of dict
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // If the dictionary was loaded,
    // return number of words
    if (&load)
        return wordCount;
    else
        return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Call the free_nodes function
    // to free all malloc'd node
    free_nodes(init);
    return true;
}

// A void function that accepts a node pointer
// A helper function for unload
void free_nodes(node *node_pointer)
{
    // For every node pointer in children
    for (int i = 0; i < 27; i++)
    {
        // If the pointer to letters @ i is not NULL, call the free_nodes function
        if (node_pointer -> letters[i])
            free_nodes(node_pointer -> letters[i]);
    }

    // Free the travel pointer
    free(node_pointer);
}

// Find the position for the letter
// in the children node. Accepts a
// char and returns an int.
int get_index(char c)
{
    // Return the index based on char
    if (c >= 'a' && c <= 'z')
         return c - 'a';
    else if(c >= 'A' && c<= 'Z')
         return c - 'A';
    else
        return 26;
}

// A function that creates and initializes to
// NULL the 27 pointers in the node children
// Accepts and returns a node pointer
node *null_node(node *node_ptr)
{
    node_ptr = malloc(sizeof(node));
    // If the pointer is NULL, return NULL
    if (node_ptr == NULL)
        return NULL;

    // For every node in children, set to NULL
    for (int i = 0; i < 27; i++)
        node_ptr -> letters[i] = NULL;

    // Set isWord to false
    node_ptr -> isWord = false;

    // Return the node that was just created
    return node_ptr;
}