#include <iostream>
#include <cctype>
#include "stack.h"

int main(int argc, char const *argv[])
{
    using namespace std;
    Stack st;
    char ch;
    unsigned long po;
    cout << "Please enter A to add a purchase order,\n"
         << "P to process a PO, or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            ;
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch (ch)
        {
        case 'A':
        case 'a':
        {
            cout << "Enter a PO number to add: ";
            cin >> po;
            if (st.isFull())
            {
                cout << "stack already full." << endl;
            }
            else
            {
                st.push(po);
            }
            break;
        }
        case 'p':
        case 'P':
        {
            if (st.isEmpty())
            {
                cout << "stack already empty." << endl;
            }
            else
            {
                st.pop(po);
                cout << "PO #" << po << " popped." << endl;
            }
            break;
        }
        }
        cout << "Please enter A to add a purchase order,\n"
         << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye." << endl;
    return 0;
}
