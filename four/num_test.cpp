#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    cout << "Enter the starting countdown value";
    int limit;
    cin >> limit;
    int i {limit};
    for(i ; i ; i-- ){
        cout << "i = " << i << endl;
    }
    cout << "Done now that i = " << i << endl;
    return 0;
}
