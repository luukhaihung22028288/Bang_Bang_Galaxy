#ifndef PLAYER_H
#define PLAYER_H

#include "Game_Utils.h"
#include "LTexture.h"
#include "Bullet.h"

#define PLAYER_WIDTH 120
#define PLAYER_HEIGHT 170
class Player:public LTexture
{
    public:


        Player();
        ~Player();

         //texture
        bool LoadImg(string path, SDL_Renderer* screen);
        void Show(SDL_Renderer* des,const SDL_Rect* clip);

        void set_positions(const int x,const int y)
        {
        x_pos=x;
        y_pos=y;
        }
        SDL_Rect GetHitBox();
        void HandleInputAction(SDL_Event events, SDL_Renderer* screen);
        void move();

        vector<Bullet*> get_bullet_list() const {return p_bullet_list;}
        void HandleBullet(SDL_Renderer* des);
        void SpawnBullet(SDL_Renderer* screen);
        void RemoveBullet(const int &index);
        //frame
        int get_width_frame() const {return width_frame;}
        int get_height_frame() const {return height_frame;}



    private:
        int x_pos;
        int y_pos;
        int width_frame;
        int height_frame;
        vector<Bullet*> p_bullet_list;
        bool canspawnbullet;
        bool input_mouse;

        unsigned long long CurrentTime;
        unsigned long long LastTime;
        unsigned long long PausedTime;




};

#endif // PLAYER_H
