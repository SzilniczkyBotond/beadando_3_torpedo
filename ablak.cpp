#include "ablak.hpp"
#include "graphics.hpp"

void Ablak::push_back(Widget *v){
    _widgets.push_back(v);
}

void Ablak::esemeny_ciklus()
{

}

void Ablak::eraseall()
{
    for(size_t i=0;i<_widgets.size();i++)
    {
        _widgets.pop_back();
    }
}
