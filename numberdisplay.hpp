#ifndef NUMBERDISPLAY_HPP_INCLUDED
#define NUMBERDISPLAY_HPP_INCLUDED
#include "widget.hpp"
#include "window.hpp"

class NumberDisplay : public Widget
{
protected:
unsigned char _R,_G,_B;
int* _value;
public:
NumberDisplay(Window* parent,int x, int y, int* value, int r, int g, int b);
virtual void handle(genv::event ev);
virtual void draw();
virtual bool isselectable();
virtual void updatevalue(int* value);
};



#endif // NUMBERDISPLAY_HPP_INCLUDED
