#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 2)  // check for command line argument
    {
        int key = atoi(argv[1]);  // use the 'atoi' function to convert the string to an integer
        bool valid_key = false;  // store key validity
        
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isdigit(argv[1][i]))
            {
                valid_key = true;  // // check key validity
            }
            else
            {
                printf("Usage ./caesar key\n");
                return 1;  // display usage and end program
            }
        }
        
        if (valid_key == true)
        {
            char input[500];
            printf("plaintext: ");
            fgets(input, sizeof(input), stdin);
            
            for (int i = 0; i < strlen(input); i++)
            {
                if (isupper(input[i]))  // check for upper case letters
                {
                    input[i] = ((input[i] - 65 + key) % 26) + 65;  // apply formula
                }
                else if (islower(input[i]))  // check for lower case numbers
                {
                    input[i] = ((input[i] - 97 + key) % 26) + 97;  // apply formula
                }
            }
            printf("ciphertext: %s", input);
        }
    }
    else
    {
        printf("Usage ./caesar key\n");
        return 1;  // display usage and end program
    }
}