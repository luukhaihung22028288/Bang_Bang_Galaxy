#ifndef BULLET_H
#define BULLET_H
#include "GameObject.h"


#define SPHERE_WIDTH 10
#define SPHERE_HEIGHT 10

class Bullet:public GameObject
{

    public:


        Bullet();

        //void handleEvent( SDL_Event& e );
        void HandleMove(const int& x_border, const int& y_border);
        void HandleEnemyMove();
        void loadBullet(string textureID,SDL_Renderer* m_Renderer);
        void render (SDL_Renderer* m_Renderer);
        void SetPos(int PosX,int PosY) {m_PosX=PosX, m_PosY=PosY;}

        void set_x_val(const int& Xval) {x_val=Xval;};
        void set_y_val(const int& Yval) {y_val=Yval;};

        int get_x_val() const {return x_val;};
        int get_y_val() const {return y_val;};

        bool get_is_move () const {return is_move;}
        void set_is_move (bool fire) {is_move=fire;}


    private:

        int x_val;
        int y_val;
        bool is_move;
        LTexture bullet_img;

};

#endif // BULLET_H
