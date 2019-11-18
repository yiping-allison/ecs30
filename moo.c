#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void get_game_key(int *secret);
void get_user_guess(int *guess);
int is_at_index(int guess_location, int *secret_location);
int is_in_array(int *ptr_secret, char user_guess, int *ptr_secret_index);
void output(int count_array, int count_index, int count_none);

int main(void)
{
	int secret_num[4];
	int user_guess[4];
	int secret_index;
	int count_array, count_index, count_none;

	get_game_key(secret_num);
	for (int i = 10; i > 0; i--) { // loop for 10 tries
		get_user_guess(user_guess);
		count_array = 0;
		count_index = 0;
		count_none = 0;
		for (int j = 0; j < 4; j++) {
			// check if in array
			if (is_in_array(secret_num, user_guess[j], &secret_index)) { 
				if (is_at_index(j, &secret_index)) { // check if at right index
					count_index++;
				} else {
					count_array++;
					}
			}
		}
		count_none = 4 - count_array - count_index;
		if (count_index == 4) { // if guessed correctly
			printf("You guessed correctly in %d tries!\n", 11 - i);
			return 0;
		} 
		output(count_array, count_index, count_none); 
	}
	printf("You lose!\n");
}

void get_game_key(int *secret)
{
	/* gets game secret key */
	int r;

	srand(0);
	
	for (int i = 0; i < 4; i++) {
		r = rand() % 10;
		char c = r + '0';
		secret[i] = c;
	}
}

void get_user_guess(int *guess)
{
	/* gets user guess */
	char user_g;
	int i = 0;

	printf("What is your guess?\n");
	while (i < 4) {
		scanf("%c", &user_g);
		if (isdigit(user_g) == 0) {
			continue;
		} else {
			guess[i] = user_g;
			i++;
		}
	}
	while (getchar() != '\n'); 	
}

int is_in_array(int *ptr_secret, char user_guess, int *ptr_secret_index)
{
	/* checks if guessed digit is in the secret number array */
	for (int i = 0; i < 4; i++) {
		if (user_guess == ptr_secret[i]) {
			*ptr_secret_index = i;
			return 1;
		}
	}
	return 0;	
}

int is_at_index(int guess_location, int *secret_location)
{
	/* checks if guessed digit is at the right index of array */
	if (guess_location == *secret_location) {
		return 1;	
	} else {
		return 0;
	}
}

void output(int count_array, int count_index, int count_none)
{
	/* prints output statements */
	while (count_index > 0) {
		printf("X");
		count_index--;
	}
	while (count_array > 0) {
		printf("O");
		count_array--;
	}
	while (count_none > 0) {
		printf("-");
		count_none--;
	}
	printf("\n");
}
