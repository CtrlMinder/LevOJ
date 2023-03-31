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
	if (plates == 1 || plates == 0)//没有苹果或者只有一个盘子 
	{
		return 1;
	}
	else if (apples < plates)//苹果比盘子少 
	{
		return getMethods(apples, apples);
	}
	else
	{
		//有一个盘子不放苹果+每一个盘子都有苹果 
		return (getMethods(apples, plates - 1) + getMethods(apples - plates, plates));
	}
}
