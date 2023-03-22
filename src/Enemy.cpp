#include "Enemy.h"

Enemy::Enemy()
{
    x_pos=0;
    y_pos=0;
    x_speed=0;
    y_speed=0;

    angle=0;
    angle_rotate_speed=0;


    width_frame=0;
    height_frame=0;

    type=1.1;
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
    if(type==1.1)
    {
        y_pos+=y_speed;
        if(y_pos>=y_limit)
        {
        y_pos=y_limit;
        }
    }
    else if(type==2.1)
    {
        y_pos+=y_speed;
        if(y_pos>=y_limit)
        {
        y_pos=y_limit;
        }
    }


}

void Enemy::rotate_angle()
{
    angle+=angle_rotate_speed;
    if(angle>=360)
    {
        angle=0;
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


void Enemy::MakeBullet(vector<Bullet*> &bullet,SDL_Renderer* screen,Player &spaceship)
{
    if(type==1.1)
    {
        delay_shoot_time=400;
        Bullet*p_bullet=new Bullet();
        p_bullet->LoadTexture("BulletThreat2.png",screen);
        p_bullet->set_is_move(true);
        p_bullet->set_angle_random();
        p_bullet->set_x_speed(5);
        p_bullet->set_y_speed(5);
        p_bullet->set_pos(x_pos+width_frame/2-(p_bullet->GetRect().w)/2,y_pos+24);
        bullet.push_back(p_bullet);
    }
    else if (type==2.1)
    {

            for(int i=0;i<12;i++)
            {

                delay_shoot_time=400;
                Bullet*p_bullet=new Bullet();
                p_bullet->LoadTexture("BulletThreat2.png",screen);
                p_bullet->set_is_move(true);
                p_bullet->set_angle(0+30*i);
                p_bullet->set_x_speed(4);
                p_bullet->set_y_speed(4);
                p_bullet->set_pos(x_pos+width_frame/2-(p_bullet->GetRect().w)/2,y_pos+height_frame/2);
                bullet.push_back(p_bullet);
            }

        delay_shoot_time=100;
        Bullet*p_bullet1=new Bullet();
        p_bullet1->LoadTexture("BulletThreat2.png",screen);
        p_bullet1->set_is_move(true);
        p_bullet1->set_angle(angle);
        set_angle_rotate_speed(2);
        rotate_angle();
        p_bullet1->set_x_speed(2);
        p_bullet1->set_y_speed(2);
        p_bullet1->set_pos(x_pos+width_frame/2-(p_bullet1->GetRect().w)/2,y_pos+24);
        bullet.push_back(p_bullet1);

        Bullet*p_bullet2=new Bullet();
        p_bullet2->LoadTexture("BulletThreat2.png",screen);
        p_bullet2->set_is_move(true);
        p_bullet2->set_angle(angle+60);
        set_angle_rotate_speed(2);
        rotate_angle();
        p_bullet2->set_x_speed(2);
        p_bullet2->set_y_speed(2);
        p_bullet2->set_pos(x_pos+width_frame/2-(p_bullet2->GetRect().w)/2,y_pos+24);
        bullet.push_back(p_bullet2);

        Bullet*p_bullet3=new Bullet();
        p_bullet3->LoadTexture("BulletThreat2.png",screen);
        p_bullet3->set_is_move(true);
        p_bullet3->set_angle(angle+120);
        set_angle_rotate_speed(2);
        rotate_angle();
        p_bullet3->set_x_speed(2);
        p_bullet3->set_y_speed(2);
        p_bullet3->set_pos(x_pos+width_frame/2-(p_bullet3->GetRect().w)/2,y_pos+24);
        bullet.push_back(p_bullet3);

        Bullet*p_bullet4=new Bullet();
        p_bullet4->LoadTexture("BulletThreat2.png",screen);
        p_bullet4->set_is_move(true);
        p_bullet4->set_angle(angle+180);
        set_angle_rotate_speed(2);
        rotate_angle();
        p_bullet4->set_x_speed(2);
        p_bullet4->set_y_speed(2);
        p_bullet4->set_pos(x_pos+width_frame/2-(p_bullet4->GetRect().w)/2,y_pos+24);
        bullet.push_back(p_bullet4);


        Bullet*p_bullet5=new Bullet();
        p_bullet5->LoadTexture("BulletThreat2.png",screen);
        p_bullet5->set_is_move(true);
        p_bullet5->set_angle(angle+240);
        set_angle_rotate_speed(2);
        rotate_angle();
        p_bullet5->set_x_speed(2);
        p_bullet5->set_y_speed(2);
        p_bullet5->set_pos(x_pos+width_frame/2-(p_bullet5->GetRect().w)/2,y_pos+24);
        bullet.push_back(p_bullet5);

        Bullet*p_bullet6=new Bullet();
        p_bullet6->LoadTexture("BulletThreat2.png",screen);
        p_bullet6->set_is_move(true);
        p_bullet6->set_angle(angle+300);
        set_angle_rotate_speed(2);
        rotate_angle();
        p_bullet6->set_x_speed(2);
        p_bullet6->set_y_speed(2);
        p_bullet6->set_pos(x_pos+width_frame/2-(p_bullet6->GetRect().w)/2,y_pos+24);
        bullet.push_back(p_bullet6);

    }
}

void Enemy::set_stats(SDL_Renderer* screen)
{
    if(type==1.1)
    {
        LoadImg("enemy1.png",screen);
        score=100;
        y_speed=2;
    }
    else if(type==2.1)
    {
        LoadImg("boss.png",screen);
        y_speed=2;
        score=500;
    }

}






