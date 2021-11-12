#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompts user for his or her name then say "Hello, %USER_NAME%"
    string name = get_string("What is your name?\n");
    printf("Hello, %s\n", name);
}