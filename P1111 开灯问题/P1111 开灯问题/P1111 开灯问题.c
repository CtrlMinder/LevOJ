#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
	int light = 0;
	int peo = 0;
	while (scanf("%d %d", &light, &peo) != EOF)
	{
		int light_arr[10000] = { 0 };
		int i = 0;
		for (i = 1; i <= peo; i++)
		{
			int j = 0;
			for (j = i; j <= light; j+=i)
			{
				light_arr[j] = abs(light_arr[j] - 1);
			}
		}
		for (i = 1; i <= light; i++)
		{
			if (light_arr[i] == 1)
			{
				printf("%d\n", i);
			}
		}
	}
	return 0;
}