#include <stdio.h>
#include <stdbool.h>

typedef struct date
{
	int day, month, year;
};

int get_day(int day, int month, int year)
{
	bool leap = false;
	int days = (month - 1) * 30;
	if (year % 400 == 0)
	{
		leap = true;
	}
	else if (year % 100 == 0);
	else if (year % 4 == 0)
	{
		leap = true;
	}
	if (month > 2)
	{
		if (leap)
		{
			days--;
		}
		else
		{
			days -= 2;
		}
	}
	if (month - 1)
	{
		days += (month - 1) / 2;
	}	
	days += day;
	return days;
}

struct date get_date(int days, int year)
{
	struct date res;
	res.month = 1;
	res.year = 1;
	bool leap = true;
	if (year % 400 == 0)
	{
		leap = true;
	}
	else if (year % 100 == 0);
	else if (year % 4 == 0)
	{
		leap = true;
	}
	if (days % (365 + leap))
	{
		res.year = year + 1;
		days = days % (365 + leap);
	}
	if (leap)
	{
		if (days <= 31)
		{
			res.day = days % 32;
		}
		else if (days <= 60)
		{
			res.day = 31;
			res.month = 2;
			res.day += (days - 31) % 30;
		}
		else
		{
			res.month = days / 30 + 1;
			if()
		}
	}
	
	return res;
}

int main()
{
	int day, month, year, days;
	bool leap = false;
	printf("Introduceti data sub forma zi/luna/an seprate de un spatiu: ");
	scanf("%d %d %d", &day, &month, &year);
	printf("Introduceti nr de zile sa fie adaugat: ");
	scanf("%d", &days);
	int new_day = get_day(day, month, year) + days;
	struct date new_date = get_date(new_day, year);
	printf("%d/%d/%d", new_date.day, new_date.month, new_date.year);



	return 0;
}