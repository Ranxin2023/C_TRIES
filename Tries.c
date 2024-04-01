#include "Tries.h"
TRIES *initialize()
{
    TRIES *t = malloc(sizeof(TRIES));
    // t->character = c;
    t->end = 0;
    t->idxs = NULL;
    t->idx_length = 0;
    memset(t->children, 0, sizeof(t->children));
    return t;
}

void insert_word(TRIES *trie, size_t idx, char *word)
{
    TRIES *t = trie;
    size_t word_length = strlen(word);
    for (size_t i = 0; i < word_length; i++)
    {
        if (t->children[(int)word[i]] == NULL)
        {
            t->children[(int)word[i]] = initialize(word[i]);
        }
        t = t->children[(int)word[i]];
    }
    t->end = 1;
    if (t->idx_length == 0)
    {
        t->idxs = malloc(sizeof(size_t));
    }
    else
    {
        t->idxs = (size_t *)realloc(t->idxs, sizeof(size_t) * (t->idx_length + 1));
    }
    t->idxs[t->idx_length] = idx;
    t->idx_length += 1;
}

int find_word(TRIES *trie, char *word)
{
    TRIES *t = trie;
    size_t word_length = strlen(word);
    for (size_t i = 0; i < word_length; i++)
    {
        if (t->children[(int)word[i]] == NULL)
        {
            return 0;
        }
        t = t->children[(int)word[i]];
    }
    return t->end;
}

int find_prefix(TRIES *trie, char *prefix)
{
    TRIES *t = trie;
    size_t prefix_length = strlen(prefix);
    for (size_t i = 0; i < prefix_length; i++)
    {
        if (t->children[(int)prefix[i]] == NULL)
        {
            return 0;
        }
        t = t->children[(int)prefix[i]];
    }
    return 1;
}

size_t *all_idx_with_word(TRIES *trie, char *word, size_t *result_length)
{
    TRIES *t = trie;
    size_t word_length = strlen(word);
    for (size_t i = 0; i < word_length; i++)
    {
        if (t->children[(int)word[i]] == NULL)
        {
            return 0;
        }
        t = t->children[(int)word[i]];
    }
    *result_length = t->idx_length;
    return t->idxs;
}

void free_tries(TRIES *trie)
{
    if (trie == NULL)
    {
        return;
    }
    for (size_t i = 0; i < 128; i++)
    {
        free_tries(trie->children[i]);
    }
    free(trie->idxs);
    // free(trie->children);
    free(trie);
}