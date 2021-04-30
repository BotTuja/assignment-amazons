#include "graphics.hpp"
#include "widget.hpp"
#include "statictext.hpp"
using namespace genv;

StaticText::StaticText(Window* parent,int x, int y, std::string text, int r, int g, int b) : Widget(parent,x,y,0,0)
{
    _R = r;
    _G = g;
    _B = b;
    _text = text;
}
void StaticText::draw()
{
    gout << move_to(_x,_y) << color(_R,_G,_B) << text(_text);
}
void StaticText::handle(event ev)
{

}

bool StaticText::isselectable()
{
    return false;
}
