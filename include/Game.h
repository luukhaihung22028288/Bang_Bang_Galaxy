#ifndef GAME_H
#define GAME_H
#include "LTexture.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
using namespace std;

class Game
{
public:
    Game();

    // simply set the running variable to true
    void init() ;
    void loadmedia();
    void draw();
    void update();
    void handleEvents();
    void close ();
    // a function to access the private running variable
    bool running()
        {
            return m_Running;
        }
    private:


    bool m_Running;

    SDL_Window* m_Window;
    SDL_Renderer* m_Renderer;
};

#endif // GAME_H
