#include "Enemy_Array.h"


void EnemyArray_Type1(vector<Enemy*> &EnemyArray,SDL_Renderer* screen)
{
    for(int i=0;i<Num_of_ThreatArray1;i++)
    {
        Enemy* p_enemy1=new Enemy();

        p_enemy1->set_stats(screen);
        p_enemy1->set_x_pos(SCREEN_WIDTH/2-(p_enemy1->get_width_frame())/2+100*(i-2));
        p_enemy1->set_y_limit(200);
        p_enemy1->set_y_pos(-85*2-25*i);
        p_enemy1->set_health(5);
        EnemyArray.push_back(p_enemy1);
    }


}


void GenerateEnemy(vector<Enemy*> &Enemy_List,SDL_Renderer* screen)
{
            EnemyArray_Type1(Enemy_List,screen);
}
