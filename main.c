#include "Tries.h"

int main()
{
    char *words[] = {"dog", "dig", "reverse", "cat", "reserve", "result", "revolution", "cat", "category"};
    int words_size = sizeof(words) / sizeof(char *);
    TRIES *t = initialize();
    for (size_t i = 0; i < words_size; i++)
    {
        insert_word(t, i, words[i]);
    }
    printf("whether word 'dog' exist in tries: %d\n", find_word(t, "dog"));
    printf("whether prefix 'res' exist in tries: %d\n", find_prefix(t, "res"));
    size_t result_length = 0;
    size_t *idx_of_cat = all_idx_with_word(t, "cat", &result_length);
    printf("All indexs of cat are:\n");
    for (size_t i = 0; i < result_length; i++)
    {
        printf("%lld\t", idx_of_cat[i]);
    }
    return 0;
}