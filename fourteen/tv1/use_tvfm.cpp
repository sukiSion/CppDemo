#include<iostream>
#include "tvfm.h"

int main(int argc, char const *argv[])
{
    using std::cout;
    using std::endl;
    Tv s42;
    cout << "Initial settings for 42\" TV:" << endl;
    s42.settings();
    s42.onoff();
    s42.chanup();
    cout << endl << "Adjust settings for 42\" TV:" << endl;
    s42.settings();

    Remote gery;
    gery.set_chan(s42 , 10);
    gery.volup(s42);
    gery.volup(s42);
    cout << endl << "42\" settings after using remote:" << endl;
    s42.settings();
    Tv s58(Tv::On);
    s58.set_mode();
    gery.set_chan(s58 , 28);
    cout << endl << "58\" settings:" << endl;
    s58.settings();
    return 0;
}
