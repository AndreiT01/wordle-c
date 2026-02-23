#include "ui.h"
#include <stdio.h>

#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void print_color_result(const char *guess, LetterStatus *in){
    for(int i  = 0; i < WORD_LEN; i++){
        //gray
        if(in->states[i] == LETTER_GRAY){
            printf("%s%c%s", ANSI_COLOR_RESET, guess[i], ANSI_COLOR_RESET);
        }else if(in->states[i] == LETTER_YELLOW){
            printf("%s%c%s", ANSI_COLOR_YELLOW, guess[i], ANSI_COLOR_RESET);
        } else if(in->states[i] == LETTER_GREEN){
            printf("%s%c%s", ANSI_COLOR_GREEN, guess[i], ANSI_COLOR_RESET);
        }
    }
    printf("\n");
}
