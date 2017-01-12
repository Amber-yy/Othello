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
	/*��һ����������*/
	BlockType lastPlayer;
	/*��ǰ������*/
	BlockType board[BOARDSIZE][BOARDSIZE];
};

struct GameControl
{
	/*���ڼ�¼��ǰ����*/
	int currentStep;
	/*��һ���߶���λ�ã�������ʾ���*/
	Point lastPoint;
	/*��¼ӵ������Ȩ��һ��*/
	BlockType currentPlayer;
	/*���ڼ�¼��֣��ṩ��¼���ס�����ȹ��ܣ��ڰ��������64����ʵ������60����*/
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