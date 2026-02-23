#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "dict.h"
#include <time.h>

void init_dict(Dict *d){
    d->words = NULL;
    d->count = 0;
    d->capacity = 0;
}

static int validate_word(char *word){
    size_t len = strlen(word);
    while(len > 0 && (word[len -1] == '\n' || word[len - 1] == '\r')){
        word[len - 1] = '\0';
        len--;
    }

    if (len!=5){
        return 0;
    }

    while(len > 0){
        if(word[len -1] >= 'a' && word[len - 1] <= 'z'){
            len --;
            continue;
        }
        return 0;
    }
    return 1;
}

int load_words(const char *file_name, Dict *d){

    FILE *fptr = fopen(file_name, "r");

    if (fptr == NULL){
        printf("Error: Could not open file\n");
        return 0;
    }
    if (d->capacity == 0){
        d->capacity = 64;
        d->words = malloc(d->capacity * WORD_BUF);

        if(d->words == NULL){
            printf("Error: Memory allocation failed\n");
            fclose(fptr);
            return 0;
        }
    }
    char buffer[WORD_BUF + 2];

    while (1){
        if (fgets(buffer, WORD_BUF + 2, fptr) == NULL)
            break;
        
        if (d->capacity == d->count){
            d->capacity *= 2;
            char *temp = realloc(d->words, d->capacity * WORD_BUF);

        if(temp == NULL){
            printf("Error: Memory reallocation failed, keeping only current words\n");
            fclose(fptr);
            return d->count>0;
        }

        d->words = temp;
        }

        if(validate_word(buffer)){
            strcpy(d->words + d->count * WORD_BUF, buffer);
            d->count++;
        } 
        
    }
    
    fclose(fptr);
    return d->count>0;
}

int dict_contains(const Dict *d, const char *word){
    size_t c = d->count;
    for (size_t i = 0; i < c; i++){
    char *temp = d->words + i * WORD_BUF;
    if( strcmp(word,temp) == 0)
        return 1;
    }
    return 0 ;
}

int dict_random_word(const Dict *d, char out[WORD_BUF]){
    if (d->count == 0)
        return 0;

    size_t r = rand() % d->count;
    strcpy(out, d->words + r *WORD_BUF);
    return 1;
}


void free_dict_memory (Dict *d){

    if (d == NULL){
        return;
    }

    free(d->words);
    d->words = NULL;
    d->count = 0;
    d->capacity = 0;
}

