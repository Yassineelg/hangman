#ifndef HANGMAN_H
#define HANGMAN_H

#include "dictionary.h"

char *getRandomWord(Word *array, int size);
void fillTempArray(Word *dictionary, int dictionarySize, Word *tempArray, int *tempSize, char *difficulty, char *category);
char *startHangmanGame(Word *dictionary, int dictionarySize, char *difficulty, char *category);

#endif