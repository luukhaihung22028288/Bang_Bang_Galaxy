#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "LTexture.h"

class GameObject
{
    public:
        GameObject();
        void load( int width, int height, std::string textureID);
        void draw(SDL_Renderer* m_Renderer);
        //void update();
        void clean();
    protected:
        int m_PosX;
        int m_PosY;
        int m_width;
		int m_height;
        string m_textureID;
};

#endif // GAMEOBJECT_H
