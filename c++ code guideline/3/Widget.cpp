#include "Widget.h"

class Widget::impl{
    int n;
    public:
    void draw(const Widget& w){}
    impl(int n): n(n){}
};
void Widget::draw(){ pimpl->draw(*this);}
Widget::Widget(int n){
    pimpl = std::make_unique<impl>(n);
}
Widget::~Widget() = default;
Widget& Widget::operator=(Widget&&) = default;