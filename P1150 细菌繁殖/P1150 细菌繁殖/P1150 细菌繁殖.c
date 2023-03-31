#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int getDays(int originMonth, int originDay, int finalMonth, int finalDay);
int main()
{
	int n = 0;
	int j = 0;
	int originMonth = 0;
	int originDay = 0;
	long originNum = 0;
	int finalMonth = 0;
	int finalDay = 0;
	scanf("%d", &n);
	for (j = 0; j < n; j++)
	{
		scanf("%d %d %ld %d %d", &originMonth, &originDay, &originNum, &finalMonth, &finalDay);
		int days = getDays(originMonth, originDay, finalMonth, finalDay);
		int i = 0;
		for (i = 0; i < days; i++)
		{
			originNum = originNum << 1;
		}
		printf("%ld\n", originNum);
	}
	return 0;
}
int getDays(int originMonth, int originDay, int finalMonth, int finalDay)//计算繁殖的天数
{
	int i = 0;
	int days = 0;
	for (i = originMonth; i < finalMonth; i++)
	{
		switch (i)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			days += 31;
			break;
		case 2:
			days += 28;
			break;
		default:
			days += 30;
			break;
		}
	}
	days = days - originDay + finalDay;
	return days;
}