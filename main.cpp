#include "LTexture.h"
#include "Game_Utils.h"
#include "Player.h"
#include "Enemy.h"
#include "Enemy_Array.h"
#include "Collision.h"
#include "Text.h"


LTexture m_Background;
LTexture Heart[3];

Player spaceship ;

TTF_Font* general_font=NULL;


Text currentscore;
Text numberofcurrentscore;
Text Life;

;
bool init()
{
     bool success=true;
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success=false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
            success=false;
		}

		//Create window
		m_Window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( m_Window == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success=false;
		}
		else
		{
			//Create vsynced renderer for window
			m_Renderer = SDL_CreateRenderer( m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( m_Renderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success=false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( m_Renderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success=false;
				}
				//Initialize SDL_ttf
				if( TTF_Init() == -1 )
				{
					printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
					success = false;
				}
				general_font=TTF_OpenFont("text.ttf",25);

			}
		}
	}
       return success;
}



void close()
{
    //Destroy window
	SDL_DestroyRenderer( m_Renderer );
	SDL_DestroyWindow( m_Window );
//	m_go.clean();

	m_Window = NULL;
	m_Renderer = NULL;

    //Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* argv[])
{
    vector<Enemy*> Enemy_List;
    vector<Bullet*> Bullet_List;
     int score=0;
    int wave=0;
    if(init()==false)
    {
        return 0;
    }

    for(int i=0;i<3;i++)
    {
        Heart[i].LoadTexture("heart_icon.png",m_Renderer);
        Heart[i].SetRect(SCREEN_WIDTH-25-Heart[i].get_width_frame()*2-32*(i-1),Heart[i]. get_height_frame());
    }
    m_Background.LoadTexture( "background.png" ,m_Renderer);

    spaceship.LoadImg("rocket.png",m_Renderer);

    currentscore.SetColor(Text::RED_COLOR);
    numberofcurrentscore.SetColor(Text::WHITE_COLOR);
    Life.SetColor(Text::RED_COLOR);

    string str_currentscore="SCORE";
    string str_life="HEART";

    currentscore.Set_Text(str_currentscore);
    currentscore.LoadFromRenderText(general_font,m_Renderer);

    Life.Set_Text(str_life);
    Life.LoadFromRenderText(general_font,m_Renderer);

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

   while( !quit )
   {
    while (SDL_PollEvent( &e ) )
        {
            if( e.type == SDL_QUIT )
            {
                quit=true;
            }


        spaceship.HandleInputAction(e,m_Renderer);
        }
            //Clear screen

            SDL_SetRenderDrawColor( m_Renderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( m_Renderer );

            SDL_ShowCursor(SDL_DISABLE);
            m_Background.MoveBackGround(m_Renderer,NULL);
            GenerateEnemy(Enemy_List,m_Renderer,wave);




            spaceship.Show(m_Renderer,NULL);
            spaceship.SpawnBullet(m_Renderer);
            spaceship.HandleBullet(m_Renderer);

            Collision(Enemy_List,spaceship,Bullet_List,score,m_Renderer);


            currentscore.RenderText(m_Renderer,10,10);
            Life.RenderText(m_Renderer,SCREEN_WIDTH-105,10);
            numberofcurrentscore.Set_Text(number_to_string(score));
            numberofcurrentscore.LoadFromRenderText(general_font,m_Renderer);
            numberofcurrentscore.RenderText(m_Renderer,10,35);


            for(int i=0;i<spaceship.get_life();i++)
            {
                    Heart[i].Render(m_Renderer);
            }

            SDL_RenderPresent(m_Renderer);
   }

    //Free resources and close SDL
	close();

    return 0;
}












