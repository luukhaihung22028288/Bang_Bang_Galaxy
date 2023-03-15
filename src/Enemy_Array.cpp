#include "Enemy_Array.h"


void EnemyArray_Type1(vector<Enemy*> &EnemyArray,SDL_Renderer* screen)
{
    for(int i=0;i<Num_of_ThreatArray1;i++)
    {
        Enemy* p_enemy1=new Enemy();
        p_enemy1->set_type_threat(1.1);
        p_enemy1->set_stats(screen);
        p_enemy1->set_x_pos(SCREEN_WIDTH/2-(p_enemy1->get_width_frame())/2+100*(i-2));
        p_enemy1->set_y_limit(200);
        p_enemy1->set_y_pos(-150);

        p_enemy1->set_health(5);
        EnemyArray.push_back(p_enemy1);
    }
}

void EnemyBoss(vector<Enemy*> &EnemyArray,SDL_Renderer* screen)
{
    Enemy* p_enemy=new Enemy();
    p_enemy->set_type_threat(2.1);
    p_enemy->set_stats(screen);
    //p_enemy->set_angle(0);
    //p_enemy->set_angle_rotate_speed(0.5);
    p_enemy->set_x_pos(SCREEN_WIDTH/2-(p_enemy->get_width_frame())/2);
    p_enemy->set_y_pos(-p_enemy->get_height_frame());
    p_enemy->set_health(10);
    p_enemy->set_y_limit(100);
    EnemyArray.push_back(p_enemy);
}


void GenerateEnemy(vector<Enemy*> &Enemy_List,SDL_Renderer* screen,int &wave)
{

    if(Enemy_List.size()<=0)
    {
        wave+=1;

        if(wave==1)
        {
           EnemyArray_Type1(Enemy_List,screen);
        }

         else
        {
            EnemyBoss(Enemy_List,screen);
        }

    }


}
