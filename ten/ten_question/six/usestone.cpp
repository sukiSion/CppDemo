#include<iostream>
#include "stone2.h"
const int SIZE = 6;
int main(int argc, char const *argv[])
{
    using namespace std;
    static Stonewt stonewt_11 = Stonewt(11  , 0);
    Stonewt stonewts[6]{
        275,
        Stonewt(285.7),
        Stonewt(21 , 8.8)
    };
    double pounds;
    int count;
    for(count = 3 ; count < SIZE ; count++){
        cout << "stonewts[" << count << "]: " ;
        if(cin >> pounds){
            stonewts[count] = pounds; 
        }else{
            break;
        }  
    }

    Stonewt minStonewt = stonewts[0];
    Stonewt maxStonewt = stonewts[0];
    int moreThanStonewt11 = 0;
    for(int i = 0 ; i < count ; i++){
        Stonewt temp = stonewts[i];
        minStonewt = temp < minStonewt ? temp : minStonewt;
        maxStonewt = temp > maxStonewt ? temp : maxStonewt;
        if(temp >= stonewt_11){
            moreThanStonewt11++;
        }
    }
    cout << "maxStonewt: " ; 
    maxStonewt.show_lbs();
    cout << "minStonewt: " ; 
    minStonewt.show_lbs();
    cout << "moreThanStonewt11Count: " << moreThanStonewt11 << endl;
    return 0;
}
