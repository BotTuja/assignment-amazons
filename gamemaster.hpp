#ifndef GAMEMASTER_HPP_INCLUDED
#define GAMEMASTER_HPP_INCLUDED
#include "window.hpp"
#include "widget.hpp"
#include <map>

class Game
{
protected:
int _sx,_sy;
std::map<int,Widget*> _board;
int _turn;
Window* _win;
public:
Game(Window* Parent,int x, int y);
~Game();
int getturn();
void moveturn();
bool moveattempt(Widget* pawn, int mx, int my);
};

#endif // GAMEMASTER_HPP_INCLUDED
