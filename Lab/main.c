#include <stdio.h>

int gcd(int x, int y)
{
	int r;
	while (y)
	{
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int scm(int x, int y)
{
	return (x * y) / gcd(x, y);
}

int main()
{
	int ext;
	printf("Introduceti lungimea pt fortareata exterioara(n>=7): ");
	scanf("%d", &ext);
	int l1 = ext * 2 + (ext - 1) * 2;
	int l2 = (ext - 2) * 2 + (ext - 4) * 2;
	int com = scm(l1, l2);
	printf("Prima chestie are nevoie de %d cicluri, iar a doua de %d cicluri pt a se putea schimba garda", com / l1, com / l2);

	return 0;
}