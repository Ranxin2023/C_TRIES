#include "Tries.h"

int main()
{
    char *words[] = {"dog", "dig", "reverse", "reserve", "result", "revolution", "cat", "category"};
    int words_size = sizeof(words) / sizeof(char *);
    TRIES *t = initialize();
    for (size_t i = 0; i < words_size; i++)
    {
        insert_word(t, words[i]);
    }
    printf("whether word 'dog' exist in tries: %d\n", find_word(t, "dog"));
    printf("whether prefix 'res' exist in tries: %d\n", find_prefix(t, "res"));
    return 0;
}