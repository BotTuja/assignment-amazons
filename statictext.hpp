#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED
#include "widget.hpp"
#include "window.hpp"
class StaticText : public Widget
{
protected:
unsigned char _R,_G,_B;
std::string _text;
public:
StaticText(Window* parent,int x, int y, std::string text, int r, int g, int b);
virtual void handle(genv::event ev);
virtual void draw();
virtual bool isselectable();
};

#endif // STATICTEXT_HPP_INCLUDED
