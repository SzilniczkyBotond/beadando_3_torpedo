#include "hajo_widget.hpp"

using namespace genv;

Hajo::Hajo(Terulet *t, float x, float y, float sx, float sy, std::string irany, int hossz)
            : Widget(x,y,sx,sy),_t(t), _irany(irany), _hossz(hossz)
{
    _size = 30;
    _r=_g=_b=200;
}

