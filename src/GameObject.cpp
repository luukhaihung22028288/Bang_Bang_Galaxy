#include "GameObject.h"

LTexture m_GameObject;

GameObject::GameObject() {


}

 void GameObject::load( int width, int height, std::string textureID)
{

    m_width = width;
    m_height = height;
    m_textureID = textureID;
}

void GameObject::draw(SDL_Renderer* m_Renderer) {

    m_GameObject.loadFromFile(m_textureID, m_Renderer);
    m_GameObject.render(m_PosX, m_PosY, m_Renderer);

}


void GameObject::clean()
{
    m_GameObject.free();
}
