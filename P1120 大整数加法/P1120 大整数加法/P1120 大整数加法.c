#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char num1[201] = { 0 };
//	char num2[201] = { 0 };
//	int integer1[201] = { 0 };
//	int integer2[201] = { 0 };
//	//��ȡ����������
//	while (scanf("%s %s", num1, num2) != EOF)
//	{
//		int i = 0;
//		int j = 0;
//		int sz1 = strlen(num1);
//		int sz2 = strlen(num2);
//		//���ַ���ת��Ϊ����
//		for (i = 0,j = sz1 - 1; i < sz1; i++,j--)
//		{
//			integer1[i] = num1[j] - 48;
//		}
//		for (i = 0,j = sz2 - 1; i < sz2; i++, j--)
//		{
//			integer2[i] = num2[j] - 48;
//		}
//		//sz2�������������λ��
//		if (sz1 > sz2)
//		{
//			int temp = sz1;
//			sz1 = sz2;
//			sz2 = temp;
//		}
//		//�������
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
//		//������
//		//�жϸ�λ�Ƿ�Ϊ0
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
//		//���
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
void printNum(int* num, int sz);//ȥ��ǰ��0�����
int main()
{
	char strNum1[201] = { 0 };//��������
	char strNum2[201] = { 0 };
	int num1[201] = { 0 };//����ת���������
	int num2[201] = { 0 };
	printf("��������������:\n");
	while (scanf("%s %s", strNum1, strNum2) != EOF)//��������
	{
		int sz1 = strlen(strNum1);//����������λ��
		int sz2 = strlen(strNum2);
		strToNum(strNum1, num1, sz1);
		strToNum(strNum2, num2, sz2);
		int max = (sz1 > sz2) ? sz1 : sz2;//��ȡ���������нϴ��λ��
		sum(num1, num2, max);
		printf("���Ϊ:\n");
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
		num[j++] = str[i] - '0';//char����ת��Ϊint����
	}
}
void sum(int* num1, int* num2, int max)//max - ������������λ��
{
	int i = 0;
	for (i = 0; i < max; i++)//�����λ�����λ����
	{
		num1[i] += num2[i];
		if (num1[i] >= 10)//��ӽ���������10��,��λȡģ10����һλ��1
		{
			num1[i] = num1[i] % 10;
			num1[i + 1]++;
		}
	}
}
void printNum(int* num, int sz)//ȥ��ǰ��0�����
{
	int i = 0;
	for (i = sz; i > -1; i--)//ȥ��ǰ��0
	{
		if (num[i])
		{
			break;
		}
	}
	for (; i > -1; i--)//�ӵ�һ������0������ʼ���
	{
		printf("%d", num[i]);
	}
	printf("\n");
}