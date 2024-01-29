#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "hangman.h"

// Returns a random word from the array
char *getRandomWord(Word *array, int size)
{
    return array[rand() % size].word;
}

// Fills tempArray with words matching the difficulty and category
void fillTempArray(Word *dictionary, int dictionarySize, Word *tempArray, int *tempSize, char *difficulty, char *category)
{
    for (int i = 0; i < dictionarySize; i++)
    {
        if ((strcmp(dictionary[i].difficulty, difficulty) == 0) &&
            (category[0] == '\0' || strcmp(dictionary[i].category, category) == 0))
        {
            tempArray[(*tempSize)++] = dictionary[i];
        }
    }
}

// Starts the hangman game and returns the word to find
char *startHangmanGame(Word *dictionary, int dictionarySize, char *difficulty, char *category)
{
    srand(time(0));

    Word *tempArray = malloc(sizeof(Word) * dictionarySize);
    int tempSize = 0;
    char *wordToFind;

    if (difficulty[0] == '\0' && category[0] == '\0')
    {
        wordToFind = getRandomWord(dictionary, dictionarySize);
    }
    else
    {
        fillTempArray(dictionary, dictionarySize, tempArray, &tempSize, difficulty, category);

        if (tempSize == 0)
        {
            fprintf(stderr, "No words found that match the criteria.: %s, %s\n", difficulty, category ? category : "");
            exit(1);
        }
        else
        {
            wordToFind = getRandomWord(tempArray, tempSize);
        }
    }

    free(tempArray);
    return wordToFind;
}