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

	/*�Ѿ����ӣ������ٴ�����*/
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

	/*��������*/
	if (canMoveToLeft(board, moveInfo))
	{
		return true;
	}

	/*��������*/
	if (canMoveToRight(board, moveInfo))
	{
		return true;
	}

	/*��������*/
	if(canMoveToUp(board, moveInfo))
	{
		return true;
	}

	/*��������*/
	if(canMoveToDown(board, moveInfo))
	{
		return true;
	}

	/*����������*/
	if(canMoveToLeftUp(board, moveInfo))
	{
		return true;
	}

	/*����������*/
	if(canMoveToRightDown(board, moveInfo))
	{
		return true;
	}

	/*����������*/
	if(canMoveToLeftDown(board, moveInfo))
	{
		return true;
	}

	/*����������*/
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
	
	/*����+1*/
	game->currentStep++;

	/*���Ƶ�ǰ��ֵ��µ�����*/
	memcpy(board, prevBoard, BOARDSIZE*BOARDSIZE * sizeof(BlockType));
	game->board[game->currentStep + 1].lastPlayer=currentType;

	moveStruct moveInfo;
	moveInfo.x = point->x;
	moveInfo.y = point->y;
	moveInfo.currentType = currentType;
	moveInfo.enemyType = enemyType;
	moveInfo.autoFill = true;

	/*���չ���ת����*/
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

	/*����Ƿ������ӣ������������أ������ƽ���Ȩ*/
	Point target;
	for (int x = 0; x < BOARDSIZE; x++)
	{
		for (int y = 0; y < BOARDSIZE; y++)
		{
			target.x = x;
			target.y = y;
			if (canMove(game, &target))//�ҵ���һ�������ӵ�λ��
			{
				return true;
			}
		}
	}

	/*��һ�����ӿ��ߣ�����ͼ����Ȩת�ƣ�����һ��Ҳ���ӿ��ߣ�������Ծ�*/
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
