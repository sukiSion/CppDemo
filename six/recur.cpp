#include<iostream>
void countdown(int);

void countdown(int n){
    using namespace std;
    cout << "Counting down ... " << n << " (n at " << &n << ") " << endl;
    if(n > 0){
        countdown(n - 1);
    } 
    cout << n << ": Kaboom!" << " (n at " << &n << ") " << endl;
}

int main(int argc, char const *argv[])
{
    countdown(4);
    return 0;
}
