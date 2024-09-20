//
// Created by hfwei on 2024/9/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int secretNumber, guess, attempts = 0;
  const int maxAttempts = 7;

  // Tell the player about the game rule
  printf("Welcome to 'Guess the Number'!\n");
  printf("I have picked a number between 1 and 100.\n");
  printf("You have %d attempts to guess it!\n\n", maxAttempts);

  // Generate a random number
  srand(time(0));
  secretNumber = rand() % 100 + 1;

  // Loop: repeat until the player wins or loses
  while (attempts < maxAttempts) {
    // Ask the player to enter the guess number
    printf("Enter your guess (1-100): ");
    scanf("%d", &guess);

    // Compare it with the random secret number, and inform the player of the result
    if (guess < secretNumber) {
      printf("Too low!\n");
    } else if (guess > secretNumber) {
      printf("Too high!\n");
    } else {
      printf("Congratulations! You guessed the number in %d attempts.\n", attempts + 1);
      return 0;
    }

    attempts++;
  }

  // If player runs out of attempts
  printf("Sorry! You've used all %d attempts. The number was %d.\n", maxAttempts, secretNumber);
  return 0;
}