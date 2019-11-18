#include <stdio.h>
#include <stdlib.h>

int month_day(int year, int yearday, int *month, int *day);
int is_leap_yr(int year);
void output(int year, int *month, int *day);

void get_user_date(int *user_date)
{
	int year, day;

	if (scanf("%d %d", &year, &day) == 0) {
		printf("Invalid input\n");
		exit(EXIT_FAILURE);
	}
	user_date[0] = year;
	user_date[1] = day;
}

int main(void)
{
	int user_date[2];	
	int year, yearday, month, day;

	get_user_date(user_date);
	year = user_date[0]; // transfers array variables to new variable
	yearday = user_date[1];
	if (month_day(year, yearday, &month, &day)) {
		output(year, &month, &day);
	} else {
		exit(EXIT_FAILURE);
	}

	return 0;
}

int month_day(int year, int yearday, int *month, int *day)
{
	int num_day_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int temp_yearday, i;	

	if (is_leap_yr(year) == 1) { // if it's a leap year
		if (yearday > 366 || yearday < 1 || year < 1) {
			printf("Wrong date\n");
			return 0;
		}
		num_day_month[1] = 29; // changes Feb max days to 29
	} else {
		if (yearday < 1 || yearday > 365 || year < 1) {
		printf("Wrong date\n");
		return 0;
		}
	}
	/* calculates month and day of month */
	temp_yearday = yearday;
	i = 0;
	while (temp_yearday > num_day_month[i]) {
		temp_yearday -= num_day_month[i];
		i++;
	}
	*day = temp_yearday;
	*month = ++i;

	return 1;
}

int is_leap_yr(int year)
{
	if (year % 4 == 0 && year % 100 == 0) {
		if (year % 400 == 0) {
			return 1;
		} else {
			return 0;
		}
	} else if (year % 4 == 0 && year % 100 != 0) {
		return 1;
	} else {
		return 0;
	}
}

void output(int year, int *month, int *day)
{
	printf("%02d/%02d/%04d\n", *month, *day, year);	
}
