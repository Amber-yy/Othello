#include "structs.h"
#include "functions.h"
#include <vector>
#include <algorithm>
#include <random>

operation getAIOperarion(PaintStruct *painter)
{
	int currentStep = painter->game.currentStep;
	BlockType currentPlayer = painter->game.currentPlayer;
	Point lastPoint = painter->game.lastPoint;
	Point currentPoint;
	Point bestPoint;
	counter c;
	int bestMark=0;
	std::vector<Point> points;

	for (int x = 0; x < BOARDSIZE; x++)
	{
		for (int y = 0; y < BOARDSIZE; y++)
		{
			currentPoint.x = x;
			currentPoint.y = y;
			if (canMove(&painter->game, &currentPoint))
			{
				movePiece(&painter->game, &currentPoint);
				c = count(&painter->game);
				if (currentPlayer == black)
				{
					if (c.black >= bestMark)
					{
						if (c.black >bestMark)
						{
							points.clear();
						}
						bestMark = c.black;
						bestPoint.x = x;
						bestPoint.y = y;
						points.push_back(currentPoint);
					}
				}
				else
				{
					if (c.white >= bestMark)
					{
						if (c.white > bestMark)
						{
							points.clear();
						}
						bestMark = c.white;
						bestPoint.x = x;
						bestPoint.y = y;
						points.push_back(currentPoint);
					}
				}

				painter->game.currentPlayer = currentPlayer;
				painter->game.currentStep = currentStep;
				painter->game.lastPoint = lastPoint;
			}
		}
	}

	std::random_device rd;
	std::default_random_engine e(rd());
	std::uniform_int_distribution<> u(0, points.size()-1);

	operation op;
	op.op = move;
	op.point = points[u(e)];

	return op;
}