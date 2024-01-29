#ifndef ERROR_TOOLBOX_H
#define ERROR_TOOLBOX_H

#include "dictionary.h"

#define INVALID_USAGE_ERROR 1
#define RED "\x1B[31m"
#define RESET "\x1B[0m"

void handleInvalidUsage(char *programName);

#endif // ERROR_TOOLBOX_H