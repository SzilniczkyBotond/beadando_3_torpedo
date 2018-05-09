#include "ablak.hpp"
#include "graphics.hpp"

void Ablak::push_back(Widget *v){
    _widgets.push_back(v);
}

void Ablak::esemeny_ciklus()
{
    /*event ev;
    while(gin >> ev && ev.keycode!=key_escape) {
        for(Widget *w : _widgets){
            w->select(ev);
        }
        for(Widget *w : _widgets){
            w->ertek_valtozas(ev);
        }
        for(const Widget *w : _widgets){
            w->rajzol();
        }
    }*/
}

