#ifndef TEXTDISPLAY_HPP_INCLUDED
#define TEXTDISPLAY_HPP_INCLUDED
#include "widget.hpp"
#include "window.hpp"

class TextDisplay : public Widget
{
protected:
unsigned char _R,_G,_B;
std::string* _text;
public:
TextDisplay(Window* parent,int x, int y, std::string* text, int r, int g, int b);
virtual void handle(genv::event ev);
virtual void draw();
virtual bool isselectable();
virtual void updatetext(std::string* text);
};


#endif // TEXTDISPLAY_HPP_INCLUDED
