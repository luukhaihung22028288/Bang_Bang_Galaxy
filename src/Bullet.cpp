#include "Bullet.h"

Bullet::Bullet()
{
    x_speed=0;
    y_speed=0;
    is_move=false;
    angle=90;

    //type=1;
    starting_point=0;
}

Bullet::~Bullet()
{

}

void Bullet::HandleMove(const int &x_border,const int &y_border)
{

    y_pos -= y_speed;
    if (y_pos <0)
    {
      is_move = false;
    }
    Rect.x=x_pos;
    Rect.y=y_pos;
}

void Bullet::HandleEnemyMove()
{
    x_pos+=x_speed*cos(angle*PI/180);
    y_pos+=y_speed*sin(angle*PI/180);
    if(y_pos>SCREEN_HEIGHT)
    {
    is_move=false;
    }
    Rect.x=x_pos;
    Rect.y=y_pos;


}
void Bullet::set_angle_random()
{

    double random_angle=rand()%181;
    angle=random_angle;
}




