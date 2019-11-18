#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int user_input();
void is_multiple(int num);
void sum_digits(int num);
void is_prime(int num);

int main()
{
	int user;

	user = user_input();
	printf("Properties of number %d:\n", user);
	is_multiple(user);
	sum_digits(user);
	is_prime(user);

	return 0;
}

int user_input(void)
{
	int user_num;
	
	if (scanf("%d", &user_num) == 1) { // check if input is a num
		if (user_num > 0) { // check if input is not lower than 1
			return user_num;
		} else {
			printf("Invalid input\n");
			exit(1);
		}
	} else {
		printf("Invalid input\n");
		exit(1);
	}
}

void is_multiple(int num)
{
	/* Prime number calculation */
	if (num % 7 == 0 || num % 11 == 0 || num % 13 == 0) {
		printf("- Multiple of 7, 11 or 13\n");
	} else {
		printf("- Not a multiple of 7, 11 or 13\n");
	} 
}

void sum_digits(int num)
{
	/* summing digits */
	int sum;
	int digit;

	sum = 0; // initialization
	while (num > 0) {
		digit = num % 10;
		sum += digit;
		num = num / 10;
	}
	/* even or odd calculation */
	if (sum % 2 == 0) {
		printf("- Sum of digits is even\n");
	} else {
		printf("- Sum of digits is odd\n");
	}
}
	
void is_prime(int num)
{
	/* prime number calculation */
	int i;

	for (i = 2; i < num; i++) {
		if (num % i == 0) {
			printf("- Not a prime number\n");
			break;
		}
	}
	if (i == num) {
		printf("- Prime number\n");
	}
	if (num == 1) { // special case 1
		printf("- Prime number\n");
	}
}
		
