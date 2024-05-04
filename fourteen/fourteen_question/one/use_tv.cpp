#include<iostream>
#include "tv.h"

int main(int argc, char const *argv[])
{
    using std::cout;
    using std::endl;
    Tv s42;
    Remote gery;
    cout << "Initial settings for 42\" TV:" << endl;
    s42.settings();
    s42.onoff();
    s42.chanup();
    cout << endl << "Adjust settings for 42\" TV:" << endl;
    s42.settings();
    cout << "grey mode: " << endl;
    gery.show_remote_mode();

    
    gery.set_chan(s42 , 10);
    gery.volup(s42);
    gery.volup(s42);
    gery.set_remote_mode();
    cout << endl << "42\" settings after using remote:" << endl;
    s42.settings();
    cout << "grey mode: " << endl;
    gery.show_remote_mode();
    Tv s58(Tv::On);
    s58.set_tv_mode();
    gery.set_chan(s58 , 28);
    s58.set_remote_mode(gery);
    cout << endl << "58\" settings:" << endl;
    s58.settings();
    cout << "grey mode: " << endl;
    gery.show_remote_mode();
    return 0;
}