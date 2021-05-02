#include "graphics.hpp"
#include "widget.hpp"
#include "button.hpp"
#include <vector>

using namespace std;
using namespace genv;

Button::Button(Window* parent,int x, int y, int sx, int sy, std::string title, std::function<void()> f) : Widget(parent,x,y,sx,sy), _title(title), _f(f)
{

}

void Button::draw()
{
    //SZIN BEALLITASA
    int bc = 255;
    if(_focused) bc = 0;

    gout << color(bc,bc,255) << move_to(_x,_y) << box(_sx,_sy);
    gout << color(0,0,0) << move_to((_x+_sx/2)+3-(gout.twidth(_title))/2,_y+_sy*0.5+gout.cdescent()) << text(_title);

    //ARNYEKOK
    gout << color(100,100,bc) << move_to(_x,_y+_sy-2) << box_to(_x+_sx,_y+_sy);
    gout << color(100,100,bc) << move_to(_x+_sx-2,_y) << box_to(_x+_sx,_y+_sy);
}


void Button::action()
{
    _f();
}



void Button::handle(event ev)
{
    if(subselected(ev,_x,_x+_sx,_y,_y+_sy) && ev.button == btn_left) action();
    if(ev.keycode == key_space || ev.keycode == key_enter) action();
}
