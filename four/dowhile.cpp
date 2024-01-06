#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    int n;
    cout << "Enter number in the rang 1-10 to find my favorite number" << endl;
    do{
        cin >> n;
    }while(n != 7);
    cout << "Yes , 7 is my favorite." << endl;
    return 0;
}
