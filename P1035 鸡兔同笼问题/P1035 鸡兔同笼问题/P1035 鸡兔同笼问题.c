#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int m = 0;
	int n = 0;
	while (scanf("%d %d", &m, &n) != EOF)
	{
		int i = 1;
		int j = 0;
		int mark = 0;
		for (i = 0; i <= m; i++)
		{
			for (j = 0; j <= m; j++)
			{
				if ((i + j == m) && ((2 * i + 4 * j) == n))
				{
					mark = 1;
					break;
				}
			}
			if (mark == 1)
			{
				break;
			}
		}
		if (mark == 0)
		{
			printf("-1 -1\n");
		}
		else
		{
			printf("%d %d\n", i, j);
		}
	}
	return 0;
}
