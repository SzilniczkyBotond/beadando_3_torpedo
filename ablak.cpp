#include "ablak.hpp"
#include "graphics.hpp"

using namespace std;

void Ablak::push_back(Widget *v){
    _widgets.push_back(v);
}

void Ablak::esemeny_ciklus()
{

}

void Ablak::eraseall(int a)
{
    vector<Widget*> w;
    for(size_t i=0; i<_widgets.size()-a; i++)
    {
        w.push_back(_widgets[i]);
    }
    _widgets = w;
}
void Ablak::clrscr(int XX, int YY)
{
    gout << move_to(0,0) << color(0,0,0) << box(XX,YY);
}
