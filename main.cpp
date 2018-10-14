/*
    OH MY KALETH

    WRITTEN IN C++
    24 SEP 2018 - XX XXX XXXX (VERSION 0.0.1)
*/

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "h/graphicscontroller.hpp"
#include "h/error.hpp"

int main( int argc, char **argv )
{
    // Morale Check
    for( int c=1; c<argc; c++ ){
        std::string arg(argv[c]);

        if( arg == "-lowmorale" )
            std::cout << "Come now, and let us reason together, saith Kaleth: though your morale may be low, it shall be as blue as the sky; though it be low, it shall soar as high as the eagle.\n";
    }

	if( SDL_Init( SDL_INIT_EVERYTHING ) != 0 ){
		//logSDLError( std::cout, "Could not intialize SDL");
		return 1;
	}

	if( !( IMG_Init( IMG_INIT_PNG ) ) ){ //SDL_image for PNG support
        //logSDLError( std::cout, "Could not initialize SDL_image ");
        //logSDLError( std::cout, IMG_GetError() );
        return 1;
	}

	GraphicsController graphicsController;

    bool quit = false;
    SDL_Event e;
    SDL_Joystick *joystick;

    if( SDL_NumJoysticks > 0 ){
        joystick = SDL_JoystickOpen( 0 );
        SDL_JoystickEventState( SDL_ENABLE );
    }
    //else
        //logSDLError( std::cout, "Could not initialize joystick" );

    while( !quit )
    {
        //Handle events
        while( SDL_PollEvent( &e ) )
        {
            if( e.type == SDL_QUIT )
                quit = true;
			switch( e.type ) {
				case SDL_KEYDOWN:
					switch( e.key.keysym.sym ){
						case SDLK_RIGHT: graphicsController.x=20; break;
						case SDLK_LEFT: graphicsController.x=5; break;
						case SDLK_UP: graphicsController.y=5; break;
						case SDLK_DOWN: graphicsController.y=20; break;
					}
			}
        }
        if( joystick != NULL )
        {
            switch ( SDL_JoystickGetHat( joystick, 0 ) )
            {
                case SDL_HAT_RIGHT: graphicsController.x=20; break;
                case SDL_HAT_LEFT: graphicsController.x=5; break;
                case SDL_HAT_UP: graphicsController.y=5; break;
                case SDL_HAT_DOWN: graphicsController.y=20; break;
            }
        }

        graphicsController.Draw();
    }

    SDL_JoystickClose( joystick );
    IMG_Quit(); //Quit SDL_image
	SDL_Quit();

	return 0;
}