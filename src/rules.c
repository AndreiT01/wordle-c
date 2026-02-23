#include <string.h>
#include "rules.h"

void evaluate_guess(const char secret[WORD_BUF], const char guess[WORD_BUF], LetterStatus *out){
    int count[26] = {0};
    int idx;
    for (int i = 0; i < WORD_LEN; i++)
        out->states[i] = LETTER_GRAY;

    for(int i = 0; i < WORD_LEN; i++)
        if(secret[i] == guess[i])
            out->states[i] = LETTER_GREEN;
        else count[secret[i] - 'a']++;

    for(int i = 0; i < WORD_LEN; i++)
        if(out->states[i] == LETTER_GREEN)
            continue;
        else {
            idx = guess[i] - 'a';
            if(count[idx] > 0){
                out->states[i] = LETTER_YELLOW;
                count[idx]--;
            }
        }

}
