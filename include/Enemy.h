#ifndef ENEMY_H
#define ENEMY_H


#include "Game_Utils.h"
#include "LTexture.h"
#include "Bullet.h"
#include "Player.h"
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
    void MakeBullet(vector<Bullet*> &bullet,SDL_Renderer* screen,Player &spaceship);


    //movement
    void set_x_speed(const float &xSpeed) {x_speed=xSpeed;}
    void set_y_speed(const float &ySpeed) {y_speed=ySpeed;}
    void MoveThreat();
    void MoveDead();

    void rotate_angle_right();
    void rotate_angle_left();
   void set_angle_rotate_speed(const double& angleSpeed) {angle_rotate_speed=angleSpeed;}
   void set_angle(const double& angle_) {angle=angle_;}

    //texture
    bool LoadImg(string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des,const SDL_Rect* clip);

    //action when die
    void got_hit(const int damage) {health-=damage;}
    void set_health(const int &life) {health=life;}
    int get_heslth() const {return health;}
    int get_score() const {return score;}

    void set_type_threat(const double type_) {type=type_;}
    double get_type_threat() const {return type;}

    private:
    double x_pos;
    double y_pos;
    double x_speed;
    double y_speed;

    double angle;
    double angle_rotate_speed;


    int width_frame;
    int height_frame;


    int y_limit;
    int health;
    int score;
    int delay_shoot_time;
    double type;


    unsigned long long CurrentTime;
    unsigned long long LastTime;









};

#endif // ENEMY_H
