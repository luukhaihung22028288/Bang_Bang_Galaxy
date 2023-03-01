#include "Player.h"

Player::Player()
{
    m_PosX = SCREEN_WIDTH/2;
    m_PosY = SCREEN_HEIGHT/2;

    m_VelX = 0;
    m_VelY = 0;
}

void Player::handleEvent( SDL_Event& e,SDL_Renderer* m_Renderer )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: m_VelY -= PLAYER_VEL; break;
            case SDLK_DOWN: m_VelY += PLAYER_VEL; break;
            case SDLK_LEFT: m_VelX -= PLAYER_VEL; break;
            case SDLK_RIGHT: m_VelX += PLAYER_VEL; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: m_VelY += PLAYER_VEL; break;
            case SDLK_DOWN: m_VelY -= PLAYER_VEL; break;
            case SDLK_LEFT: m_VelX += PLAYER_VEL; break;
            case SDLK_RIGHT: m_VelX -= PLAYER_VEL; break;
        }
    }
    else if (e.type == SDL_MOUSEBUTTONDOWN)
    {

        if (e.button.button == SDL_BUTTON_LEFT)
        {
            Bullet* m_bullet = new Bullet();
            cout << "Shopot";
            m_bullet->load(SPHERE_WIDTH ,SPHERE_HEIGHT,"sphere.png");
            m_bullet->loadImg(m_Renderer);
            m_bullet->SetPos(this->m_PosX+m_width/2,this->m_PosY);
            m_bullet->set_x_val(1);
            m_bullet->set_is_move(true);


            m_bullet_list.push_back(m_bullet);
        }
    }
}

void Player::handleBullet(SDL_Renderer* m_Renderer)
{
    for (int i=0;i< m_bullet_list.size();i++)
    {
        Bullet* m_bullet = m_bullet_list.at(i);

        if( m_bullet!=NULL)
        {
            if (m_bullet->get_is_move()==true)
            {

                m_bullet->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
                m_bullet->render(m_Renderer);

            }
            else
            {
                m_bullet_list.erase(m_bullet_list.begin() + i);
                if(m_bullet!=NULL)
                {
                    delete m_bullet;
                    m_bullet=NULL;
                    cout << "xoa";
                }
            }
        }
    }
}



void Player::move ()
{
    //Move  left or right
    m_PosX += m_VelX;

    //If went too far to the left or right
    if( ( m_PosX < 0 ) || ( m_PosX + m_width > SCREEN_WIDTH ) )
    {
        //Move back
        m_PosX -= m_VelX;
    }

    //Move  up or down
    m_PosY += m_VelY;

    //If  went too far up or down
    if( ( m_PosY < 0 ) || ( m_PosY + m_height > SCREEN_HEIGHT ) )
    {
        //Move back
        m_PosY -= m_VelY;
    }
}
