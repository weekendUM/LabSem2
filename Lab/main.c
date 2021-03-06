#include <stdio.h>

void thing(int f, int b, int n)
{
	int buffer;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &buffer);
		if (buffer % 2 == 0)
		{
			if (f)
			{
				f--;
			}
		}
		else
		{
			if (b)
			{
				b--;
			}
		}
	}
	printf("%d\n%d", f, b);
}

int main()
{
	int f, b, n;
	scanf("%d %d %d", &f, &b, &n);
	thing(f, b, n);


	return 0;
}