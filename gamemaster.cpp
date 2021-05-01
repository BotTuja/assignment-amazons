#include "window.hpp"
#include "widget.hpp"
#include "gamemaster.hpp"
#include <map>
#include "amazon.hpp"
#include <iostream>
#include "fire.hpp"

const int SIZE = 6;
const int HH = 100;

class Amazon;
//Amazon::Amazon(Window* parent, Game* master, int x, int y, bool team);

using namespace genv;
using namespace std;

Game::Game(Window* Parent,int s) : _win(Parent), _sx(s), _sy(s), _turn(0), _shooting(false)
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

bool Game::getturn()
{
return _turn;
}

bool Game::getshooting()
{
return _shooting;
}

void Game::moveturn()
{
    _turn = !_turn;
}


bool Game::moveattempt(Widget* pawn, int mx, int my)
{
//IS ON BOARD?
if(my < HH) return false;

//GET TARGET
int gx = mx/50;
int gy = (my-HH)/50;

//IS THE TARGET EMPTY?
if(_board.find(gx+SIZE*gy) != _board.end()) return false;

//GET CURRENT POSITION
pair<int,Widget*> p = {0,0};
for(pair<int,Widget*> p0 : _board)
{
if(p0.second == pawn) p = p0;
}
int cx = p.first%SIZE;
int cy = p.first/SIZE;

//IS THE DIRECTION OF THE MOVEMENT LEGAL?
if(!(cx == gx || cy == gy || abs(cx-gx) == abs(cy-gy))) return false;

//IS THE PATH CLEAR?
while(gx != cx || gy != cy)
{
if(gx > cx) cx++;
if(gx < cx) cx--;
if(gy > cy) cy++;
if(gy < cy) cy--;
if(_board.find(cx+SIZE*cy) != _board.end()) return false;
}

//MOVE
_board.erase(_board.find(p.first));
_board[gx+SIZE*gy] = pawn;
_shooting = true;
return true;

//The pawns can only move legally now, but the arrow shooting have not been implemented yet.

}

bool Game::shootattempt(Widget* pawn, int mx, int my)
{
//IS ON BOARD?
if(my < HH) return false;

//GET TARGET
int gx = mx/50;
int gy = (my-HH)/50;

//IS THE TARGET EMPTY?
if(_board.find(gx+SIZE*gy) != _board.end()) return false;

//GET CURRENT POSITION
pair<int,Widget*> p = {0,0};
for(pair<int,Widget*> p0 : _board)
{
if(p0.second == pawn) p = p0;
}
int cx = p.first%SIZE;
int cy = p.first/SIZE;

//IS THE DIRECTION OF THE MOVEMENT LEGAL?
if(!(cx == gx || cy == gy || abs(cx-gx) == abs(cy-gy))) return false;

//IS THE PATH CLEAR?
while(gx != cx || gy != cy)
{
if(gx > cx) cx++;
if(gx < cx) cx--;
if(gy > cy) cy++;
if(gy < cy) cy--;
if(_board.find(cx+SIZE*cy) != _board.end()) return false;
}

//MOVE
_board[gx+SIZE*gy] = new Fire(_win,gx*50,HH+gy*50);
_shooting = false;
moveturn();
return true;

//The pawns can only move legally now, but the arrow shooting have not been implemented yet.

}
