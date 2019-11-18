#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_random_num(void);
int get_player_guess(void);
int game_status(int random_num, int player_guess, int num_tries);
int tries(int);

int main()
{
	int rand_num, player_guess;
	int game_tries;

	rand_num = get_random_num();
	game_tries = 10;
	while (1) {
		player_guess = get_player_guess();
		game_tries -= 1;
		if (game_status(rand_num, player_guess, game_tries) == 1) {
			break;
		}
		if (tries(game_tries) == 0) {
			break;
		}
	}
	return 0;
}

int get_random_num(void)
{
	/* random input to be compared with */
	int r;

	srand(0);
	
	r = rand() % 10;
	
	return r;
}

int get_player_guess(void)
{
	int guess;
	int *ip;

	printf("What is your guess?\n"); // intial phrase
	
	/* If user gives bad input */
	while (1) {
		ip = &guess;
		if (scanf("%d", &guess) == 0) {
			printf("Invalid input, try again.\n");
			while (getchar() != '\n');
			continue;
		} else if (*ip > 100 || *ip < 1) {
			printf("Guess out of bounds, try again.\n");
			while (getchar() != '\n');
			continue;
		} else {
			return guess;
		}
	}	
}

int tries(int cur_tries)
{
	/* keeps track of tries */
	if (cur_tries == 0) {
		printf("You lose!\n");
		return 0;
	}
	return 1;
}

int game_status(int random_num, int player_g, int num_tries)
{
	/* displays status of game */
	if (player_g == random_num) {
		printf("You guessed correctly in %d tries!\n", num_tries);
		return 1;
	} else if (player_g > random_num) {
		printf("Your guess is too big! (%d tries left)\n", num_tries);
	} else if (player_g < random_num) {
		printf("Your guess is too small! (%d tries left)\n", num_tries);
	}
	return 0;
}
