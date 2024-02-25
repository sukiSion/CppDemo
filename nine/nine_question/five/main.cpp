#include<iostream>
#include<cctype>
#include "stack.h"
using namespace std;


void setCustomer(customer & ct){
    cout << "Enter fullname: ";
    cin.get(ct.fullname , 35);
    ct.fullname[35] = '\0';
    while(cin.get() != '\n');
    cout << "Enter payment: ";
    if(cin >> ct.payment)cin.get();
}

void showCustomer(const customer & ct){
    cout << "fullname: " << ct.fullname << ", payment: " << ct.payment << endl;
}

int main(int argc, char const *argv[])
{
    Stack st; // create an empty stack
    char ch;
    customer ct;
    cout << "Please enter A to add a purchase order,\n"
        << "P to process a PO, or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q'){
        while (cin.get() != '\n');
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch(ch)
        {
             case 'A':
             case 'a': 
                       setCustomer(ct);
                       if (st.isFull())
                           cout << "stack already full\n";
                       else
                           st.push(ct);
                       break;
             case 'P':
             case 'p': if (st.isEmpty())
                           cout << "stack already empty\n";
                       else {
                           st.pop(ct);
                           showCustomer(ct);
                       }
                       break;
        }
        cout << "Please enter A to add a purchase order,\n"
             << "P to process a PO, or Q to quit.\n";
    }   
    cout << "Bye\n"; 
    return 0;
}
