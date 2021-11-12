#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int validate_dataset(string dataset);
string encrypt(string plaintext, string dataset);
int is_letter(char letter);

int main(int argc, char *argv[])
{
    // Validate qtd of arguments
    string dataset;
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    dataset = argv[1];

    // Validate argument
    int validation = validate_dataset(dataset);
    if (validation != 3)
    {
        printf("Key must contain 26 UNIQUE ALPHABET characters\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    string ciphertext = encrypt(plaintext, dataset);
    printf("ciphertext: %s\n", ciphertext);
}

// uses the dataset to encrypt the plaintext
string encrypt(string plaintext, string dataset)
{
    for (int i = 0; i < strlen(plaintext); i++)
    {
        int position;
        int characterType = is_letter(plaintext[i]);
        // if upper
        if (characterType == 1)
        {
            position = plaintext[i] - 'A';
            plaintext[i] = toupper(dataset[position]);
        }
        // if lower
        else if (characterType == 2)
        {
            position = plaintext[i] - 'a';
            plaintext[i] = tolower(dataset[position]);
        }

    }

    return plaintext;
}

int validate_dataset(string dataset)
{
    /*
        0 - Does not contain 26 characters
        1 - Contains non-alphabet character
        2 - Does not contain each letter exactly once
    */
    // Validate qtd of chars
    if (strlen(dataset) != 26)
    {
        return 0;
    }

    // Validate alphabet chars
    for (int i = 0; i < strlen(dataset); i++)
    {
        if (!isalpha(dataset[i]))
        {
            return 1;
        }
    }

    // Validate unique chars
    for (int i = 0; i < strlen(dataset); i++)
    {
        for (int j = i + 1; j < strlen(dataset); j++)
        {
            if (dataset[i] == dataset[j])
            {
                return 2;
            }
        }
    }

    return 3;
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