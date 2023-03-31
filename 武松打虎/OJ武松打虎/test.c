#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void Sort(long arr[], int);//ц╟ещеепР
int main()
{
	long arr[1000] = { 0 };
	long t = 0;
	int n = 0;
	while ((scanf("%d%ld", &n, &t)) != EOF)
	{
		int i = 0;
		int count = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%ld", &arr[i]);
		}
		Sort(arr, n);
		for (i = 0; i < n; i++)
		{
			t = t - arr[i];
			if (t >= 0)
			{
				count++;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
void Sort(long arr[], int n)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}