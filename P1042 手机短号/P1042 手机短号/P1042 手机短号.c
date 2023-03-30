#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	char mobile_number[12] = { 0 };
	int i = 0;
	for (i = 0; (mobile_number[i] = getchar()) != '\n'; i++);
	printf("6");
	for (i = 6; i < 11; i++)
	{
		printf("%d", mobile_number[i] - 48);
	}
	printf("\n");
	return 0;
}