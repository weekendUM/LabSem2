#include <stdio.h>

void print(int n)
{
	int level = 1;
	for (int i = 0; i < n; level++)
	{
		for (int j = 0; j < level && i < n; i++, j++)
		{
			printf("%d ", i + 1);
		}
		printf("\n");
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	print(n);

	return 0;
}