#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    cout << "Enter a integer: ";
    int by;
    cin >>  by;
    cout << "Counting by " << by << "s" << endl;
    for (int i = 0 ; i < 100 ; i += by){
        cout << i << endl;
    }
    return 0;
}
