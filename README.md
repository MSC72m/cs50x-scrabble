# Scrabble Scoring

## Project Description
This project is a solution to a CS50x problem set that involves calculating the Scrabble score of words entered by two players. The program assigns points to each letter and computes the total score for each player's word, then determines the winner or if there is a tie.

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Code Explanation](#code-explanation)


## Installation
No special installation is required for this project.

## Usage
To compile and run the project, use the following commands:


make scrabble
./scrabble
You will be prompted to enter words for Player 1 and Player 2, and the program will output the winner or if there is a tie.

## Code Explanation
Points Array

``` C
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
```
#include <cs50.h>, #include <ctype.h>, #include <stdio.h>, and #include <string.h> include the necessary libraries for CS50 functions, character type functions, standard input/output functions, and string handling functions respectively.
int POINTS[] is an array that holds the point values assigned to each letter of the alphabet based on Scrabble scoring rules.
Function Prototypes

``` C 
int compute_score(string word);
```
int compute_score(string word); is the prototype for the function that calculates the score of a given word.
Main Function

``` C
int main(void)
{
    // Prompt the user for two words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    // Calculate each player's score
    int player_one = compute_score(word1);
    int player_two = compute_score(word2);

    // Status of the game
    if (player_one < player_two)
    {
        printf("Player 2 wins\n");
    }
    else if (player_two < player_one)
    {
        printf("Player 1 wins\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
```
string word1 = get_string("Player 1: "); prompts Player 1 to enter a word and stores it in word1.
string word2 = get_string("Player 2: "); prompts Player 2 to enter a word and stores it in word2.
int player_one = compute_score(word1); calculates the score for Player 1's word.
int player_two = compute_score(word2); calculates the score for Player 2's word.
The if, else if, and else statements compare the scores of both players and print the result: "Player 2 wins", "Player 1 wins", or "Tie!".
Compute Score Function

``` C

int compute_score(string word)
{
    int len = strlen(word);
    int score = 0;
    for (int i = 0; i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }
    return score;
}
```
int len = strlen(word); calculates the length of the input word.
int score = 0; initializes the score to zero.
The for loop iterates over each character in the word.
if (isupper(word[i])) checks if the character is an uppercase letter. If true, it adds the corresponding points to the score using POINTS[word[i] - 'A'].
else if (islower(word[i])) checks if the character is a lowercase letter. If true, it adds the corresponding points to the score using POINTS[word[i] - 'a'].
return score; returns the total score for the word.
