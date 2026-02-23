#include "dict.h"
#include "rules.h"
#include "ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main(){
    Dict d;
    init_dict(&d);
    if(load_words(WORDS_FILE, &d) == 0){
        return 0;
    }

    srand(time(NULL));

    while (1){

    

    char answer[WORD_BUF];
    if (dict_random_word(&d, answer) == 0){
        printf("ERROR: cannot pick a random word from an empty list of words\n");
        return 0;
    }

    char guess[WORD_BUF];
    int attempts = 0;
    int won = 0;

    while(attempts < 6){
        printf("attempt %d : ", attempts);
        scanf("%5s", guess);

        for (int i = 0; i < WORD_LEN; i++){
            if(guess[i] <= 'Z' && guess[i] >= 'A')
                guess[i] += 32;
        }

        if(dict_contains(&d, guess) == 0){
            printf("ERROR: the guessed word isn'n available, try another\n");
            continue;
        }else{
            LetterStatus outStatus;
            evaluate_guess(answer, guess, &outStatus);
            print_color_result(guess, &outStatus);

            int correct = 1;
            for(int i = 0; i < WORD_LEN; i++)
                if(outStatus.states[i] != LETTER_GREEN)
                    correct = 0;

            attempts++;

            if (correct == 1){
                won = 1;
                printf("Correct answer!\n");
                break;
            }
        }
    }
    if (won == 0)
    printf("You lost! The correct answer was: %s\n", answer);

    printf("Press Enter to play again or ESC to exit \n");
    int key = _getch();

    if(key == 27) //esckey ascii
    break;

    }

    free_dict_memory(&d);
    return 0;
}