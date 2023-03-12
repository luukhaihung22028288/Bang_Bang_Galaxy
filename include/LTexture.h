#ifndef LTEXTURE_H
#define LTEXTURE_H

#include "Game_Utils.h"

class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory (giai phong bo nho)
		~LTexture();

		void SetRect(const int &x, const int &y)
    {
        Rect.x=x;
        Rect.y=y;
    }
    SDL_Rect GetRect()
    {
        return Rect;
    }
    SDL_Texture* GetTexture()
    {
        return p_texture;
    }
    virtual bool LoadTexture(string path, SDL_Renderer* screen);
    void MoveBackGround(SDL_Renderer* screen,const SDL_Rect* clip=NULL);
    void Render(SDL_Renderer* screen,const SDL_Rect* clip=NULL);
    void free();
protected:
    SDL_Texture* p_texture;
    SDL_Rect Rect;
};

#endif // LTEXTURE_H
