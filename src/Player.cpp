#include "Player.h"

Player::Player()
{
    width_frame=PLAYER_WIDTH;
    height_frame=PLAYER_HEIGHT;

    x_pos = SCREEN_WIDTH/2;
    y_pos = SCREEN_HEIGHT/2;

    life=3;
    canspawnbullet=0;
    CurrentTime=0;
    LastTime=0;

}

Player::~Player()
{

}

bool Player::LoadImg(string path, SDL_Renderer* screen)
{
    bool ret=LTexture::LoadTexture(path,screen);

    if(ret==true)
    {
        width_frame=Rect.w;
        height_frame=Rect.h;
    }
    return ret;
}

void Player::Show(SDL_Renderer* des,const SDL_Rect* clip)
{
    Rect.x=x_pos;
    Rect.y=y_pos;

    SDL_Rect RenderQuad={Rect.x,Rect.y,width_frame,height_frame};

    SDL_RenderCopy(des,p_texture,clip,&RenderQuad);
}

SDL_Rect Player::GetHitBox()
{
    SDL_Rect hit_box;
    hit_box.x=Rect.x;
    hit_box.y=Rect.y;
    hit_box.w=width_frame;
    hit_box.h=height_frame;
    return hit_box;
}


void Player::HandleInputAction(SDL_Event events, SDL_Renderer* screen)
{

    if(events.type==SDL_MOUSEBUTTONDOWN || events.type==SDL_MOUSEBUTTONUP || events.type==SDL_MOUSEMOTION)
    {
        input_mouse=1;
        int x,y;
        SDL_GetMouseState(&x,&y);
        x_pos=x-width_frame/2;
        y_pos=y-height_frame/2;
    }
    if(events.type==SDL_MOUSEBUTTONDOWN)
    {
        if(events.button.button==SDL_BUTTON_LEFT)
        {
            canspawnbullet=1;
        }
    }
    else if(events.type==SDL_MOUSEBUTTONUP)
    {
        canspawnbullet=0;
    }
}

void Player::SpawnBullet(SDL_Renderer* screen)
{
    CurrentTime=SDL_GetTicks();
    if(canspawnbullet &&CurrentTime>LastTime+200)
    {
        Bullet* p_bullet=new Bullet();
        p_bullet->LoadTexture("bullet.png",screen);
        p_bullet->set_pos(Rect.x+width_frame/2-18,Rect.y+height_frame*0.1);
        //p_bullet->set_angle(angle);
        p_bullet->set_x_speed(5);
        p_bullet->set_y_speed(5);
        p_bullet->set_is_move(true);
        p_bullet_list.push_back(p_bullet);
        LastTime=CurrentTime;
    }
}

void Player::HandleBullet(SDL_Renderer* des)
{
    for(int i=0;i<p_bullet_list.size();i++)
    {
        Bullet* p_bullet=p_bullet_list.at(i);
        if(p_bullet!=NULL)
        {
            if(p_bullet->get_is_move()==true)
            {
                p_bullet->HandleMove(SCREEN_WIDTH,SCREEN_HEIGHT);
                p_bullet->Render(des);
            }
            else
            {
                p_bullet_list.erase(p_bullet_list.begin()+i);
                if(p_bullet!=NULL)
                {
                    delete p_bullet;
                    p_bullet=NULL;
                }
            }
        }
    }
}

void Player::RemoveBullet(const int &index)
{
    int n=p_bullet_list.size();
    if(n>0 && index<n)
    {
        Bullet*p_bullet=p_bullet_list.at(index);
        p_bullet_list.erase(p_bullet_list.begin()+index);
        if(p_bullet)
        {
            delete p_bullet;
            p_bullet=NULL;
        }
    }
}
