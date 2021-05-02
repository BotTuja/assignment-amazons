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
bool _won;
bool _shooting;
int _turncount;
Window* _win;
string _status;
vector<Widget*> _t0;
vector<Widget*> _t1;
void isover();
public:
Game(Window* Parent,int s);
~Game();
void signup(Widget* player, bool team);
bool ismyturn(bool team);
bool getshooting();
void moveturn();
bool moveattempt(Widget* pawn, int mx, int my);
bool shootattempt(Widget* pawn, int mx, int my);
string* accessstatus();
int* accessturncount();
};

#endif // GAMEMASTER_HPP_INCLUDED
