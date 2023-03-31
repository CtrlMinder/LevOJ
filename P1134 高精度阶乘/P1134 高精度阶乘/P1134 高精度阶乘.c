#define _CRT_SECURE_NO_WARNINGS 1
//方法1 - 转化为加法
// 缺陷：效率过低，时间复杂度和空间复杂度过高
//#include <stdio.h>
//#include <string.h>
//int generateFactorial(int* factorial, int num);
//void sumNum(int* num, int* num1, int sz);
//void printFactorial(int* factorial, int sz);
//int main()
//{
//	int num = 0;
//	while (scanf("%d", &num) != EOF)
//	{
//		int factorial[3005] = { 0 };//存放阶乘的数组
//		int sz = generateFactorial(factorial, num);
//		printFactorial(factorial, sz);
//	}
//	return 0;
//}
//int generateFactorial(int* factorial, int num)//计算阶乘
//{
//	if (num == 0 || num == 1)//0或1的阶乘
//	{
//		factorial[0] = 1;
//		return 1;
//	}
//	else
//	{
//		int i = 0;
//		factorial[0] = 1;
//		int sz = 3000;
//		for (i = 2; i <= num; i++)
//		{
//			int j = 0;
//			int factorialBak[3005] = { 0 };
//			memcpy(factorialBak, factorial, sizeof(int) * sz);
//			for (j = 1; j < i; j++)
//			{
//				sumNum(factorial, factorialBak, sz);
//				//sz++;
//			}
//		}
//		return sz;
//	}
//}
//void sumNum(int* num, int* num1, int sz)//高精度求和
//{
//	int k = 0;
//	for (k = 0; k < sz + 1; k++)
//	{
//		int temp = num[k] + num1[k];
//		if (temp >= 10)
//		{
//			num[k + 1]++;
//			num[k] = temp - 10;
//		}
//		else
//		{
//			num[k] = temp;
//		}
//	}
//}
//void printFactorial(int* factorial, int sz)//输出阶乘
//{
//	int i = 0;
//	for (i = sz - 1; i > -1; i--)//去除前导0
//	{
//		if (factorial[i] == 0)
//		{
//			continue;
//		}
//		else
//		{
//			break;
//		}
//	}
//	for (; i > -1; i--)
//	{
//		printf("%d", factorial[i]);
//	}
//	printf("\n");
//}


//方法2
//效率高
//#include <stdio.h>
//int main()
//{
//	int num = 0;
//	while (scanf("%d", &num) != EOF)
//	{
//		int factorial[3005] = { 1 };//存储阶乘
//		int carry = 0;//进位的大小
//		int digitLocation = 1;//阶乘的位数
//		int i = 0;
//		int j = 0;
//		for (i = 1; i <= num; i++)
//		{
//			for (j = 0; j < digitLocation; j++)
//			{
//				int temp = factorial[j] * i + carry;
//				factorial[j] = temp % 10;
//				carry = temp / 10;
//			}
//			while (carry)
//			{
//				factorial[digitLocation++] = carry % 10;
//				carry = carry / 10;
//			}
//		}
//		for (i = digitLocation - 1; i > -1; i--)
//		{
//			printf("%d", factorial[i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
#include <stdio.h>
int calFactorial(int* factorial, int n);
void printFactorial(int* factorial, int location);
int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)//多组输入
	{
		int factorial[3005] = { 1 };//用于存储阶乘 - 个位初始化为1
		int location = calFactorial(factorial, n);
		printFactorial(factorial, location);
	}
	return 0;
}
int calFactorial(int* factorial, int n)//计算n的阶乘
{
	int carry = 0;//进位
	int location = 1;//当前阶乘的位数
	int i = 0;
	for (i = 1; i <= n; i++)
	{
		int j = 0;
		for (j = 0; j < location; j++)
		{
			factorial[j] = factorial[j] * i + carry;//结果为乘完加上之前的进位
			carry = factorial[j] / 10;
			factorial[j] %= 10;//获取进位
		}
		while (carry)//进行进位操作
		{
			factorial[location++] = carry % 10;
			carry /= 10;
		}
	}
	return location;
}
void printFactorial(int* factorial, int location)//输出
{
	int i = 0;
	for (i = location - 1; i > -1; i--)//输出阶乘结果
	{
		printf("%d", factorial[i]);
	}
	printf("\n");
}