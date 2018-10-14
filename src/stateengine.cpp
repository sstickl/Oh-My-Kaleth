#include "../h/stateengine.hpp"

/*
    PUBLIC FUNCTIONS
*/

StateEngine::StateEngine()
{
    init();

    //initialize SDL

    //push first state

    //log init
}

StateEngine::~StateEngine()
{
    cleanup();  //should clear states

    //close SDL

    //log shutdown
}

void StateEngine::changeState( State* state )
{
    //pause current state

    //store, initialize new state
    ;
}

void StateEngine::popState()
{
    //cleanup state

    //resume previous state
    ;
}

void StateEngine::handleEvents()
{
    states.back()->handleEvents();  //probably will need an SDL linkup
}

void StateEngine::draw()
{
    states.back()->draw();  //needs a graphicscontroller hookup
}

/*
    PRIVATE FUNCTIONS
*/