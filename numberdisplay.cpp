#include "graphics.hpp"
#include "widget.hpp"
#include "numberdisplay.hpp"
using namespace genv;

NumberDisplay::NumberDisplay(Window* parent,int x, int y, int* value, int r, int g, int b) : Widget(parent,x,y,0,0)
{
    _R = r;
    _G = g;
    _B = b;
    _value = value;
}
void NumberDisplay::draw()
{

    gout << move_to(_x,_y) << color(_R,_G,_B) << text(std::to_string(*_value));
}
void NumberDisplay::handle(event ev)
{

}

bool NumberDisplay::isselectable()
{
    return false;
}

void NumberDisplay::updatevalue(int* value)
{
    _value = value;
}
