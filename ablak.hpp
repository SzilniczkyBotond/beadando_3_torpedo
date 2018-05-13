#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED
#include <vector>
#include "legjobb_widget.hpp"
class Ablak {
protected:
    std::vector<Widget*> _widgets;
public:
    void push_back(Widget *v);
    void eraseall(int a);
    virtual void esemeny_ciklus()=0;
    virtual void clrscr(int XX, int YY);
};

#endif // WINDOW_HPP_INCLUDED
