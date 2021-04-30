#include "window.hpp"
#include "widget.hpp"
#include "gamemaster.hpp"
#include <map>
#include "amazon.hpp"
#include <iostream>

const int HH = 100;

class Amazon;
//Amazon::Amazon(Window* parent, Game* master, int x, int y, bool team);

using namespace genv;
using namespace std;

Game::Game(Window* Parent,int x, int y) : _win(Parent), _sx(x), _sy(y), _turn(0)
{
_board[0] = new Amazon(_win,this,0,HH,0);
_board[5] = new Amazon(_win,this,250,HH,1);
_board[30] = new Amazon(_win,this,0,HH+250,1);
_board[35] = new Amazon(_win,this,250,HH+250,0);
}

Game::~Game()
{
for(pair<int, Widget*> p : _board)
{
_win->wrem(p.second);
}
}

int Game::getturn()
{
return _turn;
}

void Game::moveturn()
{
    _turn++;
    if(_turn > 1) _turn = 0;
}


bool Game::moveattempt(Widget* pawn, int mx, int my)
{
if(my < HH) return false;
int gx = mx/50;
int gy = (my-HH)/50;
map<int, Widget*>::iterator bi = _board.find(gx+6*gy);
if(bi != _board.end()) return false;
else
{
for(pair<int,Widget*> p : _board)
{
if(p.second == pawn)
{
        map<int, Widget*>::iterator bi2 = _board.find(p.first);
        _board.erase(bi2);
        _board[gx+6*gy] = pawn;
        moveturn();
        return true;
        //currently the pawns can move anywhere, and the arrow shooting have not been implemented yet.

}
}
}
}

