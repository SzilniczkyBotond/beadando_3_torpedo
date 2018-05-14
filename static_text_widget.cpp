#include "static_text_widget.hpp"

using namespace std;
using namespace genv;

Static_text_widget::Static_text_widget(float x, float y, float sx, float sy, string s) : Widget(x,y,sx,sy), _s(s)
{

}
void Static_text_widget::rajzol() const
{
    gout <<move_to(_pozx,_pozy) << color(255,255,255) << text(_s);
}
void Static_text_widget::set_s(string s)
{
    _s=s;
}
void Static_text_widget::select(genv::event ev){}
void Static_text_widget::select(genv::event ev, int a, string s){}
void Static_text_widget::select(genv::event ev, int a, string s, bool &b, bool &c){}
