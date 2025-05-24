#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(nullptr)); // Seed random number generator

    char playAgain = 'y';

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;

    while (playAgain == 'y' || playAgain == 'Y') {
        int number = std::rand() % 100 + 1; // Number between 1 and 100
        int guess = 0;
        int attempts = 0;

        std::cout << "\nI have selected a number between 1 and 100. Try to guess it!" << std::endl;

        while (true) {
            std::cout << "Enter your guess: ";
            if (!(std::cin >> guess)) {
                std::cin.clear(); // Clear error flag
                std::cin.ignore(10000, '\n'); // Ignore invalid input
                std::cout << "Invalid input! Please enter an integer." << std::endl;
                continue;
            }
            attempts++;

            if (guess < 1 || guess > 100) {
                std::cout << "Please guess a number between 1 and 100." << std::endl;
            }
            else if (guess < number) {
                std::cout << "Too low! Try again." << std::endl;
            }
            else if (guess > number) {
                std::cout << "Too high! Try again." << std::endl;
            }
            else {
                std::cout << "Congratulations! You guessed the number in " << attempts << " attempts." << std::endl;
                break;
            }
        }

        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
        std::cin.ignore(10000, '\n'); // Clean input buffer
    }

    std::cout << "Thanks for playing! Goodbye!" << std::endl;
    return 0;
}
