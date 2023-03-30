#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
	int num = 0;
	while (scanf("%d", &num) != EOF)
	{
		int i = 0;
		int temp = 1;
		for (i = 2; i <= sqrt(1.0 * num); i++)
		{
			if (num % i == 0)
			{
				temp = 0;
			}
		}
		if (temp == 0)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
	}
	return 0;
}