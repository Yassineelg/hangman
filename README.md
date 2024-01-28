<div align="center">
  <img src="https://media.giphy.com/media/3o6Mb6zsfA7xoL6S2I/giphy.gif" alt="Hangman Game GIF" width="100%" height="250">
  <h1>🎮 Hangman Game in C</h1>
  <p>A Challenging Terminal-Based Hangman Game</p>

  [![GitHub License](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT)
</div>

## 📜 Table of Contents

- [🚀 Introduction](#-introduction)
- [✨ Features](#-features)
- [🛠️ Installation](#%EF%B8%8F-installation)
- [🔥 Usage](#-usage)
- [🤝 Contributing](#-contributing)
- [📝 License](#-license)

## 🚀 Introduction

Welcome to the Hangman Game in C! This is a terminal-based hangman game that offers a blend of challenge and fun. It runs smoothly on both Windows and Linux, providing a unique adventure set in an enchanted forest theme.

## ✨ Features

- 🌟 Multiple difficulty levels: Easy, Medium, and Hard
- 📚 Extensive word categories for diverse gameplay
- 🖥️ Cross-platform compatibility for Windows and Linux
- 🌐 Online gameplay option for playing with friends
- 📈 Player score tracking and leaderboard
- 🕹️ Interactive interface using Ncurses library
- 🔒 Secure gameplay with minimal memory leaks
- 🎯 Bonus features including word suggestion and score tracking

## 🛠️ Installation

**Prerequisites:**
- GCC Compiler
- `libncurses` library
- GNU Make

**Steps:**
1. Clone the repository to your local machine.
2. Ensure `libncurses` and `gcc` are installed on your system.
3. Navigate to the project directory and run `make` to compile the game using the Makefile.

Understood. Let's enhance the Usage section to provide more details about the commands available with `./hangman`. Here's the revised section:

---

## 🔥 Usage

**Launching the Game:**
- To start the game, run `./hangman` in your terminal.

**Available Commands:**
- `./hangman`: Starts the game with default settings.
- `./hangman [options]`: Launch the game with specified options.
  - `[dictionary_file]`: Specify a custom dictionary file for word selection.
  - `[difficulty]`: Choose between Easy, Medium, or Hard difficulty levels.
  - `[category]`: Select a specific word category for gameplay.

**Gameplay Instructions:**
- Once the game starts, you will be prompted to guess letters to reveal the word.
- The game tracks your guesses and updates the hangman drawing accordingly.
- You can also view your current score and progress during gameplay.

Remember to consult the help command inside the game for more detailed instructions on gameplay and options.

## 🤝 Contributing

Contributions are welcome! Feel free to fork the repository, make changes, and submit pull requests. Please adhere to the code of conduct and contribute to improving the game.

## 📝 License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.