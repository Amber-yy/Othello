#include "structs.h"
#include "functions.h"
#include <graphics.h>
#include <string>

static PIMAGE iniInterface()
{
	initgraph(900, 640);
	setrendermode(RENDER_MANUAL);
	setcaption("黑白棋");
	PIMAGE canvas = newimage(900, 640);
	settarget(canvas);

	setfillcolor(EGERGB(0, 101, 0));
	bar(0, 0, 640, 640);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2)
			{
				setfillcolor(EGERGB(0, 152, 0));
			}
			else
			{
				setfillcolor(EGERGB(101, 204, 0));
			}
			bar(j * 80 + 2, i * 80 + 2, j * 80 + 78, i * 80 + 78);
		}
	}

	setfillcolor(0xFFFFFF);
	bar(650, 100, 890, 300);
	bar(690, 355, 850, 445);
	bar(690, 505, 850, 595);

	settarget(nullptr);

	return canvas;
}

static void repaint(PaintStruct *painter,bool first,bool second)
{
	cleardevice();
	PIMAGE tempImage = newimage(900,640);
	putimage(tempImage, 0, 0, painter->originCanvas);

	settarget(tempImage);

	BlockType(*board)[BOARDSIZE] = painter->game.board[painter->game.currentStep].board;

	for (int x = 0; x < BOARDSIZE; x++)
	{
		for (int y = 0; y < BOARDSIZE; y++)
		{
			if (board[x][y] == black)
			{
				setcolor(0x000000);
				setfillcolor(0x000000);
				fillellipse(x*80+40,y*80+40,36,36);
			}
			else if (board[x][y] == white)
			{
				setcolor(0xffffff);
				setfillcolor(0xffffff);
				fillellipse(x * 80 + 40, y * 80 + 40, 36, 36);
			}
		}
	}

	setcolor(0xffffff);
	setbkmode(TRANSPARENT);
	setfont(20, 0, "楷体");
	outtextxy(painter->promptGeo.x, painter->promptGeo.y, painter->prompt.c_str());
	
	setcolor(0x000000);
	setbkmode(TRANSPARENT);
	outtextrect(650, 100, 890, 300,painter->history.c_str());

	if (first)
	{
		setfont(40,0,"楷体");
		outtextxy(painter->hoverRegret.x, painter->hoverRegret.y,painter->regret.c_str());
	}
	else
	{
		setfont(35, 0, "楷体");
		outtextxy(painter->normalRegret.x, painter->normalRegret.y, painter->regret.c_str());
	}

	if (second)
	{
		setfont(40, 0, "楷体");
		outtextxy(painter->hoverQuit.x,painter->hoverQuit.y, painter->quit.c_str());
	}
	else
	{
		setfont(35, 0, "楷体");
		outtextxy(painter->normalQuit.x, painter->normalQuit.y, painter->quit.c_str());
	}

	settarget(nullptr);

	putimage(0,0,tempImage);
	delimage(tempImage);
}

static void iniData(PaintStruct *painter)
{
	painter->originCanvas = iniInterface();
	painter->quit = "重新开局";
	painter->regret = "悔棋";
	painter->prompt = "当前玩家：黑方";

	painter->history = "游戏开始\n轮到黑方走子\n黑方有2颗棋子\n白方有2颗棋子\n总共有4颗棋子";
	iniBoard(&painter->game);

	setfont(20, 0, "楷体");
	painter->promptGeo.x = 640 + (260 - textwidth(painter->prompt.c_str())) / 2;
	painter->promptGeo.y = 0 + (100 - textheight(painter->prompt.c_str())) / 2;

	setfont(35, 0, "楷体");
	painter->normalQuit.x = 690 + (160 - textwidth(painter->quit.c_str())) / 2;
	painter->normalQuit.y = 505 + (90 - textheight(painter->quit.c_str())) / 2;
	painter->normalRegret.x = 690 + (160 - textwidth(painter->regret.c_str())) / 2;
	painter->normalRegret.y = 355 + (90 - textheight(painter->regret.c_str())) / 2;

	setfont(40, 0, "楷体");
	painter->hoverQuit.x = 690 + (160 - textwidth(painter->quit.c_str())) / 2;
	painter->hoverQuit.y = 505 + (90 - textheight(painter->quit.c_str())) / 2;
	painter->hoverRegret.x = 690 + (160 - textwidth(painter->regret.c_str())) / 2;
	painter->hoverRegret.y = 355 + (90 - textheight(painter->regret.c_str())) / 2;

	repaint(painter, false, false);
}

operation getOperation(PaintStruct *painter)
{
	mouse_msg msg;
	operation op;

	int lastState = 0;
	for(;; delay_fps(FPS))
	{
		msg = getmouse();
		if (msg.is_move())
		{
			if (690 <= msg.x&&msg.x <= 850 && 355 <= msg.y&&msg.y <= 445)
			{
				if (lastState != 1)
				{
					lastState = 1;
					repaint(painter, true, false);
				}
			}
			else if (690 <= msg.x&&msg.x <= 850 && 505 <= msg.y&&msg.y <= 595)
			{
				if (lastState != 2)
				{
					lastState = 2;
					repaint(painter, false, true);
				}
			}
			else
			{
				if (lastState != 0)
				{
					lastState = 0;
					repaint(painter, false, false);
				}
			}
		}
		else if (msg.is_left() && msg.is_down())
		{
			if (690 <= msg.x&&msg.x <= 850 && 355 <= msg.y&&msg.y <= 445)
			{
				op.op = regret;
				break;
			}
			else if (690 <= msg.x&&msg.x <= 850 && 505 <= msg.y&&msg.y <= 595)
			{
				op.op = restart;
				break;
			}
			else if (0 <= msg.x&&msg.x <= 640 && 0 <= msg.y&&msg.y <= 640)
			{
				op.op = move;
				op.point.x = msg.x / 80;
				op.point.y = msg.y / 80;
				break;
			}
		}
	}

	return op;
}

void gaming()
{
	PaintStruct painter;
	BlockType lastPlayer=black;
	char buffer[1024];

	iniData(&painter);

	int blackNum = 2;
	int whiteNum = 2;
	int deltaNum;
	bool isGameOver = false;

	operation s;

	for(;;delay_fps(FPS))
	{
		if (isGameOver)
		{
			lastPlayer = black;
			Sleep(100000);
		}

		if (lastPlayer == black)
		{
			//s = getOperation(&painter);
			s = getAIOperarion(&painter);
			Sleep(500);
		}
		else
		{
			s = getAIOperarion(&painter);
			Sleep(500);
		}

		if (s.op == move)
		{
			if (canMove(&painter.game, &s.point))
			{
				isGameOver=!movePiece(&painter.game, &s.point);
				counter c = count(&painter.game);

				if (isGameOver)
				{
					if (c.black > c.white)
					{
						sprintf(buffer, "对局结束，黑方获胜\n黑方有%d颗棋子\n白方有%d颗棋子\n",c.black,c.white);
					}
					else if (c.black < c.white)
					{
						sprintf(buffer, "对局结束，白方获胜\n黑方有%d颗棋子\n白方有%d颗棋子\n", c.black, c.white);
					}
					else
					{
						sprintf(buffer, "对局结束，平局\n黑方有%d颗棋子\n白方有%d颗棋子\n", c.black, c.white);
					}
					painter.history = buffer;
				}
				else
				{
					
					if (painter.game.board[painter.game.currentStep - 1].lastPlayer==black)
					{
						painter.history = "黑方将棋子放到了";
					}
					else
					{
						painter.history = "白方将棋子放到了";
					}

					char buffer[1024];
					sprintf(buffer, "%c%d\n", painter.game.lastPoint.x + 'A', painter.game.lastPoint.y + 1);
					painter.history += buffer;

					if (c.black > blackNum)
					{
						deltaNum = whiteNum - c.white;
					}
					else
					{
						deltaNum = blackNum - c.black;
					}

					blackNum = c.black;
					whiteNum = c.white;

					sprintf(buffer,"吃掉了对手%d颗棋子\n黑方有%d颗棋子\n白方有%d颗棋子\n总共有%d颗棋子\n",deltaNum,c.black,c.white,c.total);
					painter.history += buffer;

					if (painter.game.currentPlayer== black)
					{
						painter.prompt = "当前玩家：黑方";
						if (lastPlayer == black)
						{
							painter.history += "白方无子可走";
						}
						painter.history += "现在轮到黑方走子\n";
						lastPlayer = black;
					}
					else
					{
						painter.prompt = "当前玩家：白方";
						if (lastPlayer == white)
						{
							painter.history += "白方无子可走";
						}
						lastPlayer = white;
						painter.history += "现在轮到白方走子\n";
					}

				}

				repaint(&painter, false, false);
			}
		}
		else if (s.op == regret)
		{
			OutputDebugStringA("regret\n");
		}
		else if (s.op == restart)
		{
			iniBoard(&painter.game);
			lastPlayer = black;
			blackNum = 2;
			whiteNum = 2;
			iniData(&painter);
		}
	}

}