#include <iostream>
#include "GameOfLife.h"
using namespace std;
gameField game_field;
int main(){
    fillField(game_field);
    updateCell(game_field, 11, 11, 1);
    updateCell(game_field, 11, 12, 1);
    updateCell(game_field, 11, 13, 1);
    updateCell(game_field, 12, 12, 1);
    drawField(game_field);
    for(int i=0; i<20; i++){
            generation(game_field);
    }
    return 0;
}
