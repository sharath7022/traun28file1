import random

def number_guessing_game():
    print("Welcome to the Number Guessing Game!")
    
    while True:
        number = random.randint(1, 100)
        attempts = 0
        print("\nI have selected a number between 1 and 100. Try to guess it!")
        
        while True:
            try:
                guess = int(input("Enter your guess: "))
                attempts += 1
                
                if guess < 1 or guess > 100:
                    print("Please guess a number between 1 and 100.")
                    continue
                
                if guess < number:
                    print("Too low! Try again.")
                elif guess > number:
                    print("Too high! Try again.")
                else:
                    print(f"Congratulations! You guessed the number in {attempts} attempts.")
                    break
                
            except ValueError:
                print("Invalid input! Please enter an integer.")
        
        play_again = input("Do you want to play again? (y/n): ").lower()
        if play_again != 'y':
            print("Thanks for playing! Goodbye!")
            break

if __name__ == "__main__":
    number_guessing_game()
