#ifndef GAME_UTILS_H
#define GAME_UTILS_H

#include<iostream>
#include<fstream>
#include<SDL.h>
#include <vector>
#include<iomanip>
#include <sstream>
#include<cmath>
#include<string>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>
using namespace std;

static const int SCREEN_WIDTH = 800;
static const int SCREEN_HEIGHT = 720;


bool CheckCollision(const SDL_Rect &object1,const SDL_Rect &object2);

string number_to_string(int number);


static SDL_Window* m_Window=NULL;
static SDL_Renderer* m_Renderer=NULL;






#endif // GAME_UTILS_H
