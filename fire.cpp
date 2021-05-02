#include "window.hpp"
#include "widget.hpp"
#include "graphics.hpp"
#include "fire.hpp"

Fire::Fire(Window* parent, int x, int y) : Widget(parent,x,y,50,50)
{

}

void Fire::draw()
{
    for(int i = -2; i < 6; i++)
    {
    gout << color(255,0,0) << move_to(_x+5+i, _y+5) << line_to(_x+_sx-10+i,_y+_sy-10) << move_to(_x+5+i, _y+_sy-10) << line_to(_x+_sx-10+i,_y+5);
    }
}

void Fire::handle(genv::event ev)
{

}

bool Fire::isselectable()
{
return false;
}
