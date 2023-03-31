#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int squareCounts(int length, int width);
int main()
{
	int length = 0;
	int width = 0;
	while (scanf("%d %d", &length, &width) != EOF)
	{
		int counts = squareCounts(length, width);
		printf("%d\n", counts);
	}
	return 0;
}
int squareCounts(int length, int width)
{
	if (length == 0 || width == 0)
	{
		return 0;
	}
	if (width > length)//目的：length大于width
	{
		int temp = width;
		width = length;
		length = temp;
	}
	int multiple = length / width;
	if (length % width == 0)
	{
		return (multiple);
	}
	else
	{
		return (multiple + squareCounts(length - multiple * width, width));
	}
}