#include<iostream>
#include<string>
using namespace std;

struct Donor
{
    string fullname;
    double payment;
};

void printGrandPatrons(int , Donor[]);
void printPatrons(int , Donor[]);

void printGrandPatrons(int num , Donor donors[]){
    cout << "Grand Patrons" << endl;
    int count= 0;
    for(int i = 0 ; i < num ; i ++){
        if(donors[i].payment >= 10000){
            cout << "fullname: " << donors[i].fullname << endl;
            cout << "payment: " << donors[i].payment << endl;
            count++;
        }
    } 
    if(count == 0){
            cout << "none" << endl;
    }   
}


void printPatrons(int num , Donor donors[]){
    cout << "Patrons" << endl;
    int count= 0;
    for(int i = 0 ; i < num ; i ++){
        if(donors[i].payment < 10000 && donors[i].payment >= 0){
            cout << "fullname: " << donors[i].fullname << endl;
            cout << "payment: " << donors[i].payment << endl;
            count++;
        }
    } 
    if(count == 0){
            cout << "none" << endl;
    }
}


int main(int argc, char const *argv[])
{
    int num;
    cout << "Enter donor num: ";
    (cin >> num).get();
    Donor * donors = new Donor[num];
    for(int i = 0; i < num ; i++){
        cout << "Enter fullname: ";
        getline(cin , donors[i].fullname);
        cout << "Enter payment: ";
        (cin >> donors[i].payment).get();
    }
    printGrandPatrons(num , donors);
    printPatrons(num , donors);
    cout << "Done!";
    delete [] donors;
    return 0;
}
