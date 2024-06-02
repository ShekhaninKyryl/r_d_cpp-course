# Wordle Game Description

## Todo
Currently the game is not support random word. ASAP I'll add this logic and game will be coplete!

## Overview
Wordle is a word puzzle game where players try to guess a hidden five-letter word within six attempts. Each guess provides feedback in the form of colored tiles, indicating how close the guess is to the hidden word. The game has gained popularity for its simplicity and challenge.

## How to Play

### Objective
The objective of Wordle is to guess the hidden five-letter word within six attempts.

### Rules
1. **Guess the Word**: Enter a valid five-letter word as your guess.
2. **Receive Feedback**: After each guess, the game provides feedback by coloring the tiles of the guessed word:
    - **Green**: The letter is in the correct position.
    - **Yellow**: The letter is in the word but in the wrong position.
    - **Gray**: The letter is not in the word at all.

3. **Adjust Your Guesses**: Use the feedback to adjust your next guesses accordingly.
4. **Win or Lose**: You win if you guess the word within six attempts. If you don't guess the word within six attempts, you lose and the hidden word is revealed.

### Example

Suppose the hidden word is **`PLANT`**.

| Guess  | Feedback                |
|--------|-------------------------|
| CRANE  | 🟨🟨⬜⬜⬜                   |
| GLASS  | 🟩⬜🟨⬜⬜                   |
| PLANT  | 🟩🟩🟩🟩🟩 (Correct!) |

- **First Guess (`CRANE`)**: The letters `C` and `R` are not in the hidden word (`PLANT`). The letters `A` and `N` are in the word but not in the correct positions.
- **Second Guess (`GLASS`)**: The letter `G` is not in the hidden word. The letter `L` is in the correct position. The letter `A` is in the word but in the wrong position.
- **Third Guess (`PLANT`)**: All letters are in the correct positions, and the player wins the game.

### Tips and Strategies
- **Start with Common Vowels**: Begin with a word that includes common vowels (A, E, I, O, U) to identify which vowels are in the hidden word.
- **Use Process of Elimination**: Based on the feedback, eliminate letters that are not in the word and adjust your guesses to narrow down the possibilities.
- **Look for Patterns**: Pay attention to the positions of the correct letters to form potential words.

## Additional Features
- **Daily Puzzle**: Wordle offers a new hidden word puzzle every day, providing a fresh challenge each time.
- **Share Results**: After completing the puzzle, players can share their results with friends without revealing the hidden word.

## Conclusion
Wordle is an engaging and challenging word puzzle game that tests your vocabulary and deductive skills. With its simple rules and daily puzzles, it provides endless fun and a great way to start your day.

Happy guessing!
