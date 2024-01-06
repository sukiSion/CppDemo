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
    Pizza * p_pizza = new Pizza;
    cout << "Enter name: " ;
    getline(cin , p_pizza->name);
    cout << "Enter diameter: ";
    cin >> p_pizza->diameter;
    cout << "Enter weight: ";
    cin >> p_pizza->weight;

    cout << "pizza: name = " << p_pizza->name << ", diameter = " << p_pizza->diameter << ", weight = " << p_pizza->weight << endl;

    delete p_pizza;
    return 0;
}