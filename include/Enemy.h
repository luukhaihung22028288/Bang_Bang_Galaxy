#ifndef ENEMY_H
#define ENEMY_H


#include "Game_Utils.h"
#include "LTexture.h"
#include "Bullet.h"
#define ENEMY_WIDTH 120
#define ENEMY_HEIGHT 120

class Enemy:public LTexture
{
    public:
    Enemy();
    ~Enemy();

    //frame
    int get_width_frame() const {return width_frame;}
    int get_height_frame() const {return height_frame;}

    //position
    void set_x_pos(const double &xPos) {x_pos=xPos;}
    void set_y_pos(const double &yPos) {y_pos=yPos;}
    double get_x_pos() const {return x_pos;}
    double get_y_pos() const {return y_pos;}
    void set_y_limit(const double &yLimit) {y_limit=yLimit;}
    void set_stats(SDL_Renderer* screen);


    //bullet
    bool canspawnbullet();
    void MakeBullet(vector<Bullet*> &bullet,SDL_Renderer* screen);


    //movement
    void set_x_speed(const float &xSpeed) {x_speed=xSpeed;}
    void set_y_speed(const float &ySpeed) {y_speed=ySpeed;}
    void MoveThreat();

    //texture
    bool LoadImg(string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des,const SDL_Rect* clip);

    //action when die
    void got_hit() {health--;}
    int set_health(const int &life) {health=life;}
    int get_heslth() const {return health;}
    int get_score() const {return score;}



    private:
    double x_pos;
    double y_pos;
    double x_speed;
    double y_speed;


    int width_frame;
    int height_frame;


    double y_limit;
    int health;
     int score;
    int delay_shoot_time;


    unsigned long long CurrentTime;
    unsigned long long LastTime;







};

#endif // ENEMY_H
