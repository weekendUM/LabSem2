#include <iostream>

using namespace std;

void append_stuff(char* in, int day, int month, int year)
{
	char* buffer = new char[5];
	_itoa(day, buffer, 10);
	if (day < 10)
	{
		strcat(in, "0");
	}
	strcat(in, buffer);
	strcat(in, "/");
	if (month < 10)
	{
		strcat(in, "0");
	}
	_itoa(month, buffer, 10);
	strcat(in, buffer);
	_itoa(year, buffer, 10);
	strcat(in, "/");
	strcat(in, buffer);
}

char* modificareData(int day, int month, int year)
{
	char* res = new char[11];
	strcpy(res, "");
	if (month == 12)
	{
		if (day + 5 <= 31)
		{
			day += 5;
			append_stuff(res, day, month, year);
			return res;
		}
		else
		{
			year++;
			month = 1;
			day = (day + 5) % 31;
			append_stuff(res, day, month, year);
			return res;
		}
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)
	{
		if (day + 5 <= 31)
		{
			day += 5;
			append_stuff(res, day, month, year);
			return res;
		}
		else
		{
			month++;
			day = (day + 5) % 31;
			append_stuff(res, day, month, year);
			return res;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day + 5 <= 30)
		{
			day += 5;
			append_stuff(res, day, month, year);
			return res;
		}
		else
		{
			month++;
			day = (day + 5) % 30;
			append_stuff(res, day, month, year);
			return res;
		}
	}
	else
	{
		if (day + 5 <= 28 + (year % 4 && (year / 4) % 100))
		{
			day += 5;
			append_stuff(res, day, month, year);
			return res;
		}
		else
		{
			month++;
			day = (day + 5) % (28 + (year % 4 && (year / 4) % 100));
			append_stuff(res, day, month, year);
			return res;
		}
	}
}

char* modificareData(char* raw)
{
	char* buffer = new char[11];
	strcpy(buffer, raw);
	int day, month, year;
	int i = 0;

	char* token = strtok(buffer, "/");

	/* walk through other tokens */
	while (token != NULL) {
		switch (i)
		{
		case 0:
			day = atoi(token);
			break;
		case 1:
			month = atoi(token);
			break;
		case 2:
			year = atoi(token);
			break;
		default:
			break;
		}
		i++;
		token = strtok(NULL, "/");
	}
	
	return modificareData(day, month, year);
}

char* modificareData(char* month, int day, int year)
{
	if (!strcmp(month, "ianuarie"))
	{
		return modificareData(day, 1, year);
	}
	else if (!strcmp(month, "februarie"))
	{
		return modificareData(day, 2, year);
	}
	else if (!strcmp(month, "martie"))
	{
		return modificareData(day, 3, year);
	}
	else if (!strcmp(month, "aprilie"))
	{
		return modificareData(day, 4, year);
	}
	else if (!strcmp(month, "mai"))
	{
		return modificareData(day, 5, year);
	}
	else if (!strcmp(month, "iunie"))
	{
		return modificareData(day, 6, year);
	}
	else if (!strcmp(month, "iulie"))
	{
		return modificareData(day, 7, year);
	}
	else if (!strcmp(month, "august"))
	{
		return modificareData(day, 8, year);
	}
	else if (!strcmp(month, "septembrie"))
	{
		return modificareData(day, 9, year);
	}
	else if (!strcmp(month, "octombrie"))
	{
		return modificareData(day, 10, year);
	}
	else if (!strcmp(month, "noiembrie"))
	{
		return modificareData(day, 11, year);
	}
	else if (!strcmp(month, "decembrie"))
	{
		return modificareData(day, 12, year);
	}
}



int main()
{
	//char* raw_date = new char[11];
	//std::cin >> raw_date;
	char* str = new char[15];
	strcpy(str, "februarie");
	printf("%s", modificareData(str, 28, 2021));
}