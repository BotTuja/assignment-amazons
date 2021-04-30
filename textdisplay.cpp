#include "graphics.hpp"
#include "widget.hpp"
#include "textdisplay.hpp"
using namespace genv;

TextDisplay::TextDisplay(Window* parent,int x, int y, std::string* text, int r, int g, int b) : Widget(parent,x,y,0,0)
{
    _R = r;
    _G = g;
    _B = b;
    _text = text;
}
void TextDisplay::draw()
{
    gout << move_to(_x,_y) << color(_R,_G,_B) << text(*_text);
}
void TextDisplay::handle(event ev)
{

}

bool TextDisplay::isselectable()
{
    return false;
}

void TextDisplay::updatetext(std::string* text)
{
    _text = text;
}
