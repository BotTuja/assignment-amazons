#include "window.hpp"
#include "widget.hpp"
#include "graphics.hpp"
#include "fire.hpp"

Fire::Fire(Window* parent, int x, int y) : Widget(parent,x,y,50,50)
{

}

void Fire::draw()
{
gout << color(255,0,0) << move_to(_x+5, _y+5) << box(_sx-10,_sy-10);
}

void Fire::handle(genv::event ev)
{

}

bool Fire::isselectable()
{
return false;
}
