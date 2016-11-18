#include <iostream>
#include <algorithm>
#include <cstring>
#include "GameOfLife.h"
void fillField(gameField &game_field){
    for(int i = 0; i<f_height; i++){
        for(int j = 0; j<f_width; j++){
            game_field[i][j] = 0;
        }
    }
}
void drawField(gameField game_field){
    for(int i=0; i<f_height; i++){
        for(int j=0;j<f_width; j++){
            switch(game_field[i][j]){
                case 1: std::cout<<char(219);break;
                case 0: std::cout<<char(177);break;
            }
        }
        std::cout << std::endl;
    }
    std::cout<<"--------------------"<<std::endl;
}
void updateCell(gameField &game_field, short x, short y, unsigned short status){
    game_field[x][y] = status;
}
unsigned short getAliveNeighbors(gameField game_field, short x, short y){
    int count = 0;
    for(int i = std::max<int>(0, x-1); i<=std::min<int>(x+1,f_height); i++){
        for(int j = std::max<int>(0, y-1); j<=std::min<int>(y+1,f_width); j++){
        if(i==x&&j==y)continue;
        if(game_field[i][j])count++;
        }
    }
    return count;
}
void generation(gameField &game_field){
    gameField newGeneration;
    /** create a mirror of current game_field **/
    std::memcpy(newGeneration, game_field, sizeof(game_field[0][0])*f_height*f_width);
    for(int x=0; x<f_height; x++){
        for(int y=0;y<f_width; y++){
            unsigned short aliveNeighbours = getAliveNeighbors(game_field, x, y);
            if(aliveNeighbours<2)newGeneration[x][y]=false;
            if(aliveNeighbours==3)newGeneration[x][y]=true;
            if(aliveNeighbours>3)newGeneration[x][y]=false;
        }
    }
    std::memcpy(game_field, &newGeneration, sizeof(newGeneration[0][0])*f_height*f_width);
    drawField(game_field);
}

