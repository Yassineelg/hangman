#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"
#include "error_toolbox.h"
#include "hangman.h"

#define DEFAULT_DICTIONARY "default_dictionary.csv"
#define INVALID_FILE_ERROR 1

int main(int argc, char *argv[])
{
    char *dictionaryFilename;
    char *difficulty;
    char *category = NULL;
    Word dictionary[MAX_DICTIONARY_SIZE];
    int dictionarySize = 0;

    // Handle command line arguments
    switch (argc)
    {
    case 1:
        // Default settings
        dictionaryFilename = DEFAULT_DICTIONARY;
        break;
    case 3:
    case 4:
        // User-provided settings
        dictionaryFilename = argv[1];

        if (argc >= 3)
        {
            difficulty = argv[2];
        }

        if (argc == 4)
        {
            category = argv[3];
        }
        break;
    default:
        // Invalid usage
        handleInvalidUsage(argv[0]);
    }

    // Read dictionary file
    if (readDictionary(dictionaryFilename, dictionary, &dictionarySize))
    {
        fprintf(stderr, "%s : invalid file.\n", dictionaryFilename);
        return INVALID_FILE_ERROR;
    }

    // Start game
    startHangmanGame(dictionary, dictionarySize, difficulty, category);

    // Clean dictionary
    cleanDictionary(dictionary, dictionarySize);

    return 0;
}