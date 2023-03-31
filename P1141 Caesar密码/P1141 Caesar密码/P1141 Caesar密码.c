#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//定义全局变量用于存放密码消息
char code[140005] = { 0 };
void getCode(char* code);
void printCode(char* codeBak);
int main()
{
	char begin[12] = { 0 };
	char conclude[5] = { 0 };
	scanf("%s", begin);
	while (!(strcmp(begin, "START")))
	{
		getchar();
		getCode(code);
		scanf(" %s", conclude);
		int sz = strlen(code);
		int i = 0;
		for (i = 0; i < sz; i++)
		{
			if (code[i] >= 'F' && code[i] <= 'Z')
			{
				code[i] -= 5;
			}
			else if(code[i] >= 'A' && code[i] < 'F')
			{
				code[i] += 21;
			}
		}
		printCode(code);
		scanf(" %s", begin);
	}
	return 0;
}
void getCode(char* codeBak)
{
	int i = 0;
	for (i = 0; (codeBak[i] = getchar()) != '\n'; i++);
	codeBak[i] = '\0';
}
void printCode(char* codeBak)
{
	int i = 0;
	for (i = 0; codeBak[i] != '\0'; i++)
	{
		printf("%c", codeBak[i]);
	}
	printf("\n");
}