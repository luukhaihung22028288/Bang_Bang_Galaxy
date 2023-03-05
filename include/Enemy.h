#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
#include "Bullet.h"
#define ENEMY_WIDTH 120
#define ENEMY_HEIGHT 120

class Enemy:public GameObject
{
    public:
    Enemy();
    ~Enemy();
    void HandleMove (const int& x_border, const int& y_border);
    void set_x_val(const int& val) {x_val=val;};
    void set_y_val(const int& val) {y_val=val;};

    void SetBulletList(vector <Bullet*> bullet_list) {bullet_list = m_bullet_list;};
    vector <Bullet*> GetBulletList ()const {return  m_bullet_list;};
    void SetBullet(Bullet* m_bullet,SDL_Renderer* m_Renderer);
    void MakeBullet(SDL_Renderer* m_Renderer, const int& x_limit, const int& y_limit);

    bool get_is_move () const {return is_move;}
    void set_is_move (bool fire) {is_move=fire;}

    private:
        int x_val;
        int y_val;
        vector <Bullet*> m_bullet_list;
        bool is_move;
};

#endif // ENEMY_H
