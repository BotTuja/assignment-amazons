#ifndef AMAZON_HPP_INCLUDED
#define AMAZON_HPP_INCLUDED
#include "window.hpp"
#include "widget.hpp"
#include "gamemaster.hpp"
#include "graphics.hpp"

class Amazon : public Widget
{
Game* _master;
bool _team;
bool _shooting;
public:
Amazon(Window* parent, Game* master, int x, int y, bool team);
virtual void draw();
virtual void handle(genv::event ev);
virtual bool isselectable();
virtual bool isselected(genv::event ev);
};


#endif // AMAZON_HPP_INCLUDED
