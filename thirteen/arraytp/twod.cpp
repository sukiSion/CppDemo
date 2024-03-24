#include<iostream>
#include "arraytp.h"
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    ArratTP<int , 10> sums;
    ArratTP<double , 10> aves;
    ArratTP<ArratTP<int , 5> , 10> twodee;
    int i , j;
    for(i = 0 ; i < 10 ; i++){
        sums[i] = 0;
        for(j = 0 ;  j < 5 ;j++){
            twodee[i][j] = (i + 1) * (j + 1 );
            sums[i] += twodee[i][j];
        }
        aves[i] = sums[i] / 5.0;
    }
    for(i = 0 ; i < 10 ; i++){
        for(j = 0 ;  j < 5 ;j++){
            cout.width(2);
            cout << twodee[i][j] << ' ';
        }
        cout << ": sum = ";
        cout.width(3);
        cout << sums[i] << ", average = " << aves[i] << endl;
    }
    return 0;
}
