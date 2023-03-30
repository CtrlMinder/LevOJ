#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	char ch[100] = { 0 };
	int i = 0;
	int k = 0;
	scanf("%d", &k);
	getchar();
	for (i = 0; (ch[i] = getchar()) != '\n'; i++);
	ch[i] = '\0';
	k = k % (i - 1);
	int j = 0;
	int sz = i;
	for (i = 0; i < k; i++)
	{
		char temp = ch[0];
		for (j = 0; j < sz - 1; j++)
		{
			ch[j] = ch[j + 1];
		}
		ch[sz - 1] = temp;
	}
	for (i = 0; i < sz; i++)
	{
		printf("%c", ch[i]);
	}
	printf("\n");
	return 0;
}