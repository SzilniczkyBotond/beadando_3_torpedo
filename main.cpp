#include "../../headers/legjobb_widget.hpp"
#include "../../headers/ablak.hpp"

using namespace std;
using namespace genv;

class Enablakom : public Ablak
{
public:
    Tabla *t1;
    Tabla *t2;
    Kivalaszto_widget *k1;
    Kivalaszto_widget *k2;
    Enablakom();
    virtual void esemeny_ciklus() override;
};

Enablakom::Enablakom()
{
    genv::gout.open(800,600);
    t1 = new Tabla(230,325,20,20);
    t2 = new Tabla(500,325,20,20);
    vector<string> ss = {"5","4","3","2","1"};
    k1 = new Kivalaszto_widget(20,325,150,20,5,ss);
    vector<string> sss = {"függõlegesen","vizszintesen"};
    k2 = new Kivalaszto_widget(20,450,150,20,2,sss);
    _widgets.push_back(t1);
    _widgets.push_back(t2);
    _widgets.push_back(k1);
    _widgets.push_back(k2);
}

void Enablakom::esemeny_ciklus()
{
    genv::event ev;
    while(genv::gin >> ev && ev.keycode!=key_escape)
    {
        for(Widget *w : _widgets)
        {
            w->select(ev);
        }
        for(Widget *w : _widgets)
        {
            w->ertek_valtozas(ev);
        }
        for(Widget *w : _widgets)
        {
            w->rajzol();
        }
        gout << refresh;
    }
}



int main()
{
    Enablakom *a = new Enablakom();
    a->esemeny_ciklus();
    return 0;
}
