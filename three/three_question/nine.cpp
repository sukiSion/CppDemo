#include<iostream>
#include<string>
using namespace std;

struct CandyBar
{
   string brand;
   float weight;
   int calories;
};

int main(int argc, char const *argv[])
{
    int size;
    cout << "Enter size of CandyBars: ";
    cin >> size;
    if(size <= 0){
        size = 1;
    }
    CandyBar * cb = new CandyBar[size];
    cb[0] = {"Mocha Munch" , 2.3 , 350};
    cout << "snack: brand = " << cb[0].brand << ", weight = " << cb[0].weight << ", calories = " << cb[0].calories << endl;
    delete [] cb;
    return 0;
}
