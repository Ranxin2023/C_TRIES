#ifndef TRIES_H
#define TRIES_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct _TRIES
{
    // char character;
    int end;
    struct _TRIES *children[128];
} TRIES;

TRIES *initialize();
void insert_word(TRIES *trie, char *word);
int find_word(TRIES *trie, char *word);
int find_prefix(TRIES *trie, char *prefix);
#endif