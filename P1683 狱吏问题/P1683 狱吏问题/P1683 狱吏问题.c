#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	int rooms = 0;//������
	while ((scanf("%d", &rooms)) != EOF)
	{
		int* roomId = (int*)calloc(rooms + 1,sizeof(int));
		int i = 0;
		//��������
		for (i = 0; i < rooms; i++)//��n��
		{
			int j = 0;
			for (j = 1; j <= rooms; j++)
			{
				if (j % (i + 1) == 0)
				{
					roomId[j] = abs(roomId[j] - 1);
				}
			}
		}
		//���
		for (i = 1; i <= rooms; i++)
		{
			if (roomId[i] == 1)
				printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}