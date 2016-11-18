#ifndef GAMEOFLIFE_H_INCLUDED
#define GAMEOFLIFE_H_INCLUDED
const unsigned short f_height = 20;
const unsigned short f_width = 20;

typedef unsigned short gameField[f_height][f_width];
//funkcje
void fillField(gameField &game_field);
void drawField(gameField game_field);
void updateCell(gameField &game_field, short x, short y, unsigned short status);
void generation(gameField &game_field);
#endif // GAMEOFLIFE_H_INCLUDED
