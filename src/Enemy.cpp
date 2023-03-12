#include "Enemy.h"

Enemy::Enemy()
{
    x_pos=0;
    y_pos=0;
    x_speed=0;
    y_speed=0;


    width_frame=0;
    height_frame=0;


    y_limit=0;
    delay_shoot_time=300;
    health=0;
    score=0;

    CurrentTime=0;
    LastTime=0;



}
Enemy::~Enemy()
{

}

bool Enemy::LoadImg(string path, SDL_Renderer* screen)
{
    bool ret=LTexture::LoadTexture(path,screen);

    if(ret==true)
    {
        width_frame=Rect.w;
        height_frame=Rect.h;
    }
    return ret;
}

void Enemy::Show(SDL_Renderer* screen,const SDL_Rect* clip)
{
    Rect.x=x_pos;
    Rect.y=y_pos;


    SDL_Rect RenderQuad={Rect.x,Rect.y,width_frame,height_frame};

    SDL_RenderCopy(screen,p_texture,clip,&RenderQuad);
}

void Enemy::MoveThreat()
{
    y_pos+=y_speed;
    if(y_pos>=y_limit)
    {
        y_pos=y_limit;

    }

}

bool Enemy::canspawnbullet()
{
    CurrentTime=SDL_GetTicks();
    bool check_can_spawn=false;
    if(CurrentTime>LastTime+delay_shoot_time && y_pos>=y_limit)
        {
            LastTime=CurrentTime;
            check_can_spawn=true;

        }
    return check_can_spawn;
}


void Enemy::MakeBullet(vector<Bullet*> &bullet,SDL_Renderer* screen)
{
    delay_shoot_time=400;
    Bullet*p_bullet=new Bullet();
    p_bullet->LoadTexture("BulletThreat2.png",screen);

    p_bullet->set_is_move(true);
    p_bullet->set_x_speed(2);
    p_bullet->set_y_speed(10);
   p_bullet->set_pos(x_pos+width_frame/2-(p_bullet->GetRect().w)/2,y_pos+24);

    bullet.push_back(p_bullet);


}

void Enemy::set_stats(SDL_Renderer* screen)
{
    LoadImg("enemy1.png",screen);
    score=100;
    y_speed=2;
}






