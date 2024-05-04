#include "exc_mean.h"
#include<cmath>
#include<iostream>

double hmean(double a , double b){
    if(a == -b){
        throw bad_hmean();
    }else{
        return 2.0 * a * b / (a + b);
    }
}

double gmean(double a , double b){
    if(a < 0 || b < 0){
        throw bad_gmean();
    }else{
        return sqrt(a * b);  
    }
}

int main(int argc, char const *argv[])
{
    using std::cout;
    using std::endl;
    using std::cin;
    double x , y , z;
    cout << "Enter two numbers: ";
    while(cin >> x >> y){
        try{
            z = hmean(x , y);
            cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
            z = gmean(x  ,y);
            cout << "Geometric mean of " << x << " and " << y << " is " << z << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }catch(bad_hmean & bg){
            cout << bg.what();
            cout << "Try again." << endl;
            continue;
        }catch(bad_gmean & hg){
            cout << hg.what();
            cout << "Sorry, you don't get to play any more." << endl;
            break;
        } 
    }
    cout << "Bye!" << endl;
    return 0;
}
