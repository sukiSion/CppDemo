#include<iostream>
#include "workermi.h"
#include<cstring>
static const int SIZE = 5;

int main(int argc, char const *argv[])
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;
    Worker * lolas[SIZE];
    int ct;
    for(ct = 0 ; ct < SIZE ; ct++){
        char choice;
        cout << "Enter the employee category: " << endl
        << "w: waiter s: singer t: singing waiter q: quit" << endl;
        cin >> choice;
        while(strchr("wstq" , choice) == nullptr){
            cout << "Please enter a w , s , t , or q: ";
            cin >> choice;
        }
        if(choice == 'q'){
            break;
        }
        switch (choice){
            case 'w':{
                lolas[ct] = new Waiter;
                break;
            }
            case 's':{
                lolas[ct] = new Singer;
                break;
            }
            case 't':{
                lolas[ct] = new SingingWaiter;
                break;
            }
        }
        cin.get();
        lolas[ct]->Set();
    }
    cout << endl << "Here is your staff:" << endl;
    int i;
    for(i = 0 ; i < ct ; i ++){
        cout << endl;
        lolas[i]->Show();
    }
    for(i = 0 ; i < ct ; i++){
        delete lolas[i];
    }
    cout << "Bye." << endl;
    return 0;
}
