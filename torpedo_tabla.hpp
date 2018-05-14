#ifndef TORPEDO_TABLA_HPP_INCLUDED
#define TORPEDO_TABLA_HPP_INCLUDED

#include "widget.hpp"
#include "hajo_widget.hpp"
using namespace std;

class Terulet;
class Hajo;
class Enablakom;

class Tabla : public Widget
{
friend class Hajo;
friend class Terulet;
friend class Enablakom;
protected:
    Enablakom *_osablak;
    string _nev;
    vector<Hajo*> _hajo;
    vector<vector<Terulet*>> _v;
    int _h1;
    int _h2;
    int _h3;
    int _h4;
    int _h5;
    int _size;
public:

    int e_ID;
    Tabla(float x, float y, float sx, float sy, string nev);
    virtual void rajzol() const override;
    virtual void select(genv::event ev, int hossz, string irany) override;
    virtual void select(genv::event ev, int hossz, string irany, bool &loves, bool &game_over);
    bool get_terulet(int x, int y);
    int get_hajok_szama();
};

class Terulet : public Widget
{
friend class Hajo;
friend class Tabla;
friend class Enablakom;
protected:
    Tabla *_t;
    bool _hajo;
    bool _lottek_mar;
    int _size;
public:
    Terulet(Tabla *t, float x, float y, float sx, float sy);
    virtual void rajzol() const override;
    virtual void rajzol(int x, int y) const;
    virtual void select(genv::event ev, int hossz, string irany);
    virtual void select(genv::event ev, int hossz, string irany, bool &loves, bool &game_over);
};


#endif // TORPEDO_TABLA_HPP_INCLUDED
