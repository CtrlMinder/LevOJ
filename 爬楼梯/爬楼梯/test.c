#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int min(int a, int b);
int main()
{
	int t, i, j, m, n;
	int ch[100005] = { 0 }, ch1[100005] = { 0 };
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		int ld;
		scanf("%d %d", &m, &n);
		for (j = 0; j < n; j++)
			scanf("%d", &ch[j]);
		ch1[0] = ch[0];
		ch1[1] = ch[1];
		for (j = 2; j < n; j++)
			ch1[j] = min(ch1[j - 1], ch1[j - 2]) + ch[j];
		ld = m - ch1[j - 1];
		if (ld > 0)
			printf("%d\n", ld);
		else
			printf("Can't get the top!\n");
	}
	return 0;
}
int min(int a, int b)
{
	if (a >= b)
		return b;
	else
		return a;
}