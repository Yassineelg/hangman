#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

#define MAX_WORD_LENGTH 50
#define MAX_CATEGORY_LENGTH 50
#define MAX_DIFFICULTY_LENGTH 10
#define MAX_DICTIONARY_SIZE 1000
#define MAX_LINE_LENGTH 100

typedef struct
{
    char word[MAX_WORD_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    char difficulty[MAX_DIFFICULTY_LENGTH];
} Word;

bool isValidDifficulty(const char *difficulty);
int parseLine(const char *line, char *word, char *category, char *difficulty);
int readDictionary(const char *filename, Word dictionary[], int *dictionarySize);
void cleanDictionary(Word dictionary[], int dictionarySize);

#endif // DICTIONARY_H