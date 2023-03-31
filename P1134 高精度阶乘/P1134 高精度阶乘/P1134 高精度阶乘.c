#define _CRT_SECURE_NO_WARNINGS 1
//����1 - ת��Ϊ�ӷ�
// ȱ�ݣ�Ч�ʹ��ͣ�ʱ�临�ӶȺͿռ临�Ӷȹ���
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
//		int factorial[3005] = { 0 };//��Ž׳˵�����
//		int sz = generateFactorial(factorial, num);
//		printFactorial(factorial, sz);
//	}
//	return 0;
//}
//int generateFactorial(int* factorial, int num)//����׳�
//{
//	if (num == 0 || num == 1)//0��1�Ľ׳�
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
//void sumNum(int* num, int* num1, int sz)//�߾������
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
//void printFactorial(int* factorial, int sz)//����׳�
//{
//	int i = 0;
//	for (i = sz - 1; i > -1; i--)//ȥ��ǰ��0
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


//����2
//Ч�ʸ�
//#include <stdio.h>
//int main()
//{
//	int num = 0;
//	while (scanf("%d", &num) != EOF)
//	{
//		int factorial[3005] = { 1 };//�洢�׳�
//		int carry = 0;//��λ�Ĵ�С
//		int digitLocation = 1;//�׳˵�λ��
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
	while (scanf("%d", &n) != EOF)//��������
	{
		int factorial[3005] = { 1 };//���ڴ洢�׳� - ��λ��ʼ��Ϊ1
		int location = calFactorial(factorial, n);
		printFactorial(factorial, location);
	}
	return 0;
}
int calFactorial(int* factorial, int n)//����n�Ľ׳�
{
	int carry = 0;//��λ
	int location = 1;//��ǰ�׳˵�λ��
	int i = 0;
	for (i = 1; i <= n; i++)
	{
		int j = 0;
		for (j = 0; j < location; j++)
		{
			factorial[j] = factorial[j] * i + carry;//���Ϊ�������֮ǰ�Ľ�λ
			carry = factorial[j] / 10;
			factorial[j] %= 10;//��ȡ��λ
		}
		while (carry)//���н�λ����
		{
			factorial[location++] = carry % 10;
			carry /= 10;
		}
	}
	return location;
}
void printFactorial(int* factorial, int location)//���
{
	int i = 0;
	for (i = location - 1; i > -1; i--)//����׳˽��
	{
		printf("%d", factorial[i]);
	}
	printf("\n");
}