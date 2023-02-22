#include "Game.h"


Game::Game()
{
    //ctor
    m_Window=NULL;
    m_Renderer=NULL;

}

/*Game::~Game()
{
    //dtor

}
*/

void Game::init()
{
	//Initialize SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
	}
	else
	{
	    m_Window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( m_Window == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );

		}
		else
		{
			//Create renderer for window
			m_Renderer = SDL_CreateRenderer( m_Window, -1, SDL_RENDERER_ACCELERATED );
			if( m_Renderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );

			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( m_Renderer,255,255,255,255);
				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );

				}
			}
		}
	}
    m_Running = true; // everything inited successfully, start the main loop

}

void Game::render()
{
    SDL_RenderClear(m_Renderer); // clear the renderer tothe draw color
    SDL_RenderPresent(m_Renderer); // draw to the screen
}


void Game::handleEvents()
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            m_Running = false;
            break;
        default:
            break;
    }

}
}

void Game::clean()
{
    //Destroy window
	SDL_DestroyRenderer( m_Renderer );
	SDL_DestroyWindow( m_Window );
	m_Window = NULL;
	m_Renderer = NULL;

    //Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}







