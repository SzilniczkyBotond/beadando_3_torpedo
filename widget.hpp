#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED
#include "graphics.hpp"
#include <iostream>
#include <sstream>
#include <vector>
using namespace genv;
using namespace std;

class Widget{
protected:
    float _pozx, _pozy, _meretx, _merety, _isselected;
    int _r,_g,_b;
public:
    Widget(float pozx, float pozy, float meretx, float merety);
    virtual void rajzol() const = 0;
    virtual void ertek_valtozas(event ev);
    virtual void select(event ev);
};

#endif // WIDGET_HPP_INCLUDED
