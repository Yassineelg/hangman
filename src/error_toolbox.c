#include <stdio.h>
#include <stdlib.h>
#include "error_toolbox.h"

void handleInvalidUsage(char *programName)
{
    fprintf(stderr, RED "Utilisation: ./%s [fichier_dictionnaire.csv] [facile/moyen/difficile] <category>\n" RESET, programName);
    fprintf(stderr, RED "fichier_dictionsnaire.csv : fichier contenant les mots, leur difficulté et leur catégorie (optionnel)\n" RESET);
    fprintf(stderr, RED "facile/moyen/difficile : difficulté du mot à trouver (optionnel)\n" RESET);
    fprintf(stderr, RED "category : catégorie du mot à trouver (optionnel)\n" RESET);
    exit(INVALID_USAGE_ERROR);
}