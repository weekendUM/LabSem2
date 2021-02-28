#include <stdio.h>
#include "utilities.h"

//OJI 2017 cls 5
int steps[1000];


int main()
{
	int length;
	printf("Alegeti lungimea drumului: ");
	scanf("%d", &length);	
	printf("Introduceti pasii, separati de cate un enter: \n");
	for (int i = 0; i < length; i++)
	{
		scanf("%d", &steps[i]);
	}
	printf("Drumul este %d ", 1);
	int curr = 1;
	for (int i = 0; i < length; i++)
	{
		if (steps[i] == 1)
		{
			curr = curr + i + 1;
			printf("%d ", curr);
		}
		else
		{
			curr = curr + i + 2;
			printf("%d ", curr);
		}
	}

	return 0;
}