#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void getNum(int* num, int n);
int isMinial(int molecule, int denominator);
int main()
{
	int n = 0;
	scanf("%d", &n);
	while (n)
	{
		int num[605] = { 0 };
		getNum(num, n);
		int i = 0;
		int count = 0;
		for (i = 0; i < n - 1; i++)
		{
			int j = 0;
			for (j = i + 1; j < n; j++)
			{
				if (num[i] > num[j])
				{
					if (isMinial(num[j], num[i]) == 1)
					{
						count++;
					}
				}
				else
				{
					if (isMinial(num[i],num[j]) == 1)
					{
						count++;
					}
				}
			}
		}
		printf("%d\n", count);
		scanf("%d", &n);
	}
	return 0;
}
void getNum(int* num, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
}
int isMinial(int molecule, int denominator)
{
	int temp = denominator % molecule;
	while (temp)
	{
		denominator = molecule;
		molecule = temp;
		temp = denominator % molecule;
	}
	return molecule;
}