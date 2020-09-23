#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int random_number = 0;
    int guess = 0;
    int numberOfGuesses = 5;
    time_t t;

    srand((unsigned) time(&t));
    random_number = rand() % 21;

    printf("This is a guessing game.\n");
    printf("Choose a number between 0 and 20.\n");

    for(numberOfGuesses = 5; numberOfGuesses > 0; --numberOfGuesses)
    {
        printf("You have %d tr%s left.\n", numberOfGuesses, numberOfGuesses == 1 ? "y" : "ies");
        printf("Enter a guess: ");
        scanf("%d", &guess);

        if(guess == random_number)
        {
            printf("Congrats! You guess it!\n");
            return 0;
        }
        else if(guess < 0 || guess > 20)
            printf("The number is between 0 and 20.\n");
        else if(random_number >  guess)
            printf("Sorry, %d is wrong. My number is greater than that.\n", guess);
        else if(random_number <  guess)
            printf("Sorry, %d is wrong. My number is smaller than that.\n", guess);
    }

    printf("You have had five tries and failed. The number was %d.\n", random_number);

    return 0;
}