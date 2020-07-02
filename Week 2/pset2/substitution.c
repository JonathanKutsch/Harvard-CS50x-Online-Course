#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
bool is_valid_key(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");  // check validity
        return 1;
    }
    if (!is_valid_key(argv[1]))
    {
        printf("Key must contain 26 characters.\n");  // if not valid, then print this
        return 1;  // if it is valid, then move on
    }
    
    string s = get_string("plaintext: ");  // request user input of text
    string difference = argv[1];
    for (int i = 'A'; i <= 'Z'; i++)
        difference[i - 'A'] = toupper(difference[i - 'A']) - i;  // calculate the difference
    printf("ciphertext: ");
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isalpha(s[i]))
            s[i] = s[i] + difference[s[i] - (isupper(s[i]) ? 'A' : 'a')];
        printf("%c", s[i]);
    }
    printf("\n");
}

bool is_valid_key(string s)
{
    int len = strlen(s);
    if (len != 26)
        return false;  // if length is not 26, then return false
    
    int freq[26] = { 0 };  // others calculate frequency of every letter  
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(s[i]))
            return false;  // if repitition, then return false
        int index = toupper(s[i]) - 'A';
        if (freq[index] > 0)
            return false;
        freq[index]++;
    }
    
    return true;  // otherwise, return true
}