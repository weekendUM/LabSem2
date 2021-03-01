#include <stdio.h>
#include "utilities.h"

//OJI 2017 cls 5
int borderR[50];
int borderL[50];
int routes[2500];
int k_level;

void build_borders(int k)
{
	borderR[1] = 1;
	borderL[1] = 1;
	int incrementer = 1;
	int i;
	for (i = 2; k >= borderL[i - 1] && k > borderR[i - 1]; i++, incrementer += i - 1)
	{
		borderL[i] += borderL[i - 1] + incrementer;
		borderR[i] += borderR[i - 1] + incrementer + 1;
	}
	k_level = i - 1;
}

int route(int node, int level)
{
	if (routes[node] != 0)
	{
		return routes[node];
	}
	if (level == 1)
	{
		return 1;
	}
	if (node - level >= borderL[level - 1] && (node - level + 1) <= borderR[level - 1])
	{
		routes[node] = max(route(node - level, level - 1), route(node - level + 1, level - 1)) + node;
		return routes[node];
	}
	else if (node - level < borderL[level - 1])
	{
		routes[node] = route(node - level + 1, level - 1) + node;
		return routes[node];
	}
	else
	{
		routes[node] = route(node - level, level - 1) + node;
		return routes[node];
	}
}

int main()
{
	//to do task 2
	int k;
	printf("Introduceti un k: ");
	scanf("%d", &k);
	build_borders(k);
	printf("Raspunsul este %d", route(k, k_level));
	

	return 0;
}