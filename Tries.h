#ifndef TRIES_H
#define TRIES_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct _TRIES
{
    // char character;
    int end;
    size_t idx_length;
    size_t *idxs;
    struct _TRIES *children[128];
} TRIES;

TRIES *initialize();
void insert_word(TRIES *trie, size_t i, char *word);
int find_word(TRIES *trie, char *word);
int find_prefix(TRIES *trie, char *prefix);
size_t *all_idx_with_word(TRIES *trie, char *word, size_t *result_length);
void free_tries(TRIES *trie);
#endif