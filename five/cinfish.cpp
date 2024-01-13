#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    const int Max = 5;
    double fish[Max];
    cout << "Please enter the weight of your fish." << endl;
    cout << "fish #1: ";
    int i = 0;
    while(i < Max && cin>> fish[i]){
        if(++i < Max){
            cout << "fish #" << i + 1 << ": ";
        }
    }
    double total = 0.0;
    for(int j = 0 ; j < i ;j ++){
        total += fish[j];
    }
    if(i == 0){
        cout << "No fish" << endl;
    }else{
        cout << total / i << " = average weight of " << i << " fish" << endl;
    }
    cout << "Done." << endl;
    return 0;
}
