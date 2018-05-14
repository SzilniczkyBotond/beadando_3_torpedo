#ifndef STATIC_TEXT_WIDGET_HPP_INCLUDED
#define STATIC_TEXT_WIDGET_HPP_INCLUDED

#include "widget.hpp"

class Static_text_widget : public Widget
{
protected:
    std::string _s;
public:
    Static_text_widget(float x, float y, float sx, float sy, std::string s);
    virtual void rajzol() const override;
    void set_s(std::string s);
    virtual void select(genv::event ev);
    virtual void select(genv::event ev, int a, std::string s);
    virtual void select(genv::event ev, int a, std::string s, bool &b, bool &c);
};

#endif // STATIC_TEXT_WIDGET_HPP_INCLUDED
