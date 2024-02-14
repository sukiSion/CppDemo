#include<iostream>
using namespace std;
void cheers(int);
double cube(double);

void cheers(int n){
    for(int i = 0 ; i < n ; i++){
        cout << "Cheers! ";
    }
    cout << endl;
    return;
}

double cube(double x){
    return x * x * x;
}

int main(int argc, char const *argv[])
{
    cheers(5);
    cout << "Give me a number: ";
    double size;
    cin >> size;
    double volume = cube(size);
    cout << "A " << size << "-foot cube has a volume of " << volume << " cubic feet." << endl;
    cheers(cube(2));
    return 0;
}

