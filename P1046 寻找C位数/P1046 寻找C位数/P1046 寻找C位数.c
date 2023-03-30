#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n = 0;
	int arr[100] = { 0 };
	while (scanf("%d", &n) != EOF)
	{
		int i = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}
		printf("%d\n", arr[n / 2]);
	}
	return 0;
}