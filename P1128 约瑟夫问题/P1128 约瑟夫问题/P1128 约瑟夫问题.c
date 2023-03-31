#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int peo = 0;
	int interval = 0;
	while (scanf("%d %d", &peo, &interval) != EOF)
	{
		int arr[1000] = { 0 };
		int i = 0;
		int count = 0;
		int countNumber = 0;
		for (i = 1; i <= peo; i++)
		{
			arr[i] = 1;
		}
		for (i = 1; countNumber < peo; i++)
		{
			count += arr[i];
			if ((count % interval == 0)&&count!=0)
			{
				printf("%d ", i);
				count = 0;
				arr[i] = 0;
				countNumber++;
			}
			i %= peo;
		}
		printf("\n");
	}
	return 0;
}