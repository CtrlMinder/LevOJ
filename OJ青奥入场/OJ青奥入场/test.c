#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
void Sort(struct nation na[1000], int);
struct nation
{
	int num;
	char name[100];
	int sum;
	char continent[100];
};
int main()
{
	int n = 0;
	int flag = 0;
	struct nation na[1000];
	while ((scanf("%d", &n)) != EOF)
	{
		int i = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d %s %d %s", &na[i].num, &na[i].name, &na[i].sum, &na[i].continent);
		}
		Sort(na, n);
		for (i = 0; i < n; i++)
		{
			if (strcmp(na[i].name, "China") == 0)
			{
				flag = i;
			}
			else
			{
				printf("%d %s %d %s\n", na[i].num, na[i].name, na[i].sum, na[i].continent);
			}
		}
		printf("%d %s %d %s\n", na[flag].num, na[flag].name, na[flag].sum, na[flag].continent);
	}
	return 0;
}
void Sort(struct nation na[1000], int n)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (strcmp(na[j].name, na[j + 1].name) > 0)
			{
				struct nation temp;
				temp = na[j];
				na[j] = na[j + 1];
				na[j + 1] = temp;
			}
		}
	}
}