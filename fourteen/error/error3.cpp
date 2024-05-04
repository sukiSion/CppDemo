#include<iostream>
double hmean(double a , double b){
    if(a == -b) {
        throw "bad hmean() arguments: a = -b not allowed";
    }
    return 2.0 * a * b / (a + b);
}

int main(int argc, char const *argv[])
{
    double x , y , z;
    using std::cout;
    using std::cin;
    using std::endl;
    cout << "Enter two numbers: ";
    while(cin >> x >> y){
        try{
            z = hmean(x , y);
        }catch(const char * s){
            cout << s << endl;
            cout << "Enter a new pair of numbers: ";
            continue;
        }
        cout << "Harmonic mean of  " << x << " and " << y << " is " << z << endl;
        cout << "Enter next set of numbers <q to quit>: ";
    }
    cout << "Bye!" << endl;
    return 0;
}
