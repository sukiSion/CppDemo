#include<iostream>
#include<string>
using namespace std;

struct Pizza
{
    string name;
    int diameter;
    float weight;
};


int main(int argc, char const *argv[])
{
    Pizza pizza;
    cout << "Enter name: " ;
    getline(cin , pizza.name);
    cout << "Enter diameter: ";
    cin >> pizza.diameter;
    cout << "Enter weight: ";
    cin >> pizza.weight;
    cout << "pizza: name = " << pizza.name << ", diameter = " << pizza.diameter << ", weight = " << pizza.weight << endl;
    return 0;
}
