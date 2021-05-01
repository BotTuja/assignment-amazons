#ifndef FIRE_HPP_INCLUDED
#define FIRE_HPP_INCLUDED
#include "window.hpp"
#include "widget.hpp"
#include "graphics.hpp"

class Fire : public Widget
{
public:
Fire(Window* parent, int x, int y);
virtual void draw();
virtual void handle(genv::event ev);
virtual bool isselectable();
};


#endif // FIRE_HPP_INCLUDED
