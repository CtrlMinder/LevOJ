#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i = 0;
	char ch[500] = { 0 };
	for (i = 0; (ch[i] = getchar()) != '\n'; i++);
	ch[i] = '\0';
	int j = 0;
	for (j = 0; j < i; j++)
	{
		if (ch[j] >= 'A' && ch[j] <= 'Z')
		{
			ch[j] = ch[j] + 32;
		}
	}
	for (j = 0; j < i; j++)
	{
		printf("%c", ch[j]);
	}
	printf("\n");
	return 0;
}