#include<stdio.h>
#include <string.h>

int main()
{
	int n;
	char buffer[80];
	char* res = malloc(sizeof(char));
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
			//printf("%d\n", sizeof(char) * (strlen(res) + 1));
			char* b = malloc(sizeof(char) * (strlen(res) + 1));
			strcpy(b, res);
			free(res);
			res = malloc(sizeof(char) * (strlen(res) + max + 2));
			strcpy(res, b);
			strcat(res, buffer);
			strcat(res, "\n");
			free(b);
		}
	}
	printf("%s", res);
}