#include <stdio.h>

#define NEW_CAR_MILES_MAX 50000

int main()
{
	int emissions_type, odometer; // input
	double number_grams_emitted_per_mile; // input	
	
	scanf("%d %lf %d", &emissions_type, &number_grams_emitted_per_mile, 
		&odometer);

	/* Program reads emissions types and compares the number of grams emitted per mile
	 * to new standard emissions.
	 * Displays a message confirming if the car reaches or exceeds standards */

	if (emissions_type == 1) {
		if (odometer <= NEW_CAR_MILES_MAX) {
			if (number_grams_emitted_per_mile > 3.4) {
				printf("Emissions exceed permitted level of 3.40 grams/mile\n");
			} else {
				printf("Emissions do not exceed permitted level of 3.40 grams/mile\n");
			}
		} else if (odometer > NEW_CAR_MILES_MAX) {
			if (number_grams_emitted_per_mile > 4.2) {
				printf("Emissions exceed permitted level of 4.20 grams/mile\n");
			} else {
				printf("Emissions do not exceed permitted level of 4.20 grams/mile\n");
			}
		}
	} else if (emissions_type == 2) {
		if (odometer <= NEW_CAR_MILES_MAX) {	
			if (number_grams_emitted_per_mile > 0.31) {
				printf("Emissions exceed permitted level of 0.31 grams/mile\n");
			} else {
				printf("Emissions do not exceed permitted level of 0.31 grams/mile\n");
			}
		} else if (odometer > NEW_CAR_MILES_MAX) {		
			if (number_grams_emitted_per_mile > 0.39) {
				printf("Emissions exceed permitted level of 0.39 grams/mile\n");
			} else {
				printf("Emissions do not exceed permitted level of 0.39 grams/mile\n");
			}
		}
	} else if (emissions_type == 3) {
		if (odometer <= NEW_CAR_MILES_MAX) {	
			if (number_grams_emitted_per_mile > 0.4) {
				printf("Emissions exceed permitted level of 0.40 grams/mile\n");
			} else {
				printf("Emissions do not exceed permitted level of 0.40 grams/mile\n");
			}
		} else if (odometer > NEW_CAR_MILES_MAX) {	
			if (number_grams_emitted_per_mile > 0.5) {
				printf("Emissions exceed permitted level of 0.50 grams/mile\n");
			} else {
				printf("Emissions do not exceed permitted level of 0.50 grams/mile\n");
			}
		}
	} else if (emissions_type == 4) {
		if (odometer <= NEW_CAR_MILES_MAX) {	
			if (number_grams_emitted_per_mile > 0.25) {
				printf("Emissions exceed permitted level of 0.25 grams/mile\n");
			} else {
				printf("Emissions do not exceed permitted level of 0.25 grams/mile\n");
			}
		} else if (odometer > NEW_CAR_MILES_MAX) {	
			if (number_grams_emitted_per_mile > 0.31) {
				printf("Emissions exceed permitted level of 0.31 grams/mile\n");
			} else {
				printf("Emissions do not exceed permitted level of 0.31 grams/mile\n");
			}
		}
	} else {  // If unknown pollutant 
		printf("Unknown pollutant\n");
		
		return 1;
	}

	return 0;
}
