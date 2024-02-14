#include<iostream>
using namespace std;
int fill_array(double[] , int);
void show_array(const double[] , int);
void revalue(double , double[] , int);

int fill_array(double ar[] , int limit){
    double temp;
    int i = 0;
    for(i ; i < limit ; i++){
        cout << "Enter value #" << i + 1 << ": ";
        if(!(cin >> temp)){
            cin.clear();
            while(cin.get() != '\n');
            cout << "Bad input; input process terminated." << endl;
            break;
        }else if(temp < 0){
            break;
        }
        ar[i] = temp;
    }
    return i;
}

void show_array(const double ar[] , int n){
    for(int i = 0  ; i < n ; i ++){
        cout << "Property #" << i + 1 << ": $" << ar[i] << endl;
    }
}

void revalue(double r , double ar[] , int n ){
    for(int i = 0 ; i < n ; i++){
        ar[i] *= r;
    }
}

const int Max = 5;

int main(int argc, char const *argv[])
{
    double properties[Max];
    int size = fill_array(properties , Max);
    show_array(properties , size);
    if(size > 0){
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor))
        {
            cin.clear();
            while(cin.get() != '\n') continue;
            cout << "Bad input; Please enter a number: ";
        }
        revalue(factor , properties , size);
        show_array(properties , size);
    }
    cout << "Done!"<< endl;
    return 0;
}
