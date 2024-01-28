# Compiler and linker configuration
CC = gcc
CFLAGS = -Wall -Werror -g
LDFLAGS = -lncurses

# Directories for source and object files
SRC_DIR = src
OBJ_DIR = obj

# Source and object files
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Executable name
EXEC = hangman

# Phony targets
.PHONY: all clean fclean run re ascii_art_loading

# Default target to build the executable and display loading effect
all: ascii_art_loading $(EXEC)

# ASCII Art display and Loading Effect
ascii_art_loading:
	@echo "\033[1;35m"
	@echo "     _   _                                         🎭"
	@echo "    | | | | __ _ _ __   __ _ _ __ ___   __ _ _ __   "
	@echo "    | |_| |/ _\` | '_ \\ / _\` | '_ \` _ \\ / _\` | '_ \\  "
	@echo "    |  _  | (_| | | | | (_| | | | | | | (_| | | | | "
	@echo "    |_| |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_| "
	@echo "                       |___/                        "
	@echo "\033[1;36m"
	@echo -n "Compiling"
	@for i in 1 2 3; do \
		echo -n "."; \
		sleep 1; \
	done

# Rule to compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Target to build the executable
$(EXEC): $(OBJECTS)
	@$(CC) $(LDFLAGS) $^ -o $@
	@echo "\n\033[1;32mCompilation Completed Successfully!\033[0m"

# Target to run the executable
run: $(EXEC)
	@./$(EXEC)

# Target to clean up objects
clean:
	@echo "\033[1;36mCleaning up objects...\033[0m"
	@rm -f $(OBJ_DIR)/*.o
	@echo "\033[1;36mClean up completed!\033[0m"

# Target to clean up objects and the executable
fclean: clean
	@echo "\033[1;36mCleaning up executable...\033[0m"
	@rm -f $(EXEC)
	@echo "\033[1;36mFull clean up completed!\033[0m"

# Target to clean and rebuild the project
re: fclean all