#include<memory>

class Widget{
    class impl;
    std::unique_ptr<impl> pimpl;
    public:
    void draw();
    Widget(int);
    ~Widget();
    Widget(Widget&&) = default;
    Widget(const Widget &) = delete;
    Widget & operator=(Widget&&);
    Widget & operator=(const Widget &) = delete;
};