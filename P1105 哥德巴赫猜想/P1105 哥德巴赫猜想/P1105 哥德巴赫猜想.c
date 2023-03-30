#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int is_prime(int n);
int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		int i = 0;
		for (i = 2; i < n; i++)
		{
			if (is_prime(i) == 1 && is_prime(n - i) == 1)
			{
				printf("%d+%d\n", i, n - i);
				break;
			}
		}
	}
	return 0;
}
int is_prime(int n)
{
	int  i = 0;
	if (n == 2 || n == 3)
	{
		return 1;
	}
	else
	{
		for (i = 2; i <= sqrt(1.0 * n); i++)
		{
			if (n % i == 0)
			{
				return 0;
			}
		}
		return 1;
	}
}