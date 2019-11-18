#include <stdio.h>

int main()
{
	double richter_scale;

	scanf("%lf", &richter_scale);

	/* If-else statments determining degree of richter scale 
	 * severness */
	if (richter_scale < 5.0 && richter_scale > 0.0) {
		printf("Little or no damage\n");
	} else if (richter_scale >= 5.0 && richter_scale < 5.5) {
		printf("Some damage\n");
	} else if (richter_scale >= 5.5 && richter_scale < 6.5) {
		printf("Serious damage: walls may crack or fall\n");
	} else if (richter_scale >= 6.5 && richter_scale < 7.5) {
		printf("Disaster: houses and buildings may collapse\n");
	} else if (richter_scale >= 7.5) {
		printf("Catastrophe: most buildings destroyed\n");
	} else {
		printf("Invalid magnitude\n");
		
		return 1; // returns error code 1 if value is invalid
	}

	return 0;
}
