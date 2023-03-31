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
//void transformNum(char* str, int* num, int sz)//�ַ���תΪ����
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
	//���ַ�����ȡ���������
	char strNum1[100] = { 0 };
	char strNum2[100] = { 0 };
	while (scanf("%s %s", strNum1, strNum2) != EOF)
	{
		int sz1 = strlen(strNum1);
		int sz2 = strlen(strNum2);
		int num1[100] = { 0 };
		int num2[100] = { 0 };
		int ret[201] = { 0 };
		//ת���ַ�������������
		toNum(strNum1, num1, sz1);
		toNum(strNum2, num2, sz2);
		//����˻�
		int location = multi(num1, num2, ret, sz1, sz2);
		//���
		printNum(ret, location);
	}
	return 0;
}
// ���ַ�����ʽ������ת��Ϊ�����������ʽ
// ������strNum��ԭʼ�ַ�����num��ת������������飻sz��ԭʼ�ַ����ĳ���
void toNum(char* strNum, int* num, int sz)
{
	int i = 0;
	int j = sz - 1;
	// ���ַ�������ת��Ϊ��������
	for (i = 0; i < sz; i++, j--)
	{
		num[i] = strNum[j] - '0';// ���ַ�������ת��Ϊ��������
	}
}
int multi(int* num1, int* num2, int* ret,int sz1,int sz2)//ʵ��������������ˣ����ؽ���������Ч����
{
	int i = 0;
	int carry = 0;//��λ
	int location = 0;//��������е��±�
	//��λ��ˣ�����������뵽��Ӧ��λ����
	for (i = 0; i < sz1; i++)
	{
		int j = 0;
		location = i;//ÿ����˽���ӵ�iλ���
		for (j = 0; j < sz2; j++)
		{
			int temp = num2[j] * num1[i] + carry;//��ǰλ�ĳ˻����Ͻ�λ
			ret[location] += temp % 10;//���ϵ�ǰλ�ĳ˻��ͽ�λ
			if (ret[location] >= 10)//�����λ
			{
				carry = temp / 10 + ret[location] / 10;
				ret[location] %= 10;//���µ�ǰλ��ֵ
			}
			else
			{
				carry = temp / 10;
			}
			location++;//�ƶ�����һλ
		}
		//����ʣ��Ľ�λ
		while (carry)
		{
			ret[location++] += carry % 10;
			carry /= 10;
		}
	}
	return location;
}
void printNum(int* ret, int sz)//����˻����
{
	int i = 0;
	// ������������е�ÿ��Ԫ��
	for (i = sz - 1; i > -1; i--)
	{
		printf("%d", ret[i]);
	}
	printf("\n");
}