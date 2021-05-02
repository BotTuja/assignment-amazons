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

void Game::isover()
{
    if(_turn)
    {
        for(Widget* p1 : _t1)
        {
            pair<int,Widget*> p2 = {0,0};
            for(pair<int,Widget*> p3 : _board)
            {
                if(p3.second == p1) p2 = p3;
            }
            int cx = p2.first%SIZE;
            int cy = p2.first/SIZE;
            for(int i = -1; i < 2; i++)
            {
                for(int j = -1; j < 2; j++)
                {
                    if(cx+j >= 0 && cx+j <= 5 && cy+i >= 0 && cy+i <= 5)
                    {
                    if(_board.find((cx+j)+(cy+i)*6) == _board.end()) return;
                    }
                }
            }

        }
        _won = true;
        _status = "Blue has won!";
        return;
    }
    for(Widget* p1 : _t0)
        {
            pair<int,Widget*> p2 = {0,0};
            for(pair<int,Widget*> p3 : _board)
            {
                if(p3.second == p1) p2 = p3;
            }
            int cx = p2.first%SIZE;
            int cy = p2.first/SIZE;
            for(int i = -1; i < 2; i++)
            {
                for(int j = -1; j < 2; j++)
                {
                    if(cx+j >= 0 && cx+j <= 5 && cy+i >= 0 && cy+i <= 5)
                    {
                    if(_board.find((cx+j)+(cy+i)*6) == _board.end()) return;
                    }
                }
            }

        }
        _won = true;
        _status = "Green has won!";
        return;
}


Game::Game(Window* Parent,int s) : _win(Parent), _sx(s), _sy(s), _turn(0), _shooting(false), _won(false), _status("Game Started, Blue moves first"), _turncount(0)
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

void Game::signup(Widget* player, bool team)
{
    if(team)
    {
        _t1.push_back(player);
        return;
    }
    _t0.push_back(player);
}

bool Game::ismyturn(bool team)
{
    if(_turn == team && !_won) return true;
    else return false;
}

bool Game::getshooting()
{
    return _shooting;
}

void Game::moveturn()
{
    _turncount++;
    _turn = !_turn;
    if(_turn) _status = "Green's turn to move";
    else _status = "Blue's turn to move";
    isover();
}


bool Game::moveattempt(Widget* pawn, int mx, int my)
{
//IS ON BOARD?
    if(my < HH) return false;

//GET TARGET
    int gx = mx/50;
    int gy = (my-HH)/50;

//IS THE TARGET EMPTY?
    if(_board.find(gx+SIZE*gy) != _board.end())
    {
        _status = "Tile occupied";
        return false;
    }

//GET CURRENT POSITION
    pair<int,Widget*> p = {0,0};
    for(pair<int,Widget*> p0 : _board)
    {
        if(p0.second == pawn) p = p0;
    }
    int cx = p.first%SIZE;
    int cy = p.first/SIZE;

//IS THE DIRECTION OF THE MOVEMENT LEGAL?
    if(!(cx == gx || cy == gy || abs(cx-gx) == abs(cy-gy)))
    {
        _status = "You can't get there";
        return false;
    }
//IS THE PATH CLEAR?
    while(gx != cx || gy != cy)
    {
        if(gx > cx) cx++;
        if(gx < cx) cx--;
        if(gy > cy) cy++;
        if(gy < cy) cy--;
        if(_board.find(cx+SIZE*cy) != _board.end())
        {
            _status = "Your path is blocked";
            return false;
        }
    }

//MOVE
    _board.erase(_board.find(p.first));
    _board[gx+SIZE*gy] = pawn;
    _shooting = true;
    _status = "Shoot an arrow";
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
    if(_board.find(gx+SIZE*gy) != _board.end())
    {
        _status = "You can only shoot on empty tiles";
        return false;
    }

//GET CURRENT POSITION
    pair<int,Widget*> p = {0,0};
    for(pair<int,Widget*> p0 : _board)
    {
        if(p0.second == pawn) p = p0;
    }
    int cx = p.first%SIZE;
    int cy = p.first/SIZE;

//IS THE DIRECTION OF THE MOVEMENT LEGAL?
    if(!(cx == gx || cy == gy || abs(cx-gx) == abs(cy-gy)))
    {
        _status = "You can't aim there";
        return false;
    }
//IS THE PATH CLEAR?
    while(gx != cx || gy != cy)
    {
        if(gx > cx) cx++;
        if(gx < cx) cx--;
        if(gy > cy) cy++;
        if(gy < cy) cy--;
        if(_board.find(cx+SIZE*cy) != _board.end())
        {
            _status = "The arrow need a clear path";
            return false;
        }
    }

//MOVE
    _board[gx+SIZE*gy] = new Fire(_win,gx*50,HH+gy*50);
    _shooting = false;
    moveturn();
    return true;

//The pawns can only move legally now, but the arrow shooting have not been implemented yet.

}

string* Game::accessstatus()
{
    return &_status;
}

int* Game::accessturncount()
{
    return &_turncount;
}
