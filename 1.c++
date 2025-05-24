#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts;
    char playAgain;

    srand(time(0)); // Seed random number generator

    printf("Welcome to the Number Guessing Game!\n");

    do {
        number = rand() % 100 + 1; // Random number between 1 and 100
        attempts = 0;
        printf("\nI have selected a number between 1 and 100. Try to guess it!\n");

        while (1) {
            printf("Enter your guess: ");
            if (scanf("%d", &guess) != 1) {
                // Clear invalid input
                while (getchar() != '\n');
                printf("Invalid input! Please enter an integer.\n");
                continue;
            }
            attempts++;

            if (guess < 1 || guess > 100) {
                printf("Please guess a number between 1 and 100.\n");
            } else if (guess < number) {
                printf("Too low! Try again.\n");
            } else if (guess > number) {
                printf("Too high! Try again.\n");
            } else {
                printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
                break;
            }
        }

        printf("Do you want to play again? (y/n): ");
        // Consume any leftover newline
        while ((getchar()) != '\n');
        playAgain = getchar();

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing! Goodbye!\n");
    return 0;
}
