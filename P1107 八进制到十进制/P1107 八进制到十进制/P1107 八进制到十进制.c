#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n = 0;
	while (1)
	{
		scanf("%o", &n);
		if (0 == n)
			break;
		else
			printf("%d\n", n);
	}
	return 0;
}