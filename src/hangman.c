#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "hangman.h"

// Function to display the hangman depending on the number of errors
void displayHangman(int errors)
{
    printf("\n  +---+\n  |   |\n");
    switch (errors)
    {
    case 6:
        printf("  |   O\n  |  /|\\\n  |  / \\\n");
        break;
    case 5:
        printf("  |   O\n  |  /|\\\n  |  /\n");
        break;
    case 4:
        printf("  |   O\n  |  /|\\\n");
        break;
    case 3:
        printf("  |   O\n  |  /|\n");
        break;
    case 2:
        printf("  |   O\n  |   |\n");
        break;
    case 1:
        printf("  |   O\n");
        break;
    default:
        printf("  |\n  |\n");
        break;
    }
    printf("__|__\n\n");
}

// Function to create the masked word
char *createMaskedWord(char *wordToFind)
{
    char *maskedWord = malloc(strlen(wordToFind) + 1);
    for (int i = 0; i < strlen(wordToFind); i++)
    {
        if (i == 0 || i == strlen(wordToFind) - 1 || wordToFind[i] == wordToFind[0] || wordToFind[i] == wordToFind[strlen(wordToFind) - 1])
        {
            maskedWord[i] = wordToFind[i];
        }
        else if (isalpha(wordToFind[i]))
        {
            maskedWord[i] = '*';
        }
        else
        {
            maskedWord[i] = wordToFind[i];
        }
    }
    maskedWord[strlen(wordToFind)] = '\0';
    return maskedWord;
}

// Function to check if the letter is in the word
int checkLetterInWord(char *wordToFind, char *maskedWord, char letter)
{
    int found = 0;
    for (int i = 0; i < strlen(wordToFind); i++)
    {
        if (wordToFind[i] == letter)
        {
            maskedWord[i] = letter;
            found = 1;
        }
    }
    return found;
}

// Function to get the letter from the player
char getLetterFromPlayer()
{
    char input[100];
    printf("Entrer une lettre : ");
    fgets(input, sizeof(input), stdin);
    return input[0];
}

// Function to check if the player won or lost
void checkGameResult(int errors, char *wordToFind)
{
    if (errors == 6)
    {
        displayHangman(errors);
        printf("Vous avez perdu ! Le mot était : %s\n", wordToFind);
    }
    else
    {
        displayHangman(errors);
        printf("Vous avez gagné ! Le mot était : %s\n", wordToFind);
    }
}

// Function to ask the player if he wants to replay
int askReplay()
{
    char replay[2];
    printf("Voulez-vous rejouer ? (Y/N) ");
    fgets(replay, 2, stdin);
    // Consume the newline character
    char tmp;
    while ((tmp = getchar()) != '\n' && tmp != EOF)
        ;
    return (replay[0] == 'Y' || replay[0] == 'y');
}

// Function to display the game status
void displayGameStatus(int errors, char *maskedWord, char *category)
{
    displayHangman(errors);
    printf("Mot à trouver : %s\n", maskedWord);
    printf("Catégorie : %s\n", category);
}

// Function to play the hangman game
void playHangmanGame(char *wordToFind, char *category)
{
    char *maskedWord = createMaskedWord(wordToFind);
    int errors = 0;
    while (errors < 6 && strcmp(wordToFind, maskedWord) != 0)
    {
        displayGameStatus(errors, maskedWord, category);
        char letter = getLetterFromPlayer();
        if (!checkLetterInWord(wordToFind, maskedWord, letter))
        {
            errors++;
        }
    }
    checkGameResult(errors, wordToFind);
    free(maskedWord);
}

// Function to get a random word from an array
char *getRandomWord(Word *array, int size)
{
    return array[rand() % size].word;
}

// Function to fill the temp array
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

// Function to start the hangman game
void startHangmanGame(Word *dictionary, int dictionarySize, char *difficulty, char *category)
{
    do
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

        playHangmanGame(wordToFind, category);
        free(tempArray);
    } while (askReplay());
}