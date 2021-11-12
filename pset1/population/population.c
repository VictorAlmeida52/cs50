#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for the starting population. Minimum of 9 is required.
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    // Prompt user for the ending population. Value equal to or greater than the starting population is required.
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    // Calculate number of years until we reach threshold
    int currentPopulation = start;
    int years = 0;
    do
    {
        int born = currentPopulation / 3;
        int dead = currentPopulation / 4;
        currentPopulation = currentPopulation + born - dead;
        years++;
    }
    while (currentPopulation < end);

    // Print number of years
    if (start == end)
    {
        years = 0;
    }
    printf("Years: %d\n", years);
}