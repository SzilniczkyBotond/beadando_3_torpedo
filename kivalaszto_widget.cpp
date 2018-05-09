#include "kivalaszto_widget.hpp"
using namespace std;
using namespace genv;
const int betu_hossz_pixelben = gout.twidth("a");

Kivalaszto_widget :: Kivalaszto_widget(float pozx, float pozy, float meretx, float merety, int megjelenitendo_db, vector<string> v)
    : Widget(pozx,pozy,meretx,merety), _megjelenitendo_db(megjelenitendo_db), _v(v)
{
    if(!_v.empty()){
        _ertek = "";
        //_ertek = _v[0];
    }
    _legordulve = 0;
    _it=0;
    _ertek_sorszam=0;
    _kijelol=-1;
}
void Kivalaszto_widget :: rajzol() const {
    gout << move_to(_pozx,_pozy) << color(_r,_g,_b) << box(_meretx,_merety)     ///doboz
         << move_to(_pozx+1,_pozy+1) << color(0,0,0) << box(_meretx-2,_merety-2)    ///fo kocka
         << move_to(_pozx+_meretx,_pozy) << color(_r,_g,_b) << box(-_meretx/10,_merety)     ///kicsi doboz
         << move_to(_pozx+_meretx-1,_pozy+1) << color(0,0,0) << box(-_meretx/10+2,_merety-2)    ///kicsi kocka
         << move_to(_pozx+5,_pozy+_merety/2-gout.cdescent()/2+gout.cascent()/2)     ///kivalasztott pozicioja
         << color(_r,_g,_b);
     if(gout.twidth(_ertek)>_meretx-_meretx/10-5){
        gout << text(_ertek.substr(0,(int)(_meretx-_meretx/10-5)/betu_hossz_pixelben));
     }else{
        gout << text(_ertek);
     }
    gout << move_to(_pozx,_pozy+_merety) << color(0,0,0)
         << box(_meretx-_meretx/10+2,_megjelenitendo_db*(gout.cascent()+gout.cdescent())+2);    ///legordules eltuntetése
    if(_legordulve){
        gout << move_to(_pozx,_pozy+_merety) << color(_r,_g,_b)
             << box(_meretx-_meretx/10+2,_megjelenitendo_db*(gout.cascent()+gout.cdescent())+2)
             << move_to(_pozx+_meretx-_meretx/40,_pozy+_merety/4*3)
             << line(-_meretx/10/4,-_merety/2) << line(-_meretx/40,_merety/2)
             << move_to(_pozx+1,_pozy+_merety+1) << color(0,0,0)
             << box(_meretx-_meretx/10,_megjelenitendo_db*(gout.cascent()+gout.cdescent()));
        for(int i=0; i<_megjelenitendo_db && (size_t)i<_v.size(); i++){
                if(i==_kijelol){
                    gout << move_to(_pozx+1,_pozy+_merety+((i)*gout.cascent())+((i)*gout.cdescent()))
                         << color(_r,255,_b) << box(_meretx-_meretx/10,(gout.cascent()+gout.cdescent())+1)
                         << move_to(_pozx+10,_pozy+_merety+((i+1)*gout.cascent())+((i+1)*gout.cdescent())-2) << color(_r,_g,_b);
                    if(!_v.empty()){
                        if(gout.twidth(_v[_it+i])>_meretx-_meretx/10-5){
                            gout << text(_v[_it+i].substr(0,(int)(_meretx-_meretx/10-10)/betu_hossz_pixelben));
                         }else{
                            gout << text(_v[_it+i]);
                         }
                    }
                }else{
                    gout << move_to(_pozx+5,_pozy+_merety+((i+1)*gout.cascent())+((i+1)*gout.cdescent())-2) << color(_r,_g,_b);
                    if(!_v.empty()){
                        if(gout.twidth(_v[_it+i])>_meretx-_meretx/10-5){
                            gout << text(_v[_it+i].substr(0,(int)(_meretx-_meretx/10-5)/betu_hossz_pixelben));
                        }else{
                            gout << text(_v[_it+i]);
                        }
                    }
                }
        }
    }else{
        gout << color(_r,_g,_b)
             << move_to(_pozx+_meretx-_meretx/40,_pozy+_merety/4) << line(-_meretx/10/4,_merety/2) << line(-_meretx/40,-_merety/2);
    }
    gout << refresh;
}

void Kivalaszto_widget::select(event ev){
    if(ev.button==btn_left){
        if(_legordulve){
            if(ev.pos_x>=_pozx && ev.pos_x<=_pozx+_meretx && ev.pos_y>=_pozy
               && ev.pos_y<=_pozy+_merety+_megjelenitendo_db*(gout.cascent()+gout.cdescent())){
                _isselected=1;
                _r=255;
                _g=0;
                _b=0;
            }else{
                _isselected=0;
                _r=_g=_b=255;
            }
        }else{
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
}

void Kivalaszto_widget::ertek_valtozas(event ev){
    if(_isselected){
        if(_legordulve){
            if(ev.button==btn_wheeldown
               && ev.pos_x>_pozx && ev.pos_x<_pozx+_meretx
               && ev.pos_y>_pozy && ev.pos_y<_pozy+_merety+_megjelenitendo_db*(gout.cascent()+gout.cdescent())
               && (size_t)_it<_v.size()-_megjelenitendo_db && _v.size()>(size_t)_megjelenitendo_db){
                    _it++;
               }

            if(ev.button==btn_wheelup
               && ev.pos_x>_pozx && ev.pos_x<_pozx+_meretx
               && ev.pos_y>_pozy && ev.pos_y<_pozy+_merety+_megjelenitendo_db*(gout.cascent()+gout.cdescent())
               && _it>0 && _v.size()>(size_t)_megjelenitendo_db)
               {
                    _it--;
               }

            if(ev.type==ev_mouse && ev.pos_x>_pozx && ev.pos_x<_pozx+_meretx-_meretx/10
               && ev.pos_y>_pozy+_merety && ev.pos_y<_pozy+_merety+_megjelenitendo_db*(gout.cascent()+gout.cdescent()))
            {
                _ertek_sorszam = (int) (ev.pos_y-_pozy-_merety)/(int)(gout.cascent()+gout.cdescent());
                _kijelol = _ertek_sorszam;
            }
            else
            {
                _kijelol=-1;
            }

            if(ev.button==btn_left && ev.pos_x>_pozx && ev.pos_x<_pozx+_meretx-_meretx/10
               && ev.pos_y>_pozy+_merety && ev.pos_y<_pozy+_merety+_megjelenitendo_db*(gout.cascent()+gout.cdescent()))
            {
                if((size_t)_ertek_sorszam+(size_t)_it<_v.size())
                {
                    _ertek = _v[_ertek_sorszam+_it];
                    _legordulve=0;
                    _kijelol=-1;
                }
            }

            if(ev.button==btn_left && ev.pos_x>_pozx+_meretx-_meretx/10 && ev.pos_x<_pozx+_meretx
               && ev.pos_y>_pozy && ev.pos_y<_pozy+_merety){
                _legordulve=0;
               }
        }
        else{
            if(ev.button==btn_left && ev.pos_x>_pozx+_meretx-_meretx/10 && ev.pos_x<_pozx+_meretx
               && ev.pos_y>_pozy && ev.pos_y<_pozy+_merety){
                _legordulve=1;
               }
        }
    }else{
        _legordulve=0;
    }
}

void Kivalaszto_widget::push_back(string s)
{
    _v.push_back(s);
}

