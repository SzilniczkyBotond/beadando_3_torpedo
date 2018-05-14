#include "hajo_widget.hpp"

using namespace std;
using namespace genv;

Hajo::Hajo(Terulet *t, float x, float y, float sx, float sy, std::string irany, int hossz, int it_x, int it_y)
            : Widget(x,y,sx,sy),_t(t), _irany(irany), _hossz(hossz)
{
    if(irany=="jobbra"){
        for(int i=0; i<hossz; i++){
            _hely.push_back(t->_t->_v[it_x+i][it_y]);
        }
    }
    if(irany=="lefele"){
        for(int i=0; i<hossz; i++){
            _hely.push_back(t->_t->_v[it_x][it_y+i]);
        }
    }
    _size = 30;
    _r=_g=_b=200;
}

