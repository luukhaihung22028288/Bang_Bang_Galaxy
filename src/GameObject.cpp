#include "GameObject.h"

LTexture m_GameObject;

GameObject::GameObject() {


}

 void GameObject::loadImg(string textureID,SDL_Renderer* m_Renderer)
{


    m_GameObject.loadFromFile(textureID, m_Renderer);

}


void GameObject::draw(SDL_Renderer* m_Renderer) {

    m_GameObject.render(m_PosX, m_PosY, m_Renderer);

}


void GameObject::clean()
{
    m_GameObject.free();
}
