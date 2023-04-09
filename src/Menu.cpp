#include "Menu.h"

Menu::Menu()
{
    width_frame=0;
    height_frame=0;
}

Menu::~Menu()
{
    //dtor
}

bool Menu::LoadButton(string path, SDL_Renderer* screen)
{
    bool check_load=LTexture::LoadTexture(path,screen);
    if(check_load==true)
    {
        width_frame=Rect.w;
        height_frame=Rect.h;
    }
    return check_load;
}

bool Menu::IsInside(SDL_Event event)
{
	if (event.type==SDL_MOUSEMOTION || event.type==SDL_MOUSEBUTTONDOWN || event.type==SDL_MOUSEBUTTONUP)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		bool inside=true;
		if (x<Rect.x)
		{
			inside=false;
		}
		else if (x>Rect.x+width_frame)
		{
			inside=false;
		}
		else if (y<Rect.y)
		{
			inside=false;
		}
		else if (y>Rect.y+height_frame)
		{
			inside=false;
		}
		return inside;
	}

}

void Menu::HandlePlayButton(SDL_Event event,SDL_Renderer* screen,bool &pick,bool &InMenu)
{
	if(IsInside(event))
	{
	    LoadButton("img//PlayButton2.png",screen);
		if(event.type==SDL_MOUSEBUTTONDOWN)
		{
		    pick=true;
		    InMenu=false;

		}
	}
	else
	{
		LoadButton("img//PlayButton.png",screen);
	}
}
void Menu::HandleChoose_Flame_Button(SDL_Event event,SDL_Renderer* screen,bool &pick,bool &play,Player &spaceship)
{
    if(IsInside(event))
	{
        LoadButton("img//choice_flame2.png",screen);
        if(event.type==SDL_MOUSEBUTTONDOWN)
		{
		    spaceship.set_type(Player::FLAME);
            play=true;
            pick=false;
		}
	}
	else
	{
		LoadButton("img//choice_flame1.png",screen);
	}
}

void Menu::HandleChoose_Flash_Button(SDL_Event event,SDL_Renderer* screen,bool &pick,bool &play,Player &spaceship)
{
    if(IsInside(event))
	{
        LoadButton("img//choice_flash2.png",screen);
        if(event.type==SDL_MOUSEBUTTONDOWN)
		{
            spaceship.set_type(Player::FLASH);
            play=true;
            pick=false;
		}
	}
	else
	{
		LoadButton("img//choice_flash1.png",screen);
	}
}

void Menu::HandleChoose_Gun_Button(SDL_Event event,SDL_Renderer* screen,bool &pick,bool &play,Player &spaceship)
{
    if(IsInside(event))
	{
        LoadButton("img//choice_gun2.png",screen);
        if(event.type==SDL_MOUSEBUTTONDOWN)
		{
            spaceship.set_type(Player::GUN);
            play=true;
            pick=false;
		}
	}
	else
	{
		LoadButton("img//choice_gun1.png",screen);
	}
}

void Menu::HandleQuitButton(SDL_Event event,SDL_Renderer* screen,bool &Quit)
{
    if(IsInside(event))
	{
	    LoadButton("img//QuitButton2.png",screen);
		if(event.type==SDL_MOUSEBUTTONDOWN)
		{
		    Quit=!Quit;
		}
	}
	else
	{
		LoadButton("img//QuitButton.png",screen);
	}
}
void Menu::HandleBackButton(SDL_Event event,SDL_Renderer* screen,bool &menu,bool &help)
{
    if(IsInside(event))
	{
	    LoadButton("img//BackButton2.png",screen);
		if(event.type==SDL_MOUSEBUTTONDOWN)
		{
		    menu=true;
		    help=false;
		}
	}
	else
	{
		LoadButton("img//BackButton.png",screen);
	}
}
void Menu::HandlePlayAgainButton(SDL_Event event,SDL_Renderer* screen,
                          vector<Enemy*>&Enemy_List,Player &spaceship,
                          vector<Bullet*> &Bullet_List,int &wave,int &current_score,bool &GameOver)
    {

    if (IsInside(event))
	{
	    LoadButton("img//PlayAgainButton2.png",screen);
		if(event.type==SDL_MOUSEBUTTONDOWN)
		{
		    GameOver=false;
            current_score=0;
            wave=0;
            Enemy_List.erase(Enemy_List.begin(),Enemy_List.begin()+Enemy_List.size());
            Bullet_List.erase(Bullet_List.begin(),Bullet_List.begin()+Bullet_List.size());
           // Health_List.erase(Health_List.begin(),Health_List.begin()+Health_List.size());
            spaceship.Reset();
            SDL_WarpMouseInWindow(m_Window,SCREEN_WIDTH/2-32,SCREEN_HEIGHT-100);
		}
	}
	else
	{
		LoadButton("img//PlayAgainButton.png",screen);
	}
}
