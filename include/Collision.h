#ifndef COLLISION_H
#define COLLISION_H


#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"

void Collision(vector<Enemy*> &Enemy_List,Player &spaceship,vector<Bullet*> &Bullet_List,int &current_score,SDL_Renderer* screen);

#endif // COLLISION_H
