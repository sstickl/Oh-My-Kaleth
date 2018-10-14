#ifndef STATEENGINE_HPP
#define STATEENGINE_HPP

#include <vector>
#include "state.hpp"
#include "graphicscontroller.hpp"

class StateEngine{
    public:
        StateEngine();
        ~StateEngine();
        void changeState( State* state );
        void pushState( State* state );
        void popState();

        void handleEvents();
        void update();
        void draw();

        bool isRunning() { return running; }

    private:
        void init();
        void cleanup();
        
        void quit();

        std::vector<State*> states;
        GraphicsController graphicsController;

        bool running;

};

#endif //STATEENGINE_HPP