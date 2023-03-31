#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char num1[201] = { 0 };
//	char num2[201] = { 0 };
//	int integer1[201] = { 0 };
//	int integer2[201] = { 0 };
//	//读取两个大整数
//	while (scanf("%s %s", num1, num2) != EOF)
//	{
//		int i = 0;
//		int j = 0;
//		int sz1 = strlen(num1);
//		int sz2 = strlen(num2);
//		//将字符串转化为整型
//		for (i = 0,j = sz1 - 1; i < sz1; i++,j--)
//		{
//			integer1[i] = num1[j] - 48;
//		}
//		for (i = 0,j = sz2 - 1; i < sz2; i++, j--)
//		{
//			integer2[i] = num2[j] - 48;
//		}
//		//sz2存入的最大的数的位数
//		if (sz1 > sz2)
//		{
//			int temp = sz1;
//			sz1 = sz2;
//			sz2 = temp;
//		}
//		//进行相加
//		for (i = 0; i < sz2; i++)
//		{
//			int temp_sum = integer1[i] + integer2[i];
//			if (temp_sum >= 10)
//			{
//				integer1[i + 1]++;
//				integer1[i] = temp_sum % 10;
//			}
//			else
//			{
//				integer1[i] = temp_sum;
//			}
//		}
//		//结果输出
//		//判断高位是否为0
//		for (i = sz2; i > 0; i--)
//		{
//			if (integer1[i] == 0)
//			{
//				continue;
//			}
//			else
//			{
//				break;
//			}
//		}
//		//输出
//		for (; i > -1; i--)
//		{
//			printf("%d", integer1[i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
#include <stdio.h>
#include <string.h>
void strToNum(char* str, int* num, int sz);
void sum(int* num1, int* num2, int max);
void printNum(int* num, int sz);//去除前导0并输出
int main()
{
	char strNum1[201] = { 0 };//接收整数
	char strNum2[201] = { 0 };
	int num1[201] = { 0 };//接收转化后的整数
	int num2[201] = { 0 };
	printf("请输入两个整数:\n");
	while (scanf("%s %s", strNum1, strNum2) != EOF)//多组输入
	{
		int sz1 = strlen(strNum1);//计算整数的位数
		int sz2 = strlen(strNum2);
		strToNum(strNum1, num1, sz1);
		strToNum(strNum2, num2, sz2);
		int max = (sz1 > sz2) ? sz1 : sz2;//获取两个整数中较大的位数
		sum(num1, num2, max);
		printf("结果为:\n");
		printNum(num1, max);
	}
	return 0;
}
void strToNum(char* str, int* num, int sz)
{
	int i = 0;
	int j = 0;
	for (i = sz - 1; j < sz; i--)
	{
		num[j++] = str[i] - '0';//char类型转化为int类型
	}
}
void sum(int* num1, int* num2, int max)//max - 两个数中最大的位数
{
	int i = 0;
	for (i = 0; i < max; i++)//从最低位到最高位遍历
	{
		num1[i] += num2[i];
		if (num1[i] >= 10)//相加结果如果大于10，,该位取模10，下一位加1
		{
			num1[i] = num1[i] % 10;
			num1[i + 1]++;
		}
	}
}
void printNum(int* num, int sz)//去除前导0并输出
{
	int i = 0;
	for (i = sz; i > -1; i--)//去除前导0
	{
		if (num[i])
		{
			break;
		}
	}
	for (; i > -1; i--)//从第一个不是0的数开始输出
	{
		printf("%d", num[i]);
	}
	printf("\n");
}