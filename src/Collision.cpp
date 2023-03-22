#include "Collision.h"


void Collision(vector<Enemy*> &Enemy_List,Player &spaceship,vector<Bullet*> &Bullet_List, int &current_score,bool &GameOver,SDL_Renderer* screen)
{
    for(int i=0;i<Enemy_List.size();i++)
    {
        Enemy *p_enemy=Enemy_List.at(i);
        if(p_enemy!=NULL)
        {
            p_enemy->MoveThreat();
            p_enemy->Show(screen,NULL);

            if(p_enemy->canspawnbullet()==true)
            {
            p_enemy->MakeBullet(Bullet_List,screen,spaceship);
            }
            SDL_Rect spaceshipRect=spaceship.GetHitBox();
            if(p_enemy!=NULL)
            {
                SDL_Rect ThreatRect=p_enemy->GetRect();
                bool Threat_to_Spaceship=CheckCollision(spaceshipRect,ThreatRect);
                if(Threat_to_Spaceship)
                {
                    spaceship.got_hit();
                    spaceship.SetRect(SCREEN_WIDTH/2,SCREEN_HEIGHT-100);
                    Enemy_List.erase(Enemy_List.begin()+i);
                    if(spaceship.get_life()==0)
                    {
                        GameOver=true;
                    }
                }
            }
        }
    }

    for(int i=0;i<Bullet_List.size();i++)
    {
        Bullet*p_bullet=Bullet_List.at(i);
        if(p_bullet!=NULL)
        {
            SDL_Rect BulletRect=p_bullet->GetRect();
            SDL_Rect Main_Rect=spaceship.GetHitBox();

        bool ThreatBullet_to_spaceship=CheckCollision(BulletRect,Main_Rect);
        if(ThreatBullet_to_spaceship)
            {
                spaceship.got_hit();
                Bullet_List.erase(Bullet_List.begin()+i);
                if(spaceship.get_life()==0)
                {
                    GameOver=true;
                }
            }
        if(p_bullet->get_is_move()==true)
            {
                p_bullet->HandleEnemyMove();
                p_bullet->Render(screen,NULL);
            }
            else
            {
                Bullet_List.erase(Bullet_List.begin()+i);
                delete p_bullet;
                p_bullet=NULL;
            }
        }
    }
    vector<Bullet*> spaceship_bullet_arr=spaceship.get_bullet_list();
    for(int i=0;i<spaceship_bullet_arr.size();i++)
    {
        Bullet*p_bullet=spaceship_bullet_arr.at(i);
        if(p_bullet!=NULL)
        {
            for(int j=0;j<Enemy_List.size();j++)
            {
                Enemy* p_enemy=Enemy_List.at(j);
                if(p_enemy!=NULL)
                {
                    SDL_Rect ThreatRect;
                    ThreatRect=p_enemy->GetRect();
                    SDL_Rect BulletRect=p_bullet->GetRect();
                    bool SpaceshipBullet_to_Threat=CheckCollision(ThreatRect,BulletRect);
                    if(SpaceshipBullet_to_Threat)
                    {
                        p_enemy->got_hit();
                        spaceship.RemoveBullet(i);
                        if(p_enemy->get_heslth()==0)
                        {
                            current_score+=(p_enemy->get_score());

                            Enemy_List.erase(Enemy_List.begin()+j);
                            if(p_enemy!=NULL)
                            {
                                delete p_enemy;
                                p_enemy=NULL;
                            }
                        }
                    }
                }
            }
        }
    }

}
