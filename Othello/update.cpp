#include "structs.h"

#include <string.h>

struct moveStruct
{
	bool autoFill;
	int x;
	int y;
	BlockType currentType;
	BlockType enemyType;
};

static bool canMoveToLeft(BlockType(*board)[BOARDSIZE],moveStruct moveInfo)
{
	bool findEnemy = false;
	for (int x = moveInfo.x-1; x >= 0; x--)
	{
		
		if (board[x][moveInfo.y] == blank)
		{
			break;
		}

		if (board[x][moveInfo.y] == moveInfo.enemyType)
		{
			findEnemy = true;
		}

		if (board[x][moveInfo.y] == moveInfo.currentType)
		{
			if (findEnemy)
			{
				if (moveInfo.autoFill)
				{
					for (int t = moveInfo.x - 1; t >x; t--)
					{
						board[t][moveInfo.y] = moveInfo.currentType;
					}
				}
				return true;
			}
			else
			{
				break;
			}
		}

	}
	
	return false;
}

static bool canMoveToRight(BlockType(*board)[BOARDSIZE], moveStruct moveInfo)
{
	bool findEnemy = false;
	for (int x = moveInfo.x+1; x<BOARDSIZE; x++)
	{

		if (board[x][moveInfo.y] == blank)
		{
			break;
		}

		if (board[x][moveInfo.y] == moveInfo.enemyType)
		{
			findEnemy = true;
		}

		if (board[x][moveInfo.y] == moveInfo.currentType)
		{
			if (findEnemy)
			{
				if (moveInfo.autoFill)
				{
					for (int t = moveInfo.x + 1; t <x; t++)
					{
						board[t][moveInfo.y] = moveInfo.currentType;
					}
				}
				return true;
			}
			else
			{
				break;
			}
		}

	}

	return false;
}

static bool canMoveToUp(BlockType(*board)[BOARDSIZE], moveStruct moveInfo)
{
	bool findEnemy = false;
	for (int y = moveInfo.y-1; y >= 0; y--)
	{

		if (board[moveInfo.x][y] == blank)
		{
			break;
		}

		if (board[moveInfo.x][y] == moveInfo.enemyType)
		{
			findEnemy = true;
		}

		if (board[moveInfo.x][y] == moveInfo.currentType)
		{
			if (findEnemy)
			{
				if (moveInfo.autoFill)
				{
					for (int t = moveInfo.y - 1; t>y; t--)
					{
						board[moveInfo.x][t] = moveInfo.currentType;
					}
				}
				return true;
			}
			else
			{
				break;
			}
		}

	}

	return false;
}

static bool canMoveToDown(BlockType(*board)[BOARDSIZE], moveStruct moveInfo)
{
	bool findEnemy = false;
	for (int y = moveInfo.y+1; y <BOARDSIZE; y++)
	{

		if (board[moveInfo.x][y] == blank)
		{
			break;
		}

		if (board[moveInfo.x][y] == moveInfo.enemyType)
		{
			findEnemy = true;
		}

		if (board[moveInfo.x][y] == moveInfo.currentType)
		{
			if (findEnemy)
			{
				if (moveInfo.autoFill)
				{
					for (int t = moveInfo.y + 1; t<y; t++)
					{
						board[moveInfo.x][t] = moveInfo.currentType;
					}
				}
				return true;
			}
			else
			{
				break;
			}
		}

	}

	return false;
}

static bool canMoveToLeftUp(BlockType(*board)[BOARDSIZE], moveStruct moveInfo)
{
	bool findEnemy = false;
	for (int y = moveInfo.y-1, x = moveInfo.x-1; x >= 0 && y >= 0; y--, x--)
	{

		if (board[x][y] == blank)
		{
			break;
		}

		if (board[x][y] == moveInfo.enemyType)
		{
			findEnemy = true;
		}

		if (board[x][y] == moveInfo.currentType)
		{
			if (findEnemy)
			{
				if (moveInfo.autoFill)
				{
					for (int tx = moveInfo.x - 1, ty = moveInfo.y - 1; tx>x&&ty>y; tx--, ty--)
					{
						board[tx][ty] = moveInfo.currentType;
					}
				}
				return true;
			}
			else
			{
				break;
			}
		}

	}

	return false;
}

static bool canMoveToRightDown(BlockType(*board)[BOARDSIZE], moveStruct moveInfo)
{
	bool findEnemy = false;
	for (int y = moveInfo.y+1, x = moveInfo.x+1; x <BOARDSIZE && y <BOARDSIZE; y++, x++)
	{

		if (board[x][y] == blank)
		{
			break;
		}

		if (board[x][y] == moveInfo.enemyType)
		{
			findEnemy = true;
		}

		if (board[x][y] == moveInfo.currentType)
		{
			if (findEnemy)
			{
				if (moveInfo.autoFill)
				{
					for (int tx = moveInfo.x + 1, ty = moveInfo.y + 1; tx<x&&ty<y; tx++, ty++)
					{
						board[tx][ty] = moveInfo.currentType;
					}
				}
				return true;
			}
			else
			{
				break;
			}
		}

	}

	return false;
}

static bool canMoveToLeftDown(BlockType(*board)[BOARDSIZE], moveStruct moveInfo)
{
	bool findEnemy = false;
	for (int y = moveInfo.y+1, x = moveInfo.x-1; x >=0 && y <BOARDSIZE; y++, x--)
	{

		if (board[x][y] == blank)
		{
			break;
		}

		if (board[x][y] == moveInfo.enemyType)
		{
			findEnemy = true;
		}

		if (board[x][y] == moveInfo.currentType)
		{
			if (findEnemy)
			{
				if (moveInfo.autoFill)
				{
					for (int tx = moveInfo.x - 1, ty = moveInfo.y + 1; tx<x&&ty<y; tx--, ty++)
					{
						board[tx][ty] = moveInfo.currentType;
					}
				}
				return true;
			}
			else
			{
				break;
			}
		}

	}

	return false;
}

static bool canMoveToRightUp(BlockType(*board)[BOARDSIZE], moveStruct moveInfo)
{
	bool findEnemy = false;
	for (int y = moveInfo.y-1, x = moveInfo.x+1; x <BOARDSIZE && y >=0; y--, x++)
	{

		if (board[x][y] == blank)
		{
			break;
		}

		if (board[x][y] == moveInfo.enemyType)
		{
			findEnemy = true;
		}

		if (board[x][y] == moveInfo.currentType)
		{
			if (findEnemy)
			{
				if (moveInfo.autoFill)
				{
					for (int tx = moveInfo.x + 1, ty = moveInfo.y - 1; tx<x&&ty<y; tx++, ty--)
					{
						board[tx][ty] = moveInfo.currentType;
					}
				}
				return true;
			}
			else
			{
				break;
			}
		}

	}

	return false;
}

bool canMove(GameControl *game,Point *point)
{
	BlockType currentType=game->currentPlayer;
	BlockType enemyType;
	BlockType (*board)[BOARDSIZE] = game->board[game->currentStep].board;

	moveStruct moveInfo;
	moveInfo.x = point->x;
	moveInfo.y = point->y;
	moveInfo.currentType = currentType;
	moveInfo.enemyType = enemyType;
	moveInfo.autoFill = false;

	/*已经有子，则不能再次落子*/
	if (board[point->x][point->y] != blank)
	{
		return false;
	}

	if (currentType == black)
	{
		enemyType = white;
	}
	else
	{
		enemyType = black;
	}

	/*向左搜索*/
	if (canMoveToLeft(board, moveInfo))
	{
		return true;
	}

	/*向右搜索*/
	if (canMoveToRight(board, moveInfo))
	{
		return true;
	}

	/*向上搜索*/
	if(canMoveToUp(board, moveInfo))
	{
		return true;
	}

	/*向下搜索*/
	if(canMoveToDown(board, moveInfo))
	{
		return true;
	}

	/*向左上搜索*/
	if(canMoveToLeftUp(board, moveInfo))
	{
		return true;
	}

	/*向右下搜索*/
	if(canMoveToRightDown(board, moveInfo))
	{
		return true;
	}

	/*向左下搜索*/
	if(canMoveToLeftDown(board, moveInfo))
	{
		return true;
	}

	/*向右上搜索*/
	if(canMoveToRightUp(board, moveInfo))
	{
		return true;
	}
	
	return false;
}

bool movePiece(GameControl *game, Point *point)
{
	BlockType currentType = game->currentPlayer;
	BlockType enemyType;
	BlockType(*prevBoard)[BOARDSIZE] = game->board[game->currentStep].board;
	BlockType(*board)[BOARDSIZE] = game->board[game->currentStep+1].board;
	
	/*步数+1*/
	game->currentStep++;

	/*复制当前棋局到新的棋盘*/
	memcpy(board, prevBoard, BOARDSIZE*BOARDSIZE * sizeof(BlockType));
	game->board[game->currentStep + 1].lastPlayer=currentType;

	moveStruct moveInfo;
	moveInfo.x = point->x;
	moveInfo.y = point->y;
	moveInfo.currentType = currentType;
	moveInfo.enemyType = enemyType;
	moveInfo.autoFill = true;

	/*按照规则翻转棋盘*/
	canMoveToUp(board, moveInfo);
	canMoveToDown(board, moveInfo);
	canMoveToLeft(board, moveInfo);
	canMoveToRight(board, moveInfo);
	canMoveToLeftUp(board, moveInfo);
	canMoveToRightUp(board, moveInfo);
	canMoveToLeftDown(board, moveInfo);
	canMoveToRightDown(board, moveInfo);

	game->lastPoint = *point;
	game->currentPlayer = enemyType;

	if (game->currentStep == BOARDSIZE*BOARDSIZE)
	{
		return false;
	}

	/*检查是否能落子，是则正常返回，否则移交棋权*/
	Point target;
	for (int x = 0; x < BOARDSIZE; x++)
	{
		for (int y = 0; y < BOARDSIZE; y++)
		{
			target.x = x;
			target.y = y;
			if (canMove(game, &target))//找到第一个能落子的位置
			{
				return true;
			}
		}
	}

	/*若一方无子可走，则试图将棋权转移，若另一方也无子可走，则结束对局*/
	game->currentPlayer = currentType;
	for (int x = 0; x < BOARDSIZE; x++)
	{
		for (int y = 0; y < BOARDSIZE; y++)
		{
			target.x = x;
			target.y = y;
			if (canMove(game, &target))
			{
				return true;
			}
		}
	}

	return false;
}
