#include "widget.hpp"
using namespace genv;

Widget :: Widget(float pozx, float pozy, float meretx, float merety)
: _pozx(pozx), _pozy(pozy), _meretx(meretx), _merety(merety)
{
    _isselected = 0;
    _r=_g=_b=255;
}

void Widget::ertek_valtozas(genv::event ev){
}

void Widget::select(event ev){
    if(ev.button==btn_left){
        if(ev.pos_x>=_pozx && ev.pos_x<=_pozx+_meretx && ev.pos_y>=_pozy && ev.pos_y<=_pozy+_merety){
            _isselected=1;
            _r=255;
            _g=0;
            _b=0;
        }else{
            _isselected=0;
            _r=_g=_b=255;
        }
    }
}
