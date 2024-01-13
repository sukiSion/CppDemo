#include<iostream>

int main(int argc, char const *argv[])
{
    const int Fave = 27;
    using namespace std;
    int n;
    cout << "Enter a number in the range 1-100 to find my favorite number: " ;
    do{
        cin >> n;
        if(n < Fave){
            cout << "Too low -- guess again: ";
        }else if (n > Fave)
        {
            cout << "Too high -- guess again: ";
        }else{
            cout << "Fave " << Fave << " is right!" << endl;
        }
    }while(n != 27);
    return 0;
}
