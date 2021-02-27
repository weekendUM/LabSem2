#include <stdio.h>

int mirrored(int x)
{
	int res = 0;
	while (x)
	{
		res = res * 10 + x % 10;
		x /= 10;
	}
	return res;
}

int main()
{
	int no;
	printf("Introduceti un nr.: ");
	scanf("%d", &no);
	if (no == mirrored(no))
	{
		printf("Rasturnatul numarului introdus este %d si numarul original este palindrom", mirrored(no));
	}
	else
	{
		printf("Rasturnatul numarului introdus este %d si numarul original nu este palindrom", mirrored(no));
	}

	return 0;
}