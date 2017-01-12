#pragma once

#include <string>
#include <graphics.h>

#define BOARDSIZE 8
#define FPS 240

enum BlockType
{
	blank,
	black,
	white
};

enum OpType
{
	move,
	restart,
	regret
};

struct counter
{
	int total;
	int black;
	int white;
};

struct Point
{
	int x;
	int y;
};

struct operation
{
	OpType op;
	Point point;
};

struct Board
{
	/*上一个走棋的玩家*/
	BlockType lastPlayer;
	/*当前的棋盘*/
	BlockType board[BOARDSIZE][BOARDSIZE];
};

struct GameControl
{
	/*用于记录当前步数*/
	int currentStep;
	/*上一次走动的位置，用于显示光标*/
	Point lastPoint;
	/*记录拥有走子权的一方*/
	BlockType currentPlayer;
	/*用于记录棋局，提供记录棋谱、悔棋等功能，黑白棋最多走64步（实际上是60步）*/
	Board board[BOARDSIZE*BOARDSIZE];
};

struct PaintStruct
{
	Point normalQuit;
	Point hoverQuit;
	Point normalRegret;
	Point hoverRegret;
	Point promptGeo;
	std::string quit;
	std::string regret;
	std::string history;
	std::string prompt;
	GameControl game;
	PIMAGE originCanvas;
};