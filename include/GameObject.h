#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "LTexture.h"

class GameObject
{
    public:
        GameObject();
        void loadImg( string textureID,SDL_Renderer* m_Renderer);
        void draw(SDL_Renderer* m_Renderer);
        void SetPos(int PosX,int PosY) {m_PosX=PosX, m_PosY=PosY;};
        //void update();
        void clean();
    protected:
        int m_PosX;
        int m_PosY;
        int m_width;
		int m_height;
		LTexture m_GameObject;
        string m_textureID;
};

#endif // GAMEOBJECT_H
