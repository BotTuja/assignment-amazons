#include "graphics.hpp"
#include "widget.hpp"
#include "amazon.hpp"
#include "gamemaster.hpp"

using namespace genv;

Amazon::Amazon(Window* parent, Game* master, int x, int y, bool team) : Widget(parent,x,y,50,50), _master(master), _team(team), _shooting(false)
{

}

void Amazon::draw()
{
if(_team && !_focused) gout << color(0,100,50);
else if(_team && _focused) gout << color(0,255,50);
else if(!_team && !_focused) gout << color(0,50,100);
else if(!_team && _focused) gout << color(0,50,255);

gout << move_to(_x+5,_y+5) << box(_sx-10,_sy-10);

}

void  Amazon::handle(genv::event ev)
{
if(!(subselected(ev,_x,_x+_sx,_y,_y+_sy)) && ev.button == btn_left)
{
    if(!_shooting)
    {
    if(_master->moveattempt(this, ev.pos_x, ev.pos_y))
    {
    _x = (ev.pos_x/50)*50;
    _y = 100+((ev.pos_y-100)/50)*50;
    _shooting = true;
    }
    }
    else
    {
    if(_master->shootattempt(this, ev.pos_x, ev.pos_y)) _shooting = false;
    }
}
}

bool Amazon::isselectable()
{
if(_team == _master->getturn() && _shooting == _master->getshooting()) return true;
else return false;

}

bool Amazon::isselected(genv::event ev)
{
    if(subselected(ev,_x,_x+_sx,_y,_y+_sy) && isselectable()) _focused = true;
    else
    {
    if(_focused) handle(ev);
    _focused = false;
    }
    return _focused;
}
