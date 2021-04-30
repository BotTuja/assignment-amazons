#include "widget.hpp"
#include "window.hpp"
#include <vector>
#include "graphics.hpp"
using namespace std;
using namespace genv;

Window::Window(int sx, int sy) : _sx(sx), _sy(sy)
{
gout.open(_sx,_sy);
gout << refresh;
}

void Window::wreg(Widget* w)
{
_widgets.push_back(w);
}

void Window::wrem(Widget* w)
{
vector<Widget*> temp;
for(Widget* a : _widgets)
{
    if(a != w) temp.push_back(a);
}
_widgets = temp;
delete w;
}

void Window::cls()
{
    gout << color(0,0,0) << move_to(0,0) << box(_sx,_sy);
}

void Window::event_loop()
{
    event ev;
    gin.timer(40);
    int focus = -1;
    while(gin >> ev && ev.keycode != key_escape) {

    if(focus != -1)
    {
    _widgets[focus]->handle(ev);
    }

    if(ev.button == btn_left)
    {
    if(focus == -1)
    {
        bool volt = false;
        for(int i = 0; i < _widgets.size(); i++)
        {
        if(_widgets[i]->isselected(ev))
        {
            focus = i;
            volt = true;
        }
        }
        if(!volt) focus = -1;
    }
    else if(!_widgets[focus]->isselected(ev))
    {
        bool volt = false;
        for(int i = 0; i < _widgets.size(); i++)
        {
        if(_widgets[i]->isselected(ev))
        {
            focus = i;
            volt = true;
        }
        }
        if(!volt) focus = -1;
    }
    }
        if(ev.keycode == key_tab)
        {
            for(Widget *&a : _widgets)
            {
            a->clearfocus();
            }
            focus++;
            if(focus >= _widgets.size()) focus = -1;
            else while(focus != -1 && !_widgets[focus]->isselectable())
            {
            if(focus >= _widgets.size()) focus = -1;
            else if(!_widgets[focus]->isselectable())
            {
                focus++;
                if(focus >= _widgets.size()) focus = -1;
            }
            }
            if(focus != -1)
            {
            _widgets[focus]->setfocus();
            }
        }

    if(ev.type == ev_timer)
    {
    cls();
    for(int i = 0; i < _widgets.size(); i++)
    {
        if(i != focus) _widgets[i]->draw();
    }
    if(focus != -1) _widgets[focus]->draw();
    gout << refresh;
    }
    passive(ev);

    }
}

void Window::passive(event ev)
{

}
