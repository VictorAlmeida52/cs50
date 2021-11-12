#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
int is_letter(char letter);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 == score2)
    {
        printf("Tie!");
    }
    else if (score1 > score2)
    {
        printf("Player 1 wins!...");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!...");
    }
}

int compute_score(string word)
{
    int totalPoints = 0;
    // Compute and return score for string
    for (int i = 0; i < strlen(word); i++)
    {
        int position;
        int characterType = is_letter(word[i]);
        // if upper
        if (characterType == 1)
        {
            position = word[i] - 'A';
            totalPoints += POINTS[position];
        }
        // if lower
        else if (characterType == 2)
        {
            position = word[i] - 'a';
            totalPoints += POINTS[position];
        }
        // if not a valid letter
        else
        {
            continue;
        }
    }
    return totalPoints;
}

// check if is letter
int is_letter(char letter)
{
    int upper = isupper(letter);
    int lower = islower(letter);
    if (upper != 0)
    {
        return 1;
    }
    else if (lower != 0)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
