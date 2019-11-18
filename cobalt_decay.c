#include <math.h>
#include <stdio.h>

#define E M_E 
#define H 5.272

/* print statments for calculations */
void print_state(int years, double remaining)
{
	printf("After %d years, the remaining amount is %.2lf grams\n",
		years, remaining);
}

int main()
{
	int grams, years, yr_count;
	double remaining;

	scanf("%d %d", &grams, &years);
	
	/* If input is invalid */
	if (grams <= 0 || years <= 0) {
		printf("Invalid values\n");
		return 1;
	}
	
	/* Calculations */
	remaining = grams;
	yr_count = 1; // intialization with base case
	while (yr_count != years + 1) {
		remaining = grams * (pow(E, (-0.693 * (yr_count / H))));
		print_state(yr_count, remaining);		
		yr_count = yr_count + 1;
	}
	
	return 0;

}
