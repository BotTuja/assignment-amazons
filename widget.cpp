#include "graphics.hpp"
#include "widget.hpp"
#include "window.hpp"

using namespace std;
using namespace genv;

Widget::Widget(Window* parent, int x, int y, int sx, int sy) : _parent(parent), _x(x), _y(y), _sx(sx), _sy(sy)
{
_focused = false;
_parent->wreg(this);
}

bool Widget::subselected(event ev, int lx, int ux, int ly, int uy)
{
    if(ev.pos_x > lx && ev.pos_x < ux && ev.pos_y > ly && ev.pos_y < uy) return true;
    return false;
}

bool Widget::isselected(event ev)
{
    if(subselected(ev,_x,_x+_sx,_y,_y+_sy)) _focused = true;
    else _focused = false;
    return _focused;
}

void Widget::setfocus()
{
_focused = true;
}
void Widget::clearfocus()
{
_focused = false;
}

string Widget::fittext(string text, int limit)
{
    if(gout.twidth(text) < limit) return text;
    for(int i = 0; i < text.length()-1; i++)
    {
    if(gout.twidth(text.substr(0,i+1)) >= limit) return text.substr(0,i-1) + "-";
    }
    return text;
}

bool Widget::isselectable()
{
    return true;
}
