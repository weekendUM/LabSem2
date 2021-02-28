#include <stdio.h>
#include "utilities.h"


int main()
{
	int h, w;
	printf("Introduceti lungimea si latimea camerei: ");
	scanf("%d %d", &w, &h);
	printf("Dimensiunea maxima a laturii patratului este %d", gcd(h, w));

	return 0;
}