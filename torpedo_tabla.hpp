#ifndef TORPEDO_TABLA_HPP_INCLUDED
#define TORPEDO_TABLA_HPP_INCLUDED

#include "widget.hpp"
#include "hajo_widget.hpp"
using namespace std;

class Terulet;
class Hajo;

class Tabla : public Widget
{
friend class Hajo;
friend class Terulet;
protected:
    string _nev;
    vector<vector<Terulet*>> _v;
    vector<Hajo*> _hajo;
    int _size;
public:
    Tabla(float x, float y, float sx, float sy, string nev);
    virtual void rajzol() const override;
    virtual void select(genv::event ev) override;
};

class Terulet : public Widget
{
friend class Hajo;
friend class Tabla;
protected:
    Tabla *_t;
    bool _hajo;
    int _size;
public:
    Terulet(Tabla *t, float x, float y, float sx, float sy);
    virtual void rajzol() const override;
    virtual void rajzol(int x, int y) const;
    virtual void select(genv::event ev);
};


#endif // TORPEDO_TABLA_HPP_INCLUDED
