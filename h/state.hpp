#ifndef STATE_HPP
#define STATE_HPP

class State //CLASS_STATE_1
{
    public:
        State();

        void Pause() { iStatus = 1; }
        void Resume() { if( iStatus == 1 ) iStatus = 0; }

        virtual void handleEvents() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;

        int getStatus() { return iStatus; }

    private:
        virtual void init() = 0;
        virtual void cleanup() = 0;

        int iStatus;    //0 = FMC, 1 = PAUSE, 2 = PAUSEDRAW
};

class IntroState : public State //CLASS_STATE_2
{
    public:
        IntroState();
        void handleEvents();
        void update();
        void draw();

    private:
        void init();
        void cleanup();
        
};

#endif  //STATE_HPP