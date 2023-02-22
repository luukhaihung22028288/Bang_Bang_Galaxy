#ifndef COMMON_FUNCTION_H
#define COMMON_FUNCTION_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
static SDL_Surface *g_screen = NULL;

static SDL_Event e;
namespace SDLCommonFunc
{
SDL_Surface* loadSurface( std::string path );
void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
void CleanUp();
}

#endif // COMMON_FUNCTION_H
