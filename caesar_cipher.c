#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int get_key(void);
void cipher(int key, char *c);

int main(void) 
{
	int key;
	char character;		
	
	key = get_key();
	while (getchar() != '\n');
	while (scanf("%c", &character) != EOF) {
		if (isalpha(character)) {
			cipher(key, &character);
			printf("%c", character);
		} else if (character == '\n') { // if character is a newline
			printf("\n");
		} else if (!(isgraph(character)) && !(isblank(character))) { // if unprintable
			continue;
		} else {
			printf("%c", character); // if a printable and valid character
		}
	}				

	return 0;
}

int get_key(void) // gets user key
{
	int user_key;
	
	scanf("%d", &user_key);
	if (user_key < 0 || user_key > 26) {
		printf("Invalid key\n");
		exit(EXIT_FAILURE);
	}
	
	return user_key;
}

void cipher(int key, char *c)
{
	int i;

	if (isupper(*c)) {
		i = *c;
		i += key;
		if (i > 90) { // if ascii value goes out of bounds
			i -= 90;
			i += 64;
			*c = i;
		} else {
			*c = i;
		}
	} else {
		i = *c;
		i += key;
		if (i > 122) { // wrapping ascii value
			i -= 122;
			i += 96;
			*c = i;
		} else {
			*c = i;
		}
	}
}
