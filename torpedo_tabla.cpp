#include "torpedo_tabla.hpp"
#include <string>
using namespace std;
using namespace genv;

const int egy=1;
const int ketto=2;
const int meret=30;
const int tabla_meret=8;
const int gray=200;


Terulet::Terulet(Tabla *t, float x, float y, float sx, float sy) : Widget(x,y,sx,sy), _t(t)
{
    _r=_g=0;
    _b=255;
    _size=meret-ketto;
    _hajo=false;
}
Tabla::Tabla(float x, float y, float sx, float sy, string nev) : Widget(x,y,sx,sy), _nev(nev)
{
    _size=tabla_meret;
    for(int i=0; i<_size; i++){
        vector<Terulet*> vv;
        for(int j=0; j<_size; j++){
            Terulet *t = new Terulet(this,x+i*meret,y+j*meret,meret,meret);
            vv.push_back(t);
        }
        _v.push_back(vv);
    }
}
void Tabla::rajzol() const
{
    for(size_t x=0; x<_v.size(); x++){
        for(size_t y=0; y<_v.size(); y++){
            _v[x][y]->rajzol(_pozx+x*meret,_pozy+y*meret);
        }
    }
}
void Terulet::rajzol(int x, int y) const
{
    gout << move_to(x+egy,y+egy) << color(_r,_g,_b) << box(_size,_size);
}
void Terulet::rajzol() const
{

}
void Tabla::select(event ev)
{
    for(size_t x=0; x<_v.size(); x++){
        for(size_t y=0; y<_v.size(); y++){
            _v[x][y]->select(ev);
        }
    }
}
void Terulet::select(event ev)
{
    if(_t->_nev == "player"){
        if(!_hajo){
            _r=_g=0;
            _b=255;
        }
        if(ev.pos_x>_pozx && ev.pos_x<_pozx+_meretx && ev.pos_y>_pozy && ev.pos_y<_pozy+_merety && _r!=gray && _g!=gray && _b!=gray){
            _r=_g=_b=gray;
            if(ev.button==btn_left && !_hajo){
                Hajo *v = new Hajo(this, _pozx,_pozy, (float)_size,(float)_size);
                _hajo=true;
                _r=_g=_b=gray;
            }
        }
    }
}
bool Tabla::get_terulet(int x, int y)
{
    return _v[x][y]->_hajo;
}

