#include "Common_Function.h"


SDL_Surface* SDLCommonFunc:: loadSurface(std::string file_path)
{
  SDL_Surface* loadedSurface = SDL_LoadBMP( file_path.c_str() );
  SDL_Surface* optimizedSurface = NULL;

 if( loadedSurface == NULL )
  {
   optimizedSurface = SDL_ConvertSurface( loadedSurface, g_screen->format, 0 );
    SDL_FreeSurface( loadedSurface );
  }
  return optimizedSurface;
}
void SDLCommonFunc:: ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)
{
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(src, NULL, des, &offset);
}

 void SDLCommonFunc:: CleanUp()
{
  SDL_FreeSurface(g_screen);
//  SDL_FreeSurface(g_bkground);
}

