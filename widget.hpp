#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED
#include "graphics.hpp"
#include "window.hpp"
class Widget
{
protected:
    Window* _parent;
    int _x,_y,_sx,_sy;
    bool _focused;
    bool subselected(genv::event ev,int lx, int ux, int ly, int uy);
    virtual std::string fittext(std::string text, int limit);
public:
    Widget(Window* parent, int x, int y, int sx, int sy);
    virtual void draw() = 0;
    virtual void handle(genv::event ev) = 0;
    virtual bool isselected(genv::event ev);
    virtual void setfocus();
    virtual void clearfocus();
    virtual bool isselectable();
};

#endif // WIDGET_HPP_INCLUDED
