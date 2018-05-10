#ifndef HAJO_WIDGET_HPP_INCLUDED
#define HAJO_WIDGET_HPP_INCLUDED

#include "widget.hpp"
#include "torpedo_tabla.hpp"

class Terulet;

class Hajo : public Widget
{
friend class Terulet;
protected:
    Terulet *_t;
    vector<Terulet*> _hely;
    std::string _irany;
    int _hossz;
    int _size;
public:
    Hajo(Terulet *t, float x, float y, float sx, float sy);
    virtual void rajzol() const override{};
};

#endif // HAJO_WIDGET_HPP_INCLUDED
