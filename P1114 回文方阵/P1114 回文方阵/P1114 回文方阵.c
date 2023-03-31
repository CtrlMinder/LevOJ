#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		int i = 0;
		int j = n;
		int k = 1;
		int spiral_array[11][11] = { 0 };
		while (k <= n * n)
		{
			while (i < n && !spiral_array[i + 1][j])
				spiral_array[++i][j] = k++;
			while (j > 1 && !spiral_array[i][j - 1])
				spiral_array[i][--j] = k++;
			while (i > 1 && !spiral_array[i - 1][j])
				spiral_array[--i][j] = k++;
			while (j < n && !spiral_array[i][j + 1])
				spiral_array[i][++j] = k++;
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				printf("%d ", spiral_array[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}