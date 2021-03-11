#include<stdio.h>
#include <string.h>

int main()
{
	int n;
	char buffer[80];
	char* res = NULL;
	scanf("%d", &n);
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", buffer);
		if (strlen(buffer) > max)
		{
			max = strlen(buffer);
			free(res);
			res = malloc(sizeof(char) * (strlen(buffer) + 2));
			strcpy(res, buffer);
			strcat(res, "\n");
		}
		else if (strlen(buffer) == max)
		{
			res = realloc(res, sizeof(char) * (strlen(res) + max + 2));
			strcat(res, buffer);
			strcat(res, "\n");
		}
	}
	
	printf("%s", res);
	free(res);
}