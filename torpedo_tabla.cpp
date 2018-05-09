#include "torpedo_tabla.hpp"
using namespace std;
using namespace genv;

const int egy=1;
const int ketto=2;
const int meret=30;


Terulet::Terulet(float x, float y, float sx, float sy) : Widget(x,y,sx,sy)
{
    _r=_g=0;
    _b=255;
    _size=meret-ketto;
}
Tabla::Tabla(float x, float y, float sx, float sy) : Widget(x,y,sx,sy)
{
    _size=8;
    for(int x=0; x<_size; x++){
        vector<Terulet*> vv;
        for(int y=0; y<_size; y++){
            Terulet *t = new Terulet(meret,meret,meret,meret);
            vv.push_back(t);
        }
        _v.push_back(vv);
    }
}
void Tabla::rajzol() const
{
    for(int x=0; x<_size; x++){
        for(int y=0; y<_size; y++){
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
