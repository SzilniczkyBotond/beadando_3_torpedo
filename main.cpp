#include "../../headers/legjobb_widget.hpp"
#include "../../headers/ablak.hpp"
#include "../../headers/torpedo_gamemaster.hpp"
#include <cstdlib>

using namespace std;
using namespace genv;

const int XX=800;
const int YY=600;

class Enablakom : public Ablak
{
public:
    Game_master *_GM;
    Tabla *t1;
    Tabla *t2;
    Kivalaszto_widget *k1;
    Kivalaszto_widget *k2;
    Kivalaszto_widget *k3;
    Enablakom();
    virtual void esemeny_ciklus() override;
    virtual void e_jatek();
    virtual void e_hajo_elhelyez();
    virtual void e_enemygenerator();
};

Enablakom::Enablakom()
{
    genv::gout.open(XX,YY);
    t1 = new Tabla(230,325,20,20,"player");
    t2 = new Tabla(500,325,20,20,"cpu");
    vector<string> ss = {"5","4","3","2","1"};
    k1 = new Kivalaszto_widget(20,325,150,20,5,ss);
    vector<string> sss = {"lefele","jobbra"};
    k2 = new Kivalaszto_widget(20,450,150,20,2,sss);
    vector<string> ssss = {"normál","speciális"};
    k3 = new Kivalaszto_widget(20,350,150,20,2,ssss);
    _GM = new Game_master();
}

void Enablakom::esemeny_ciklus()
{
    _widgets.push_back(t1);
    _widgets.push_back(t2);
    _widgets.push_back(k1);
    _widgets.push_back(k2);
    e_hajo_elhelyez(); ///e_ID = 1
    e_enemygenerator(); ///e_ID = 2
    eraseall(2);
    clrscr(XX,YY);
    e_jatek(); ///e_ID = 3
}
void Enablakom::e_hajo_elhelyez()
{
    t1->e_ID = 1;
    t2->e_ID = 1;
    event ev;
    while(gin >> ev && t1->get_hajok_szama()!=5 && ev.keycode!=key_enter)
    {
        if(ev.keycode == key_escape){
                exit(0);
        }
        for(Widget *w : _widgets)
        {
            w->select(ev);
            w->select(ev,_GM->_hossz,_GM->_irany);
        }
        for(size_t y=0; y<_GM->_kezdeti_1.size(); y++){
            for(size_t x=0; x<_GM->_kezdeti_1[y].size(); x++){
                _GM->_kezdeti_1[x][y]=t1->get_terulet(x,y);
            }
        }
        for(size_t y=0; y<_GM->_kezdeti_1.size(); y++){
            for(size_t x=0; x<_GM->_kezdeti_1[y].size(); x++){
                _GM->_kezdeti_2[x][y]=t2->get_terulet(x,y);
            }
        }
        for(Widget *w : _widgets)
        {
            w->ertek_valtozas(ev);
        }
        _GM->_hossz=k1->getter_int();
        _GM->_irany=k2->getter_string();
        for(Widget *w : _widgets)
        {
            w->rajzol();
        }
        gout << refresh;
    }
}
void Enablakom::e_enemygenerator()
{
    event ev;
    t2->e_ID = 2;
    t2->select(ev,_GM->_hossz,_GM->_irany);
}
void Enablakom::e_jatek()
{
    cout << "game" << endl;
    t1->e_ID = 3;
    t2->e_ID = 3;
    event ev;
    while(gin >> ev)
    {
        if(ev.keycode == key_escape){
                exit(0);
        }
        for(Widget *w : _widgets)
        {
            w->select(ev);
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
