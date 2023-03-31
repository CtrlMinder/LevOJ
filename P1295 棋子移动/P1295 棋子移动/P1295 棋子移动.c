#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void initboard(char* checkerboard, int chessPieces);
void moveChess(char* checkerboard, int chessPieces);
void move(char* checkerboard, int origin1, int origin2, int final1, int final2);
int main()
{
	int chessPieces = 0;
	while (scanf("%d", &chessPieces) != EOF)
	{
		char checkerboard[10000] = { 0 };
		initboard(checkerboard, chessPieces);
		moveChess(checkerboard, chessPieces);
	}
	return 0;
}
void initboard(char* checkerboard, int chessPieces)
{
	int i = 0;
	for (i = 1; i <= chessPieces; i++)
	{
		checkerboard[i] = 'O';
	}
	for (i = chessPieces + 1; i <= 2 * chessPieces; i++)
	{
		checkerboard[i] = 'X';
	}
}
void move(char* checkerboard, int origin1, int origin2, int final1, int final2)
{
	checkerboard[final1] = checkerboard[origin1];
	checkerboard[final2] = checkerboard[origin2];
	printf("%d,%d-->%d,%d\n", origin1, origin2, final1, final2);
}
void moveChess(char* checkerboard, int chessPieces)
{
	if (chessPieces == 4)
	{
		move(checkerboard, 4, 5, 9, 10);
		move(checkerboard, 8, 9, 4, 5);
		move(checkerboard, 2, 3, 8, 9);
		move(checkerboard, 7, 8, 2, 3);
		move(checkerboard, 1, 2, 7, 8);
	}
	else if (chessPieces < 4)
	{
		return;
	}
	else
	{
		move(checkerboard, chessPieces, chessPieces + 1, 2 * chessPieces + 1, 2 * chessPieces + 2);
		move(checkerboard, 2 * chessPieces - 1, 2 * chessPieces, chessPieces, chessPieces + 1);
		moveChess(checkerboard, chessPieces - 1);
	}
}