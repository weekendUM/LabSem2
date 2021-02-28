#include <stdio.h>
#include "utilities.h"


int main()
{
	int n;
	int res = 0;
	printf("Introduceti n: ");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		res += no_digits(i);
	}
	if (res < 20)
	{
		printf("S-au folosit %d cifre", res);
		return 0;
	}
	printf("S-au folosit %d de cifre", res);

	return 0;
}