#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
void str_to_num(char* str1, int* num, int sz);
void sub_num(int* num1, int* num2, int sz);
void print_num(int* num, int sz);
int main()
{
	char str_num1[201] = { 0 };
	char str_num2[201] = { 0 };
	while (scanf("%s %s", str_num1, str_num2) != EOF)
	{
		int num1[201] = { 0 };
		int num2[201] = { 0 };
		int i = 0;
		int j = 0;
		int sz1 = strlen(str_num1);
		int sz2 = strlen(str_num2);
		str_to_num(str_num1, num1, sz1);
		str_to_num(str_num2, num2, sz2);
		sub_num(num1, num2, sz1);
		print_num(num1, sz1);
	}
	return 0;
}
void str_to_num(char* str1, int* num, int sz)//字符串转换成数字
{
	int i = 0;
	int j = 0;
	for (i = 0, j = sz - 1; i < sz; i++, j--)
	{
		num[i] = str1[j] - 48;
	}
}
void sub_num(int* num1, int* num2, int sz)//大整数减法
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		int temp_num = num1[i] - num2[i];
		if (temp_num < 0)
		{
			num1[i + 1]--;
			num1[i] = 10 + temp_num;
		}
		else
		{
			num1[i] = temp_num;
		}
	}
}
void print_num(int* num, int sz)//打印数字
{
	int i = 0;
	for (i = sz - 1; i > -1; i--)
	{
		if (num[i] == 0)
		{
			continue;
		}
		else
		{
			break;
		}
	}
	for (; i > -1; i--)
	{
		printf("%d", num[i]);
	}
	printf("\n");
}