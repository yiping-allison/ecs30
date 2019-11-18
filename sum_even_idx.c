#include <stdio.h>

int sum_even_idx(int *list, int count)
{
	int sum = 0;
	int i;

	for (i = 0; i < count; i++)
	{
		if (i == 0 || i % 2 == 0) {
			sum += list[i];
		}
	}

	printf("The sum is %d\n", sum);
}

int main(void)
{
	int list[5] = { 0, 1, 2, 3, 4 };
	int count = 5;	

	sum_even_idx(list, count);	

	return 0;
}
