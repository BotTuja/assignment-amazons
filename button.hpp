#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED
#include "widget.hpp"
#include "window.hpp"
#include <functional>

class Button : public Widget
{
protected:
std::string _title;
std::function<void()> _f;
public:
Button(Window* parent, int x, int y, int sx, int sy, std::string title, std::function<void()> f);
virtual void draw();
void action();
virtual void handle(genv::event ev);
};

#endif // BUTTON_HPP_INCLUDED
