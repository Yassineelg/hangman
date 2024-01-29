#ifndef HANGMAN_H
#define HANGMAN_H

#include "dictionary.h"

void displayHangman(int errors);
char *createMaskedWord(char *wordToFind);
int checkLetterInWord(char *wordToFind, char *maskedWord, char letter);
char getLetterFromPlayer();
void checkGameResult(int errors, char *wordToFind);
int askReplay();
void displayGameStatus(int errors, char *maskedWord, char *category);
void playHangmanGame(char *wordToFind, char *category);
char *getRandomWord(Word *array, int size);
void fillTempArray(Word *dictionary, int dictionarySize, Word *tempArray, int *tempSize, char *difficulty, char *category);
void startHangmanGame(Word *dictionary, int dictionarySize, char *difficulty, char *category);

#endif