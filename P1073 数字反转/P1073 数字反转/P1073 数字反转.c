#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
void PrintNumber(char *read_number,int sz,int dead_line);
int main()
{
	char read_number[100] = { 0 };
	int i = 0;
	while (scanf("%s", read_number) != EOF)//°´×Ö·û¶Áruntime error
	{
		/*for (i = 1; (read_number[i] = getchar()) != '\n'; i++);
		read_number[i] = '\0';*/
		int sz = strlen(read_number);
		if (read_number[0] == '-')
		{
			printf("-");
			PrintNumber(read_number, sz, 0);
		}
		else
		{
			PrintNumber(read_number, sz, -1);
		}
	}
	return 0;
}
void PrintNumber(char* read_number, int sz, int dead_line)
{
	int i = 0;
	for (i = sz - 1; i > dead_line; i--)
	{
		if (read_number[i] == '0')
			continue;
		else
			break;
	}
	if (i != dead_line)
	{
		for (; i > dead_line; i--)
		{
			printf("%d", read_number[i] - 48);
		}
	}
	printf("\n");
}