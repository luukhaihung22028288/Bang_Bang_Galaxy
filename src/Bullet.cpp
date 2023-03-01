#include "Bullet.h"

Bullet::Bullet()
{
    x_val=0;
    y_val=0;
    is_move= false;

}


void Bullet::HandleMove(const int& x_border, const int& y_border)
{

    m_PosY -= x_val;
    if (m_PosY <0)
    {
        cout << "xoa";
      is_move = false;
    }
}

 void Bullet::loadImg(SDL_Renderer* m_Renderer)
 {
     bullet_img.loadFromFile(m_textureID, m_Renderer);
 }

 void Bullet::render (SDL_Renderer* m_Renderer)
 {
     bullet_img.render(m_PosX, m_PosY, m_Renderer);

 }


