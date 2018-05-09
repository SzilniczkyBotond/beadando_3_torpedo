#ifndef KIVALASZTO_WIDGET_HPP_INCLUDED
#define KIVALASZTO_WIDGET_HPP_INCLUDED
#include "widget.hpp"

class Kivalaszto_widget : public Widget{
protected:
    int _megjelenitendo_db;
    std::vector<string> _v;
    std::string _ertek;
    int _ertek_sorszam;
    int _kijelol;
    int _legordulve;
    int _it;
public:
    Kivalaszto_widget(float pozx, float pozy, float meretx, float merety, int megjelenitendo_db,vector<string> v);
    virtual void rajzol() const override;
    virtual void ertek_valtozas(genv::event ev) override;
    virtual void select(event ev) override;
    virtual void push_back(std::string s);
};
#endif // KIVALASZTO_WIDGET_HPP_INCLUDED
