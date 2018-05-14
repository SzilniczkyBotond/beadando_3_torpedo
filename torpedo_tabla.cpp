#include "torpedo_tabla.hpp"
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;
using namespace genv;

const int egy=1;
const int ketto=2;
const int meret=30;
const int tabla_meret=8;
const int gray=100;
const int light_gray=200;
const int light_red=250;
const int red=100;
const int white=255;
const int light_blue=255;
const int blue=100;


Terulet::Terulet(Tabla *t, float x, float y, float sx, float sy) : Widget(x,y,sx,sy), _t(t)
{
    _r=_g=0;
    _b=255;
    _size=meret-ketto;
    _hajo=false;
    _lottek_mar=false;
}
Tabla::Tabla(float x, float y, float sx, float sy, string nev) : Widget(x,y,sx,sy),  _nev(nev)
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
void Tabla::select(event ev, int hossz, string irany)
{
    if(e_ID == 1){
        for(size_t x=0; x<_v.size(); x++){
            for(size_t y=0; y<_v.size(); y++){
                _v[x][y]->select(ev,hossz,irany);
            }
        }
    }
    if(e_ID == 2){
        _v[0][0]->select(ev,hossz,irany);
    }
}
void Terulet::select(event ev, int hossz, string irany)
{
    srand(time(NULL));
    if(_t->e_ID == 1 ){
        int ex = ev.pos_x;
        int ey = ev.pos_y;
        int it_x = (_pozx-_t->_pozx)/meret;
        int it_y = (_pozy-_t->_pozy)/meret;
        if(irany=="lefele" && it_y+hossz>tabla_meret){
            it_y = tabla_meret-hossz;
        }
        if(irany=="jobbra" && it_x+hossz>tabla_meret){
            it_x = tabla_meret-hossz;
        }
        if((hossz==1 && !_t->_h1) || (hossz==2 && !_t->_h2) || (hossz==3 && !_t->_h3) || (hossz==4 && !_t->_h4) || (hossz==5 && !_t->_h5)){
            if(_t->_nev == "player"){
                if(!_hajo){
                    _r=_g=0;
                    _b=white;
                }
                if(ex>_pozx && ex<_pozx+_meretx && ey>_pozy && ey<_pozy+_merety && _r!=gray && _g!=gray && _b!=gray){
                    _r=_g=_b=gray;
                    bool van_hajo = false;
                    if(irany=="lefele"){
                        for(int i=it_y; i<it_y+hossz; i++){
                            if(_t->_v[it_x][i]->_hajo){
                                van_hajo = true;
                            }
                        }
                    }
                    if(irany=="jobbra"){
                        for(int i=it_x; i<it_x+hossz; i++){
                            if(_t->_v[i][it_y]->_hajo){
                                van_hajo = true;
                            }
                        }
                    }
                    if(ev.button==btn_left && !van_hajo){
                        if(irany=="lefele"){
                            Hajo *v = new Hajo(this, _pozx,_pozy, (float)_size,(float)_size, irany, hossz, it_x, it_y);
                            switch (v->_hossz){
                                case 1 : _t->_h1++; break;
                                case 2 : _t->_h2++; break;
                                case 3 : _t->_h3++; break;
                                case 4 : _t->_h4++; break;
                                case 5 : _t->_h5++; break;
                            }
                            _t->_hajo.push_back(v);
                            for(int i=it_y; i<it_y+hossz; i++){
                                _t->_v[it_x][i]->_hajo=true;
                                _t->_v[it_x][i]->_r=gray;
                                _t->_v[it_x][i]->_g=gray;
                                _t->_v[it_x][i]->_b=gray;
                            }
                        }
                        if(irany=="jobbra"){
                            Hajo *v = new Hajo(this, _pozx,_pozy, (float)_size,(float)_size, irany, hossz, it_x, it_y);
                            switch (v->_hossz){
                                case 1 : _t->_h1++; break;
                                case 2 : _t->_h2++; break;
                                case 3 : _t->_h3++; break;
                                case 4 : _t->_h4++; break;
                                case 5 : _t->_h5++; break;
                            }
                            _t->_hajo.push_back(v);
                            for(int i=it_x; i<it_x+hossz; i++){
                                _t->_v[i][it_y]->_hajo=true;
                                _t->_v[i][it_y]->_r=gray;
                                _t->_v[i][it_y]->_g=gray;
                                _t->_v[i][it_y]->_b=gray;
                            }
                        }
                    }
                }
            }
        }
    }
    static int a=0;
    if(_t->e_ID == 2 && !a){
        for(int i=5; i>0; i--){
            int c=0;
            int d = 0;
            while(c<64 && !d){
                bool van_hajo = false;
                int b = rand()%2;
                if(b){
                    irany = "jobbra";
                    int px;
                    int py;
                    do{
                        int x = rand()%(tabla_meret-i);
                        int y = rand()%tabla_meret;
                        c++;
                        px=x;
                        py=y;
                        for(int j=0; j<i; j++){
                            if(_t->_v[px+j][py]->_hajo){
                                van_hajo = true;
                            }
                        }
                    }while(van_hajo && c<64);
                    if(c<64){
                        Hajo *v = new Hajo(this, _t->_v[px][py]->_pozx,_t->_v[px][py]->_pozy, (float)_size,(float)_size, irany, i, px, py);
                        _t->_hajo.push_back(v);
                        d++;
                        for(int j=0; j<i; j++){
                            _t->_v[px+j][py]->_hajo=true;
//                            _t->_v[px+j][py]->_r=gray;
//                            _t->_v[px+j][py]->_g=gray;
//                            _t->_v[px+j][py]->_b=gray;
                        }
                        _t->rajzol();
                        gout << refresh;
                    }
                }
                else{
                    irany = "lefele";
                    int px;
                    int py;
                    do{
                        int x = rand()%tabla_meret;
                        int y = rand()%(tabla_meret-i);
                        c++;
                        px=x;
                        py=y;
                        for(int j=0; j<i; j++){
                            if(_t->_v[px][py+j]->_hajo){
                                van_hajo = true;
                            }
                        }
                    }while(van_hajo && c<64);
                    if(c<64){
                        Hajo *v = new Hajo(this, _t->_v[px][py]->_pozx,_t->_v[px][py]->_pozy, (float)_size,(float)_size, irany, i, px, py);
                        _t->_hajo.push_back(v);
                        d++;
                        for(int j=0; j<i; j++){
                            _t->_v[px][py+j]->_hajo=true;
//                            _t->_v[px][py+j]->_r=gray;
//                            _t->_v[px][py+j]->_g=gray;
//                            _t->_v[px][py+j]->_b=gray;
                        }
                    }
                }
                c = 0;
            }
        }
        a++;
    }
}
void Tabla::select(event ev, int hossz, string irany, bool &loves, bool &game_over)
{
    if(e_ID == 3){
        for(size_t x=0; x<_v.size(); x++){
            for(size_t y=0; y<_v.size(); y++){
                _v[x][y]->select(ev,hossz,irany,loves,game_over);
            }
        }
    }
    if(e_ID == 4){
        _v[0][0]->select(ev,hossz,irany,loves,game_over);
    }
}
void Terulet::select(event ev, int hossz, string irany, bool &loves, bool &game_over)
{
    srand(time(NULL));
    if(_t->e_ID == 3){
        int ex = ev.pos_x;
        int ey = ev.pos_y;
        if(_t->_nev == "cpu"){
            if(/*!_hajo && */!_lottek_mar){
                _r=_g=0;
                _b=light_blue;
            }
//            if(_hajo && !_lottek_mar){
//                _r=_g=_b=gray;
//            }
            if(ex>_pozx && ex<_pozx+_meretx && ey>_pozy && ey<_pozy+_merety && !_lottek_mar){
                _r=_g=_b=white;
                if(ev.button==btn_left){
                    loves=true;
                    if(_hajo){
                        _r=light_red;
                        _g=_b=0;
                        _lottek_mar=true;
                    }
                    else{
                        _r=_g=0;
                        _b=blue;
                        _lottek_mar=true;
                    }
                }
            }
            int all_live = _t->_hajo.size();
            for(size_t i=0; i<_t->_hajo.size(); i++){
                int elet=_t->_hajo[i]->_hely.size();
                for(size_t j=0; j<_t->_hajo[i]->_hely.size(); j++){
                    if(_t->_hajo[i]->_hely[j]->_lottek_mar){
                        elet--;
                    }
                }
                if(!elet){
                    all_live--;
                    for(size_t j=0; j<_t->_hajo[i]->_hely.size(); j++){
                        _t->_hajo[i]->_hely[j]->_g=0;
                        _t->_hajo[i]->_hely[j]->_b=0;
                        _t->_hajo[i]->_hely[j]->_r=red;
                    }
                }
            }
            if(!all_live){
                game_over=true;
            }
        }
    }
    if(_t->e_ID == 4){
        int x;
        int y;
        if(_t->_nev == "player"){
            do{
                x = rand()%tabla_meret;
                y = rand()%tabla_meret;
            }while(_t->_v[x][y]->_lottek_mar);
            if(_t->_v[x][y]->_hajo){
                _t->_v[x][y]->_r=light_red;
                _t->_v[x][y]->_g=_t->_v[x][y]->_b=0;
                _t->_v[x][y]->_lottek_mar=true;
            }
            else{
                _t->_v[x][y]->_r=_t->_v[x][y]->_g=0;
                _t->_v[x][y]->_b=blue;
                _t->_v[x][y]->_lottek_mar=true;
            }
            int all_live = _t->_hajo.size();
            for(size_t i=0; i<_t->_hajo.size(); i++){
                int elet=_t->_hajo[i]->_hely.size();
                for(size_t j=0; j<_t->_hajo[i]->_hely.size(); j++){
                    if(_t->_hajo[i]->_hely[j]->_lottek_mar){
                        elet--;
                    }
                }
                if(!elet){
                    all_live--;
                    for(size_t j=0; j<_t->_hajo[i]->_hely.size(); j++){
                        _t->_hajo[i]->_hely[j]->_g=0;
                        _t->_hajo[i]->_hely[j]->_b=0;
                        _t->_hajo[i]->_hely[j]->_r=red;
                    }
                }
            }
            if(!all_live){
                game_over=true;
            }
        }
    }

}
bool Tabla::get_terulet(int x, int y)
{
    return _v[x][y]->_hajo;
}
int Tabla::get_hajok_szama()
{
    return _hajo.size();
}

