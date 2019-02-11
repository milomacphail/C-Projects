// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

// Prototypes
bool check(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);

#endif // DICTIONARY_H

typedef struct node
{
    bool isWord;
    struct node *letters[27];
}
node;


// Declare a helper function for unload
void free_nodes(node *travel);

// Initialize a global node root
// and node trav, set to NULL
node *init;
node *pointer;

int get_index(char);

node *null_node(node *);