# Terminal Wordle in C

A terminal-based clone of the popular game Wordle, written in C. 

## Features
* Classic Wordle Gameplay: You have 6 attempts to guess a randomly chosen 5-letter secret word.
* Visual Feedback: Uses terminal text formatting to indicate whether letters are in the correct spot, in the wrong spot, or not in the word at all.
* Dynamic Dictionary: Loads playable words dynamically from a text file using memory allocation.
* Robust Game Logic: Evaluates duplicate letters correctly to provide accurate hints.

## Project Structure
* src/ - Contains the C source files (main.c, dict.c, rules.c, ui.c).
* include/ - Contains the header files (config.h, dict.h, rules.h, ui.h).
* data/ - Contains words.txt, the dictionary of valid 5-letter words.
