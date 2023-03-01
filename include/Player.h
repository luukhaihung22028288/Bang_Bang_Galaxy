#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"
#include "Bullet.h"
class Player:public GameObject
{
    public:
        static const int PLAYER_VEL = 5;

        Player();

        void handleEvent( SDL_Event& e,SDL_Renderer* m_Renderer );
        void move();
        void handleBullet(SDL_Renderer* m_Renderer);
        void SetBulletList(vector <Bullet*> bullet_list) {bullet_list = m_bullet_list;};
        vector <Bullet*> GetBulletList ()const {return  m_bullet_list;};

    private:
        int m_VelX;
        int m_VelY;
        vector <Bullet*> m_bullet_list;


};

#endif // PLAYER_H
