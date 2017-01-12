#pragma once

struct GameControl;
struct Point;
struct PaintStruct;
struct operation;
struct counter;

/*��Щ����ʵ����update.cpp��*/
bool canMove(GameControl *game, Point *point);
bool movePiece(GameControl *game, Point *point);
void iniBoard(GameControl *game);
counter count(GameControl *game);

/*��Щ����ʵ����render.cpp��*/
void gaming();
operation getOperation(PaintStruct *painter);

/*��Щ����ʵ����ai.cpp��*/
operation getAIOperarion(PaintStruct *painter);