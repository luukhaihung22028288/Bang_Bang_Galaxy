#ifndef GAME_H
#define GAME_H
#include "LTexture.h"


using namespace std;

static const int SCREEN_WIDTH = 1280;
static const int SCREEN_HEIGHT = 720;


class Game
{
public:
    Game();
    //~Game() {}
    // simply set the running variable to true
    void init() ;
    void render();
    void update();
    void handleEvents();
    void clean ();
    // a function to access the private running variable
    bool running() { return m_Running; }
    private:


    bool m_Running;

    SDL_Window* m_Window=NULL;
    SDL_Renderer* m_Renderer;
};

#endif // GAME_H
