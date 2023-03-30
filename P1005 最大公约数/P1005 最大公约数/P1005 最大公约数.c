#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n = 0;
	int i = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		int num1 = 0;
		int num2 = 0;
		scanf("%d %d", &num1, &num2);
		int temp = 0;
		while (temp = num1 % num2)
		{
			num1 = num2;
			num2 = temp;
		}
		printf("%d\n", num2);
	}
	return 0;
}