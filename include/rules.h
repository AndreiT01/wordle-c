#pragma once

#include "config.h"

typedef enum {
    LETTER_GRAY,
    LETTER_YELLOW,
    LETTER_GREEN
}State;

typedef struct LetterStatus{
    State states[WORD_LEN];

}LetterStatus;

void evaluate_guess(const char secret[WORD_BUF], const char guess[WORD_BUF], LetterStatus *out);