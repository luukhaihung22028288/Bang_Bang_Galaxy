#ifndef LTEXTURE_H
#define LTEXTURE_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory (giai phong bo nho)
		~LTexture();

		//Loads image from file (load anh tu file)
		bool loadFromFile( std::string path,SDL_Renderer* m_Renderer );

		//Deallocates texture (giai phong anh)
		void free();

		//Renders texture at given point (toa do anh)
		void render( int x, int y,SDL_Renderer* m_Renderer );

		//Gets image dimensions (lay kick thuoc anh)
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* m_Texture;

		//Image dimensions
		int m_Width;
		int m_Height;
};

#endif // LTEXTURE_H
