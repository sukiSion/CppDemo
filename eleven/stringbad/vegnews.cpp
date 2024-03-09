#include "stringbad.h"
using std::cout;
using std::endl;
void callme1(StringBad & rsb){
    cout << "String passed by reference:" << endl;
    cout << " \"" << rsb << "\"" << endl;
}

void callme2(StringBad  sb){
    cout << "String passed by value:" << endl;
    cout << " \"" << sb << "\"" << endl;
}

int main(int argc, char const *argv[])
{
    {
        cout << "Starting an inner block."  << endl;
        StringBad headline1("Celery stalks at Midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spinach Leaves Bowl for Dollars");
        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;
        callme1(headline1);
        cout << "headline1: " << headline1 << endl;
        callme2(headline2);
        cout << "headline2: " << headline2 << endl;
        cout << "Initital one object to another:" << endl;
        StringBad sailor = sports;
        cout << "sailor: " << sailor << endl;
        cout << "Assign one object to another: " << endl;
        StringBad knot;
        knot = headline1;
        cout << "knot: " << knot << endl;
        cout << "Exiting the block." << endl;
    }
    cout << "End of main()" << endl;
    return 0;
}
