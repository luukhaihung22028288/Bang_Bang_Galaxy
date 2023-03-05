#include "Bullet.h"

Bullet::Bullet()
{
    m_width=SPHERE_WIDTH;
    m_height=SPHERE_HEIGHT;
    x_val=0;
    y_val=0;
    is_move= false;

}


void Bullet::HandleMove(const int& x_border, const int& y_border)
{

    m_PosY -= x_val;
    if (m_PosY <0)
    {

      is_move = false;
    }
}
void Bullet::HandleEnemyMove()
{
    m_PosY+=x_val;
    if(m_PosY>SCREEN_HEIGHT)
    {

    is_move=false;
    }

}
 void Bullet::loadBullet(string textureID,SDL_Renderer* m_Renderer)
 {
     bullet_img.loadFromFile(textureID, m_Renderer);
 }

 void Bullet::render (SDL_Renderer* m_Renderer)
 {
     bullet_img.render(m_PosX, m_PosY, m_Renderer);

 }


