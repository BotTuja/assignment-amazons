#include "graphics.hpp"
#include "widget.hpp"
#include <vector>
#include "statictext.hpp"
#include "numberdisplay.hpp"
#include "textdisplay.hpp"
#include "window.hpp"
#include <iostream>
#include "gamemaster.hpp"
#include "button.hpp"


const int XX = 300;
const int YY = 400;
const int HH = 100;

using namespace std;
using namespace genv;

class MyWindow : public Window
{
Game* GameMaster;
TextDisplay* Message;
Button* Reset;
NumberDisplay* TurnCount;
StaticText* TurnText;
protected:
    virtual void passive(event ev)
    {
    if(ev.keycode == 'r')
    {
    gamereset();
    }
    }

    void gamereset()
    {
    delete GameMaster;
    GameMaster = new Game(this,6);
    Message->updatetext(GameMaster->accessstatus());
    TurnCount->updatevalue(GameMaster->accessturncount());
    }
public:
    MyWindow(int sx, int sy) : Window(sx,sy)
    {
    GameMaster = new Game(this,6);
    Message = new TextDisplay(this,10,70,GameMaster->accessstatus(),255,255,255);
    Reset = new Button(this,160,10,130,30,"RESTART",[this](){this->gamereset();});
    TurnCount = new NumberDisplay(this,60,30,GameMaster->accessturncount(),255,255,255);
    TurnText = new StaticText(this,10,30,"Turn:",255,255,255);
    }
    virtual void cls()
    {
        gout << color(0,0,0) << move_to(0,0) << box(XX,YY);
        for(int i = 0; i < 6; i++)
        {
            for(int j = 0; j < 6; j++)
            {
                if((i+j)%2) gout << color(255,255,255);
                else gout << color(100,100,255);
                gout << move_to(j*50,HH+i*50) << box(50,50);
            }
        }
    }
};

int main()
{

    MyWindow* Ablak = new MyWindow(XX,YY);
    Ablak->event_loop();

    return 0;
}
