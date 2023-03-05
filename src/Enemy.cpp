#include "Enemy.h"

Enemy::Enemy()
{
    m_PosX=0;
    m_PosY=0;
    m_width=ENEMY_WIDTH;
    m_height=ENEMY_HEIGHT;

    x_val=0;
    y_val=0;

    is_move=true;

}

Enemy::~Enemy()
{

}
void Enemy::HandleMove (const int& x_border, const int& y_border)
{
    if(is_move)
    {
        m_PosY+=y_val;

        if (m_PosY==y_border)
        {
        y_val=0;
        m_PosX+=x_val;
        }

        if (m_PosX==x_border)
    {
        set_is_move(false);
        x_val=0;
    }
    }

    //if (m_PosX>x_border) m_PosX=0;
}

void Enemy:: SetBullet(Bullet* m_bullet,SDL_Renderer* m_Renderer)
{
    if(m_bullet!=NULL)
    {
        m_bullet->loadBullet("sphere.png",m_Renderer);
        m_bullet->set_is_move(true);

         m_bullet->set_x_val(10);
        m_bullet_list.push_back(m_bullet);
    }
}
void Enemy:: MakeBullet(SDL_Renderer* m_Renderer, const int& x_limit, const int& y_limit)
{
    for (int i=0;i<m_bullet_list.size();i++)
    {
        Bullet* m_bullet=m_bullet_list.at(i);
        if(m_bullet!=NULL)
        {
            if(m_bullet->get_is_move())
            {

                m_bullet->render(m_Renderer);

                 m_bullet->HandleEnemyMove();

            }
            else
            {
                 m_bullet->set_is_move(true);
                 m_bullet->SetPos(m_PosX+m_width/2,m_PosY+m_height/2);
            }

        }
    }
}


