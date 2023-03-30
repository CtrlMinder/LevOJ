#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
void spiralMatrix(int(*matrix)[10], int (*matrixBak)[10],
	long long(*sumMatrix)[10], int cir, int row);
int main()
{
	int row = 0;//行数
	while (scanf("%d", &row) != EOF)
	{
		int matrix[10][10] = { 0 };//存放矩阵
		int matrixBak[10][10] = { 0 };//存放每次旋转的结果
		long long sumMatrix[10][10] = { 0 };//矩阵的和
		int k = 0;//最大旋转数
		int i = 0;
		int j = 0;
		//读取矩阵
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < row; j++)
			{
				scanf("%d", &matrix[i][j]);
				sumMatrix[i][j] = matrix[i][j];
			}
		}
		scanf("%d", &k);
		//循环数
		int circle = (k + 1) / 4;
		//余数
		k = (k + 1) % 4;
		spiralMatrix(matrix, matrixBak, sumMatrix, 3, row);
		//一次完整的循环
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < row; j++)
			{
				sumMatrix[i][j] *= circle;
			}
		}
		spiralMatrix(matrix, matrixBak, sumMatrix, k, row);
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < row; j++)
			{
				printf("%lld ",sumMatrix[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
void spiralMatrix(int(*matrix)[10], int (*matrixBak)[10],
	long long(*sumMatrix)[10], int cir, int row)
{
	int i = 0;
	for (i = 0; i < cir; i++)
	{
		//旋转cir次
		int j = 0;
		for (j = 0; j < row; j++)
		{
			int k = 0;
			for (k = 0; k < row; k++)
			{
				matrixBak[k][row - j - 1] = matrix[j][k];
				sumMatrix[k][row - j - 1] += matrixBak[k][row - j - 1];
			}
		}
		memcpy(matrix, matrixBak, sizeof(int) * 100);
	}
}