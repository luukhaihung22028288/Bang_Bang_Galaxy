#include "Enemy_Array.h"


void EnemyArray_Type1(vector<Enemy*> &EnemyArray,SDL_Renderer* screen)
{
    for(int i=0;i<5;i++)
    {
        Enemy* p_enemy1=new Enemy();
        p_enemy1->set_type_threat(1);
        p_enemy1->set_stats(screen);
        p_enemy1->set_x_pos(20+(p_enemy1->get_width_frame()+60)*i);
        p_enemy1->set_y_limit(50);
        p_enemy1->set_y_pos(-4*p_enemy1->get_height_frame());

        p_enemy1->set_health(100);
        EnemyArray.push_back(p_enemy1);
    }

    for(int i=0;i<5;i++)
    {
        Enemy* p_enemy1=new Enemy();
        p_enemy1->set_type_threat(1);
        p_enemy1->set_stats(screen);
        p_enemy1->set_x_pos(15+(p_enemy1->get_width_frame()+60)*i);
        p_enemy1->set_y_limit(50+p_enemy1->get_height_frame());
        p_enemy1->set_y_pos(-3*p_enemy1->get_height_frame());

        p_enemy1->set_health(100);
        EnemyArray.push_back(p_enemy1);
    }
}

void EnemyArray_Type2(vector<Enemy*> &EnemyArray,SDL_Renderer* screen)
{
        Enemy* p_enemy1=new Enemy();
        p_enemy1->set_type_threat(3);
        p_enemy1->set_stats(screen);
        p_enemy1->set_x_pos(100);
        p_enemy1->set_y_limit(50);
        p_enemy1->set_y_pos(-2*p_enemy1->get_height_frame());
        p_enemy1->set_health(100);
        EnemyArray.push_back(p_enemy1);

        Enemy* p_enemy2=new Enemy();
        p_enemy2->set_type_threat(3);
        p_enemy2->set_stats(screen);
        p_enemy2->set_x_pos(520);
        p_enemy2->set_y_limit(50);
        p_enemy2->set_y_pos(-2*p_enemy2->get_height_frame());
        p_enemy2->set_health(100);
        EnemyArray.push_back(p_enemy2);

/*
        Enemy* p_enemy3=new Enemy();
        p_enemy3->set_type_threat(2.2);
        p_enemy3->set_stats(screen);
        p_enemy3->set_x_pos(600);
        p_enemy3->set_y_limit(50);
        p_enemy3->set_y_pos(-4*p_enemy1->get_height_frame());
        p_enemy3->set_health(100);
        EnemyArray.push_back(p_enemy3);

*/
}
void EnemyArray_Type0(vector<Enemy*> &EnemyArray,SDL_Renderer* screen)
{
        Enemy* p_enemy1=new Enemy();
        p_enemy1->set_type_threat(1);
        p_enemy1->set_stats(screen);
        p_enemy1->set_x_pos(SCREEN_WIDTH/2-p_enemy1->get_width_frame()/2);
        p_enemy1->set_y_limit(50);
        p_enemy1->set_y_pos(-SCREEN_HEIGHT/2-p_enemy1->get_height_frame()/2);
        p_enemy1->set_health(100);
        EnemyArray.push_back(p_enemy1);
}

void EnemyBoss(vector<Enemy*> &EnemyArray,SDL_Renderer* screen)
{
    Enemy* p_enemy=new Enemy();
    p_enemy->set_type_threat(5);
    p_enemy->set_stats(screen);
    p_enemy->set_x_pos(SCREEN_WIDTH/2-(p_enemy->get_width_frame())/2);
    p_enemy->set_y_pos(-p_enemy->get_height_frame());
    p_enemy->set_health(2000);
    p_enemy->set_y_limit(0);
    EnemyArray.push_back(p_enemy);
}


void GenerateEnemy(vector<Enemy*> &Enemy_List,SDL_Renderer* screen,int &wave)
{
    if(Enemy_List.size()<=0)
    {
        wave++;

        if(wave==1)
        {
           EnemyArray_Type0(Enemy_List,screen);
        }

         else
        {
            EnemyBoss(Enemy_List,screen);
        }
    }


}
