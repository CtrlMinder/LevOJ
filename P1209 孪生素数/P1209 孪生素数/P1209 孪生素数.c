#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int isPrime(int num);
int main()
{
	int num = 0;
	while (scanf("%d", &num) != EOF)
	{
		int i = 0;
		for (i = num; i > 1; i--)
		{
			if (1 == isPrime(i) && 1 == isPrime(i - 2))
			{
					printf("%d %d\n", i - 2, i);
					break;
			}
		}
	}
	return 0;
}
int isPrime(int num)//≈–∂œ «∑Ò «Àÿ ˝
{
	if (num == 2 || num == 3)
	{
		return 1;
	}
	else
	{
		int i = 0;
		for (i = 2; i <= sqrt(1.0 * num); i++)
		{
			if (num % i == 0)
			{
				return 0;
			}
		}
		return 1;
	}
}