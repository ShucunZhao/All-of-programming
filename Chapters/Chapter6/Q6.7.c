#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(void){
  int guessesMade = 0;
  int yourGuess;
  char buffer[1024];
  struct timeval now;
  //using the time to seed the random number generator
  //is not very secure, but that doesn't matter here.
  gettimeofday(&now, NULL);
  srandom(now.tv_usec);

  int myNumber = random();

  printf("I'm thinking of a number...\n");

  do{
    if (guessesMade > 0){
      printf("Sorry that is not right... Try again!\n");
    }
    printf("What number do you guess?\n");
    if (fgets(buffer, 1024, stdin) == NULL){
      printf("Oh no, you are giving up? You lose...\n");
      return EXIT_FAILURE;
     }
	yourGuess = atoi(buffer);
	guessesMade++;
   }
  while(yourGuess != myNumber);
  printf("That is correct, you won in %d guesses!\n", guessesMade);
  return EXIT_SUCCESS;
}
