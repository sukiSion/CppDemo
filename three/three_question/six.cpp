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
    CandyBar cb[3]{
        {"Mocha Munch" , 2.3 , 350},
        {"Cottage Cheese Alfredo" , 3.6 , 450},
        {"Chicken Parmesan" , 4.9 , 550},
    };
    for(int i = 0 ; i < sizeof(cb) / sizeof(cb[0]) ; i ++){
        cout << "snack: brand = " << cb[i].brand << ", weight = " << cb[i].weight << ", calories = " << cb[i].calories << endl;
    }
    return 0;
}
