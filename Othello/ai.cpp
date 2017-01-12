#include "structs.h"
#include "functions.h"

operation getAIOperarion(PaintStruct *painter)
{
	int currentStep = painter->game.currentStep;
	BlockType currentPlayer = painter->game.currentPlayer;
	Point lastPoint = painter->game.lastPoint;
	Point currentPoint;
	Point bestPoint;
	counter c;
	int bestMark=0;

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
					if (c.black > bestMark)
					{
						bestMark = c.black;
						bestPoint.x = x;
						bestPoint.y = y;
					}
				}
				else
				{
					if (c.white > bestMark)
					{
						bestMark = c.white;
						bestPoint.x = x;
						bestPoint.y = y;
					}
				}

				painter->game.currentPlayer = currentPlayer;
				painter->game.currentStep = currentStep;
				painter->game.lastPoint = lastPoint;
			}
		}
	}

	operation op;
	op.op = move;
	op.point = bestPoint;

	return op;
}