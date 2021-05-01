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
bool _turn;
bool _shooting;
Window* _win;
public:
Game(Window* Parent,int s);
~Game();
bool getturn();
bool getshooting();
void moveturn();
bool moveattempt(Widget* pawn, int mx, int my);
bool shootattempt(Widget* pawn, int mx, int my);
};

#endif // GAMEMASTER_HPP_INCLUDED
