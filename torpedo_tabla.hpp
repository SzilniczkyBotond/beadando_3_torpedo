#ifndef TORPEDO_TABLA_HPP_INCLUDED
#define TORPEDO_TABLA_HPP_INCLUDED

#include "widget.hpp"
using namespace std;

class Terulet;

class Tabla : public Widget
{
protected:
    vector<vector<Terulet*>> _v;
    int _size;
public:
    Tabla(float x, float y, float sx, float sy);
    virtual void rajzol() const override;
};

class Terulet : public Widget
{
protected:
    int _size;
public:
    Terulet(float x, float y, float sx, float sy);
    virtual void rajzol() const override;
    virtual void rajzol(int x, int y) const;
};


#endif // TORPEDO_TABLA_HPP_INCLUDED
