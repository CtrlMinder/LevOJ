#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int sumOfApproxiamte(int num);//求约数之和
int main()
{
	int numberOfGroups = 0;
	scanf("%d", &numberOfGroups);//numberOfGroups组数据
	int i = 0;
	for (i = 0; i < numberOfGroups; i++)
	{
		int num1 = 0;
		int num2 = 0;
		scanf("%d %d", &num1, &num2);
		int sum1 = sumOfApproxiamte(num1);
		int sum2 = sumOfApproxiamte(num2);
		if (sum1 == num2 && sum2 == num1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
int sumOfApproxiamte(int num)
{
	int i = 0;
	int sum = 0;
	for (i = 1; i <= sqrt(1.0 * num); i++)
	{
		if (num % i == 0 && i != 1)
		{
			sum = sum + i + (num / i);
		}
	}
	return sum + 1;
}