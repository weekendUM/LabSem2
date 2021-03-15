#include <stdio.h>

int remove_dup(int n, int v[])
{
	for (int i = 1; i < n; i++)
	{
		if (v[i] == v[i - 1])
		{
			for (int j = i; j < n - 1; j++)
			{
				v[j] = v[j + 1];
			}
			i--;
			n--;
		}
	}
	return n;
}

int main()
{
	int v[100];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
	}
	n = remove_dup(n, v);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", v[i]);
	}
	return 0;
}