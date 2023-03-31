#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int getMethods(int apples, int plates);
int main()
{
	int apples = 0;
	int plates = 0;
	while(scanf("%d %d", &apples, &plates) != EOF)
	{
		int methods = getMethods(apples, plates);
		printf("%d\n", methods);
	}
	return 0;
}
int getMethods(int apples, int plates)
{
	if (plates == 1 || plates == 0)//û��ƻ������ֻ��һ������ 
	{
		return 1;
	}
	else if (apples < plates)//ƻ���������� 
	{
		return getMethods(apples, apples);
	}
	else
	{
		//��һ�����Ӳ���ƻ��+ÿһ�����Ӷ���ƻ�� 
		return (getMethods(apples, plates - 1) + getMethods(apples - plates, plates));
	}
}
