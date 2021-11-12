#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


float calculate_avg_letters(int letters, int words);
float calculate_avg_sentences(int letters, int sentences);

int main(void)
{
    // Get input words from both players
    string text = get_string("Text: ");
    int qtdLetters = count_letters(text);
    int qtdWords = count_words(text);
    int qtdSentences = count_sentences(text);

    int index = (int) round(0.0588 * calculate_avg_letters(qtdLetters, qtdWords) - 0.296 * calculate_avg_sentences(qtdSentences,
                            qtdWords) - 15.8);

    // if grade 16 or higher
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    // if grade lower than 1
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    // index from 1 to 15
    else
    {
        printf("Grade %d\n", index);
    }

}

// count letter in text
int count_letters(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]) > 0)
        {
            count++;
        }
    }
    return count;
}

// count words in text
int count_words(string text)
{
    int count = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]) > 0)
        {
            count++;
        }
    }
    return count;
}

// count sentences in text
int count_sentences(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}

// calculate average qtd of letters in 100 words
float calculate_avg_letters(int letters, int words)
{
    return ((letters * 100.0) / words);
}

// calculate average qtd of sentences in 100 words
float calculate_avg_sentences(int sentences, int words)
{
    return ((sentences * 100.0) / words);
}