#pragma once

struct GameControl;
struct Point;
struct PaintStruct;
struct operation;
struct counter;

/*这些函数实现在update.cpp中*/
bool canMove(GameControl *game, Point *point);
bool movePiece(GameControl *game, Point *point);
void iniBoard(GameControl *game);
counter count(GameControl *game);

/*这些函数实现在render.cpp中*/
void gaming();
operation getOperation(PaintStruct *painter);

/*这些函数实现在ai.cpp中*/
operation getAIOperarion(PaintStruct *painter);