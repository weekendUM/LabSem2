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

int get_val(int x, int y)
{
	int res = 1;
	int r = 0;
	for (int i = 0; i < x; i++, r++)
	{
		res += r;
	}
	res += y - 1;
	return res;
}

int main()
{
	int n;
	scanf("%d", &n);
	print(n);
	printf("%d", get_val(2, 1));

	return 0;
}