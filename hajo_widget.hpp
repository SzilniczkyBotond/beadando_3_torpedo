#ifndef HAJO_WIDGET_HPP_INCLUDED
#define HAJO_WIDGET_HPP_INCLUDED

#include "widget.hpp"
#include "torpedo_tabla.hpp"

class Terulet;

class Hajo : public Widget
{
friend class Terulet;
friend class Enablakom;
protected:
    Terulet *_t;
    vector<Terulet*> _hely;
    std::string _irany;
    int _hossz;
    int _size;
public:
    Hajo(Terulet *t, float x, float y, float sx, float sy, std::string irany, int hossz, int it_x, int it_y);
    virtual void rajzol() const override{};
};

#endif // HAJO_WIDGET_HPP_INCLUDED
