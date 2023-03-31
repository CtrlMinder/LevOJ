#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int factorialDigit(int num);//计算阶乘的位数
int main()
{
	int n = 0;//n组测试数据
	int i = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		int num = 0;
		scanf("%d", &num);
		int digit = factorialDigit(num);
		printf("%d\n", digit);
	}
	return 0;
}
int factorialDigit(int num)
{
	int i = 0;
	double digit = 0;
	for (i = 1; i <= num; i++)
	{
		digit += log10(1.0 * i);
	}
	return ((int)digit + 1);
}