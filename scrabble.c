#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Prompt the user for two words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    // calculate each players score
    int player_one = compute_score(word1);
    int player_two = compute_score(word2);

    // status of the game
    if (player_one < player_two)
    {

        printf("player 2 wins");
    }
    else if (player_two < player_one)
    {
        printf("player 1 wins");
    }
    else
    {

        printf("Tie!");
    }
}

int compute_score(string word)
{
    int len = strlen(word);
    int Score = 0;
    for (int i = 0; i < len; i++)
    {
        if (isupper(word[i]))
        {

            Score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {

            Score += POINTS[word[i] - 'a'];
        }
    }
    return Score;
}
