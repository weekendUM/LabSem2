#include <stdio.h>
#include "utilities.h"


int main()
{
	unsigned screen = 34;
	unsigned n;
	printf("Introduceti un nr. n: ");
	scanf("%d", &n);
	for (unsigned i = 0; i < n; i++)
	{
		screen = digit_prod(screen) + 18;
	}
	printf("Dupa %d minute va fi afisat %d", n, screen);

	return 0;
}