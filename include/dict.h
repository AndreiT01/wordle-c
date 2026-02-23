#pragma once

#include <stddef.h>
#include "config.h"

typedef struct dict {
char *words; // points to an array of words
size_t count;
size_t capacity;
}Dict;

//function to load words from file
int load_words(const char *file_name, Dict *d);

//function to inialize the dict
void init_dict(Dict *d);

//function to check if a word appears in the dictionary
int dict_contains(const Dict *d, const char *word);

//function that picks a random word
int dict_random_word(const Dict *d, char out[WORD_BUF]);

// function to free dictionary memmory
void free_dict_memory(Dict *d);


