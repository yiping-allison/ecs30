#include <stdio.h>
#include <string.h>

void stringcpy(char *dest, char *src)
{
	int i;
	int j = 0;
	int string_len;

	string_len = strlen(src);
	for (i = 0; i < string_len + 1; i++) {
		dest[j] = src[i];
		j++;
	}
}

int main(void)
{
	char src[] = "Hello";
	char dest[10];	

	stringcpy(dest, src);
	printf("dest is %s\n", dest);
}
