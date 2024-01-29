#include "dictionary.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Valid difficulties
const char *valid_difficulties[] = {"facile", "moyen", "difficile"};
const int num_difficulties = sizeof(valid_difficulties) / sizeof(valid_difficulties[0]);

// Check if difficulty is valid
bool isValidDifficulty(const char *difficulty)
{
    for (int i = 0; i < num_difficulties; i++)
    {
        if (strcmp(difficulty, valid_difficulties[i]) == 0)
        {
            return true;
        }
    }
    return false;
}

// Parse line from dictionary file
int parseLine(const char *line, char *word, char *category, char *difficulty)
{
    return sscanf(line, "%[^,],%[^,],%[^\n]", word, category, difficulty);
}

// Read dictionary file
int readDictionary(const char *filename, Word dictionary[], int *dictionarySize)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening the file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int lineNumber = 0;
    while (fgets(line, sizeof(line), file) != NULL)
    {
        lineNumber++;

        // Skip comments
        if (line[0] == '#')
        {
            continue;
        }

        char word[MAX_WORD_LENGTH];
        char category[MAX_CATEGORY_LENGTH];
        char difficulty[MAX_DIFFICULTY_LENGTH];
        // Parse line
        if (parseLine(line, word, category, difficulty) != 3)
        {
            printf("Error on line %d : \"%s\"\n", lineNumber, line);
            continue;
        }

        // Check difficulty
        if (!isValidDifficulty(difficulty))
        {
            printf("Error on line %d : \"%s\"\n", lineNumber, line);
            continue;
        }

        // Add word to dictionary
        strcpy(dictionary[*dictionarySize].word, word);
        strcpy(dictionary[*dictionarySize].category, category);
        strcpy(dictionary[*dictionarySize].difficulty, difficulty);

        (*dictionarySize)++;
    }

    fclose(file);

    return 0;
}

// Clear dictionary
void cleanDictionary(Word dictionary[], int dictionarySize)
{
    for (int i = 0; i < dictionarySize; i++)
    {
        dictionary[i].word[0] = '\0';
        dictionary[i].category[0] = '\0';
        dictionary[i].difficulty[0] = '\0';
    }
}