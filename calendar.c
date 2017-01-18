#pragma warning(disable: 4996 )

#include <stdio.h>
int month_days(int year, int month)//return number of days in this month
{
	switch (month)
	{
		case 4:
		case 6:
		case 9:
		case 11: return(30);
		break;
		case 2: if (is_leapyear(year) == 1)
		return (29);
		else
		return (28);
		break;
		default: return (31);
	}
}

int is_leapyear(int year)//return 1 if it is leapyear
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400==0)
	return 1;
	else
	return 0;
}

int firstday(int year, int month)//return what is the first day of the month
{
	int i,TotalDay,leapyearcnt=0;
	for (i = 1; i < year; i++){
		if (is_leapyear(i) == 1)
		leapyearcnt++;
	}
	TotalDay = (year - 1) * 365 + leapyearcnt;//the total days until last year

	for (i = 1; i < month; i++){
		TotalDay += month_days(year,i);
	}
	TotalDay += 1;//the total days from 1/1 to input month's first day

	return TotalDay % 7;
}

void show_calendar(int days, int first)//print calender
{
	int i = 1;
	printf("  -Sun- -Mon- -Tus- -Wen- -Thu- -Fri- -Sat-\n");
	for (i = 0; i<first; i++)
	{
		printf("      ");
	}
	for (i = 1; i <= days; i++)
	{
		printf("%6d", i);
		if ((first + i) % 7 == 0)
		printf("\n");
	}
}

int main(void)
{
	int year, month, days, first;
	printf("Input year and month to make calender (it has to  be after 1900/1/1)\n");
	scanf("%d%d", &year, &month);
	days = month_days(year, month);
	printf("number of days in this month:%d\n", days);
	first = firstday(year, month);
	show_calendar(days, first);
}
