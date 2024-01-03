#include<iostream>

int stonetolb(int sts);

int stonetolb(int sts){
    return 14 * sts;
}

int main(int argc, char const *argv[])
{
    using namespace std;
    int stone;
    cout << "Enter the weight in stone: " << endl;
    cin >> stone;
    int pounds = stonetolb(stone);
    cout << stone <<  " stone = " <<  pounds << " pounds." << endl;
    return 0;
}
