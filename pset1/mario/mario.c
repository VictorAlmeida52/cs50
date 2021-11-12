#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for the starting population. Minimum of 9 is required.
    int size;
    do
    {
        size = get_int("Pyramid size: ");
    }
    while (size < 1 || size > 8);

    int index = 1;
    do
    {
        // Calculate number of blank spaces and hashes for each line
        int blankSize = size - index;
        int hashSize = size - blankSize;

        // Print the blank spaces
        for (int i = 0; i < blankSize; i++)
        {
            printf(" ");
        }
        // Print the hashes
        for (int j = 0; j < hashSize; j++)
        {
            printf("#");
        }
        // Print two blank spaces then the hashes again
        printf("  ");
        for (int k = 0; k < hashSize; k++)
        {
            printf("#");
        }
        printf("\n");
        index++;

    }
    while (index <= size);
}