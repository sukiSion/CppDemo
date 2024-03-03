#include<iostream>
#include "stone.h"

int main(int argc, char const *argv[])
{
    using std::cout;
    using std::endl;
    Stonewt incognito = 275;
    Stonewt wolfe(285.7 , Stonewt::Mode::INT_POUND);
    Stonewt taft(21 , 8.8 , Stonewt::Mode::DOUBLE_POUND);
    
    cout << "The celebrity weighed ";
    cout << incognito;
    cout << "The detective weighed ";
    cout << wolfe;
    cout << "The President weighed ";
    cout << taft;

    cout << "After dinner, the celebrity weighed " << endl;
    incognito = incognito + 1.8;
    cout << incognito;
    cout << "After play, the detective weighed " << endl;
    wolfe = wolfe - 5;
    cout << wolfe;
    cout << "After dinner, the President weighed " << endl;
    taft = taft * 1.2;
    cout << taft;
    return 0;
}
