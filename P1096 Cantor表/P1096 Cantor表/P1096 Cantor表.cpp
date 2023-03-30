#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		int eva = (int)((-1 + sqrt(1 + 8.0 * n)) / 2);
		double real = (-1 + sqrt(1 + 8.0 * n)) / 2;
		int col = 0;
		if (real - eva)
		{
			col = eva + 1;
		}
		else
		{
			col = eva;
		}
		int  ret = n - (col - 1  + (col - 1) * (col - 2) / 2);
		if (col % 2 == 1)
		{
			printf("%d/%d\n", col + 1 - ret, ret);
		}
		else
		{
			printf("%d/%d\n", ret, col + 1 - ret);
		}
	}
	return 0;
}

