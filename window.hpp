#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED
#include "graphics.hpp"
#include <vector>
using namespace std;
using namespace genv;

class Widget;

class Window
{
protected:
vector<Widget*> _widgets;
int _sx, _sy;
virtual void passive(event ev);
public:
Window(int sx, int sy);
virtual void wreg(Widget* w);
virtual void wrem(Widget* w);
virtual void cls();
virtual void event_loop();
};


#endif // WINDOW_HPP_INCLUDED
