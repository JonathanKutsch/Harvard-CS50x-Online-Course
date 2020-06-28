#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, row, column, space; // declare variables
    do
    {
        height = get_int("Height: "); // user input
    }
    while (height < 1 || height > 8);

    for (row = 0; row < height; row++) // set row location
    {
        for (space = 0; space < height; space++)
        {
            if (row + space < height - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("  ");
        for (column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n"); // go to next line once all # are properly placed
    }
}