#ifndef ENEMY_ARRAY_H
#define ENEMY_ARRAY_H

#include "Enemy.h"
#include "Game_Utils.h"

const int Num_of_ThreatArray1 =5;

void EnemyArray_Type1(vector<Enemy*> &EnemyArray,SDL_Renderer* screen);
void EnemyBoss(vector<Enemy*> &EnemyArray,SDL_Renderer* screen);

void GenerateEnemy(vector<Enemy*> &Enemy_List,SDL_Renderer* screen,int &wave);

#endif // ENEMY_ARRAY_H

