#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 9 // set constant max number of candidates

typedef struct // give candidates name and vote count
{
    char name[50];
    int votes;
}
candidate;

candidate candidates[MAX]; // array of candidates

int candidates_count; // number of candidates

bool vote(char name[]);
void print_winner(void);

int main(int argc, char *argv[])
{
    if (argc < 3) // check for invalid usage
    {
        printf("Usage: ./plurality [candidate ...]\n");
        return 1;
    }
    
    candidates_count = argc - 1; // populate array of candidates
    if(candidates_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for(int i = 0; i < candidates_count; i++)
    {
        strcpy(candidates[i].name, argv[i + 1]);
        candidates[i].votes = 0;
    }
    
    int voters_count;
    printf("Number of voters: "); // user input number of voters
    scanf("%i", &voters_count);
    
    for (int i = 0; i < voters_count; i++) // loop over all voters
    {
        char name[50];
        printf("Vote: "); // request user input
        scanf("%s", name);
        
        if (!vote(name)) // check for invalid input
        {
            printf("Invalid vote.\n");
        }
    }
    
    print_winner(); // display winner
}

bool vote(char name[]) // update vote total when new vote provided
{
    for (int i = 0; i < candidates_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0) // check if there is a match for candidate name
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(void) // display winner
{
    int highestVotes= 0; // check for highest votes
    for (int i = 0; i < candidates_count; i++)
    {
        if (candidates[i].votes > highestVotes)
        {
            highestVotes = candidates[i].votes;
        }
    }
    
    for (int i = 0; i < candidates_count; i++)
    {
        if(candidates[i].votes == highestVotes)
        {
            printf("%s\n", candidates[i].name); // check for candidates with highest number of votes
        }
    }
}

