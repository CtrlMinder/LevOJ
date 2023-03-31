#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>
//void transformNum(char* str, int* num, int sz);
//void printNum(int* num, int sz);
//int main()
//{
//	char strNum1[105] = { 0 };
//	char strNum2[105] = { 0 };
//	while (scanf("%s %s", strNum1, strNum2) != EOF)
//	{
//		int num1[105] = { 0 };
//		int num2[105] = { 0 };
//		int multiplication[205] = { 0 };
//		int location = 0;
//		int sz1 = strlen(strNum1);
//		int sz2 = strlen(strNum2);
//		transformNum(strNum1, num1, sz1);
//		transformNum(strNum2, num2, sz2);
//		for (int i = 0; i < sz1; i++)
//		{
//			int j = 0;
//			location = i;
//			int carry = 0;
//			for (j = 0; j < sz2; j++)
//			{
//				int temp = num2[j] * num1[i] + carry; 
//				multiplication[location] += temp % 10;
//				if (multiplication[location] >= 10)
//				{
//					carry = temp / 10 + multiplication[location] / 10;
//					multiplication[location] %= 10;
//				}
//				else
//				{
//					carry = temp / 10;
//				}
//				location++;
//			}
//			while (carry)
//			{
//				multiplication[location++] = carry % 10;
//				carry /= 10;
//			}
//		}
//		printNum(multiplication, location);
//	}
//	return 0;
//}
//void transformNum(char* str, int* num, int sz)//字符串转为数字
//{
//	int i = 0;
//	int j = 0;
//	for (i = sz - 1; i > -1; i--, j++)
//	{
//		num[j] = str[i] - 48;
//	}
//}
//void printNum(int* num, int sz)
//{
//	int i = 0;
//	for (i = sz - 1; i > -1; i--)
//	{
//		printf("%d", num[i]);
//	}
//	printf("\n");
//}
#include <stdio.h>
#include <string.h>
void toNum(char* strNum, int* num, int sz);
int multi(int* num1, int* num2, int* ret, int sz1, int sz2);
void printNum(int* ret, int sz);
int main()
{
	//用字符串读取输入的数字
	char strNum1[100] = { 0 };
	char strNum2[100] = { 0 };
	while (scanf("%s %s", strNum1, strNum2) != EOF)
	{
		int sz1 = strlen(strNum1);
		int sz2 = strlen(strNum2);
		int num1[100] = { 0 };
		int num2[100] = { 0 };
		int ret[201] = { 0 };
		//转换字符串到整型数组
		toNum(strNum1, num1, sz1);
		toNum(strNum2, num2, sz2);
		//计算乘积
		int location = multi(num1, num2, ret, sz1, sz2);
		//输出
		printNum(ret, location);
	}
	return 0;
}
// 将字符串形式的数字转化为整数数组的形式
// 参数：strNum，原始字符串；num，转换后的整数数组；sz，原始字符串的长度
void toNum(char* strNum, int* num, int sz)
{
	int i = 0;
	int j = sz - 1;
	// 将字符串逆序转化为整数数组
	for (i = 0; i < sz; i++, j--)
	{
		num[i] = strNum[j] - '0';// 将字符型数字转换为整型数字
	}
}
int multi(int* num1, int* num2, int* ret,int sz1,int sz2)//实现两个大整数相乘，返回结果数组的有效长度
{
	int i = 0;
	int carry = 0;//进位
	int location = 0;//结果数组中的下标
	//逐位相乘，并将结果加入到对应的位置中
	for (i = 0; i < sz1; i++)
	{
		int j = 0;
		location = i;//每次相乘结果从第i位相加
		for (j = 0; j < sz2; j++)
		{
			int temp = num2[j] * num1[i] + carry;//当前位的乘积加上进位
			ret[location] += temp % 10;//加上当前位的乘积和进位
			if (ret[location] >= 10)//处理进位
			{
				carry = temp / 10 + ret[location] / 10;
				ret[location] %= 10;//更新当前位的值
			}
			else
			{
				carry = temp / 10;
			}
			location++;//移动到下一位
		}
		//处理剩余的进位
		while (carry)
		{
			ret[location++] += carry % 10;
			carry /= 10;
		}
	}
	return location;
}
void printNum(int* ret, int sz)//输出乘积结果
{
	int i = 0;
	// 逆序输出数组中的每个元素
	for (i = sz - 1; i > -1; i--)
	{
		printf("%d", ret[i]);
	}
	printf("\n");
}