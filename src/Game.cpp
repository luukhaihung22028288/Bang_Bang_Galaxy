#include "Game.h"


Player m_go ;
Enemy* m_enemy=new Enemy[5];

LTexture m_Background;
Game::Game()
{
    //ctor
    m_Window=NULL;
    m_Renderer=NULL;

}

void Game::init()
{
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );

	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		m_Window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( m_Window == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );

		}
		else
		{
			//Create vsynced renderer for window
			m_Renderer = SDL_CreateRenderer( m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( m_Renderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );

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

				}
			}
		}
	}
    m_Running = true; // everything inited successfully, start the main loop

}

void Game::draw()
{
    SDL_RenderClear(m_Renderer); // clear the renderer tothe draw color
//m_Background.render( 0, 0,m_Renderer );

    m_go.draw(m_Renderer);

}

void Game::loadmedia()
{
    m_Background.loadFromFile( "background.png" ,m_Renderer);

    for (int i=0;i<5;i++)
    {
        Enemy* m_e= (m_enemy+i);
        if(m_e!=NULL)
        {


        m_e->loadImg("enemy.png",m_Renderer);
        m_e->SetPos(0,-200-i*100);
        m_e->set_y_val(5);
        m_e->set_x_val(5);
        Bullet* m_bullet = new Bullet();
        m_e->SetBullet(m_bullet,m_Renderer);
        }
    }


    m_go.loadImg("rocket.png",m_Renderer);



}

void Game::handleEvents()
    {
        SDL_Event e;
        while (SDL_PollEvent( &e ) )
        {
            if( e.type == SDL_QUIT )
            {
                m_Running = false;
            }
            m_go.handleEvent( e,m_Renderer);

        }

        m_go.handleBullet(m_Renderer);
        m_go.move();

        for (int i=0;i<5;i++)
        {
            Enemy* m_e=(m_enemy+i);
            if(m_e!=NULL)
            {
             m_e->draw(m_Renderer);
             m_e->HandleMove(SCREEN_WIDTH/8+i*200,SCREEN_HEIGHT/8);

            if(m_e->get_is_move()==false)
            {
                m_e->MakeBullet(m_Renderer,SCREEN_WIDTH,SCREEN_HEIGHT);
            }
            }

        }


        SDL_RenderPresent(m_Renderer);





}

void Game::update()
{

}

void Game::close()
{
    //Destroy window
	SDL_DestroyRenderer( m_Renderer );
	SDL_DestroyWindow( m_Window );
	m_go.clean();

	m_Window = NULL;
	m_Renderer = NULL;

    //Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}







