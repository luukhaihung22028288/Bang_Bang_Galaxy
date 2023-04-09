#ifndef MENU_H
#define MENU_H

#include "LTexture.h"
#include "Game_Utils.h"
#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"

class Menu: public LTexture
{
    public:
    Menu();
    ~Menu();
    bool LoadButton(string path,SDL_Renderer* screen);
    bool IsInside(SDL_Event event);
	void HandlePlayButton(SDL_Event event,SDL_Renderer* screen,bool &pick,bool &InMenu);
	void HandleChoose_Flame_Button(SDL_Event event,SDL_Renderer* screen,bool &pick,bool &play,Player &spaceship);
	void HandleChoose_Flash_Button(SDL_Event event,SDL_Renderer* screen,bool &pick,bool &play,Player &spaceship);
	void HandleChoose_Gun_Button(SDL_Event event,SDL_Renderer* screen,bool &pick,bool &play,Player &spaceship);
	void HandleQuitButton(SDL_Event event,SDL_Renderer* screen,bool &QuitMenu);
	void HandleBackButton(SDL_Event event,SDL_Renderer* screen,bool &menu,bool &help);
	void HandlePlayAgainButton(SDL_Event event,SDL_Renderer* screen,
                          vector<Enemy*>&Enemy_List,Player &spaceship,
                          vector<Bullet*> &Bullet_List,int &wave,int &current_score,bool &GameOver);





};

#endif // MENU_H
