#include<iostream>
#include<string>
using namespace std;

struct car
{
    string manufacturer;
    int year;
};


int main(int argc, char const *argv[])
{
    int count;
    cout << "How many cars do you wish to catalog? ";
    // 注意这里cin
    // 这里的换行符会被下面的getline()捕获，所以这里应该提前捕获
    (cin >> count).get();

    car * p_car = new car[count];

    for(int i = 0 ; i < count ; i++){
        cout << "Car #" << (i + 1) << endl;
        cout << "Please enter the make: ";
        getline(cin , p_car[i].manufacturer);
        cout << "Please enter the made: ";
        (cin >> p_car[i].year).get();
    }
    for(int i = 0 ; i < count ; i++){
        cout << p_car[i].year << " " <<  p_car[i].manufacturer << endl;
    }
    delete [] p_car;

    return 0;
}
