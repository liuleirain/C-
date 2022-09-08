#include <stdio.h>
#include <stdlib.h>

int main(void) {
  float new_guess;
  float last_guess;
  int number;

  printf("Enter a number: \n");
  scanf("%d", &number);

  if (number < 0) {
    printf("Please enter a number greater than 0.\n");
    return EXIT_FAILURE;
  }

  new_guess = 1;
  do {
    last_guess = new_guess;
    new_guess = (last_guess + number / last_guess) / 2;
    printf("%.15e\n", new_guess);
  } while (new_guess != last_guess);

  printf("Square root of %d is %g.\n", number, new_guess);

  return 0;
}