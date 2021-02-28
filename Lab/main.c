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
	int h, w;
	printf("Introduceti lungimea si latimea camerei: ");
	scanf("%d %d", &w, &h);
	printf("Dimensiunea maxima a laturii patratului este %d", gcd(h, w));

	return 0;
}