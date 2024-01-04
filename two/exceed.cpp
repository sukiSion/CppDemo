#include<iostream>
#define ZERO 0
#include<climits>

int main(int argc, char const *argv[])
{
    using namespace std;
    short sam = SHRT_MAX;
    unsigned short sue = sam;
    cout << "Sam has " << sam << " dollars and Sue has " << sue << " dollars deposited." << endl;
    cout << "Add $1 to each account." << endl;
    sue += 1;
    sam += 1;
    cout << "Now Sam has " << sam << " dollars and Sue has " << sue << " dollars deposited." << endl;
    cout << "Poor Sam!";
    sam = ZERO;
    sue = ZERO;
    cout << "Sam has " << sam << " dollars and Sue has " << sue << " dollars deposited." << endl;
    cout << "Take $1 from each account." << endl;
    sue -= 1;
    sam -= 1;
    cout << "Now Sam has " << sam << " dollars and Sue has " << sue << " dollars deposited." << endl;
    cout << "Lucky Sue!";
    return 0;
}
