#include<iostream>
#include<string>
#include<cctype>
#include"stacktp.h"
using std::cout;
using std::cin;
using std::string;
int main(int argc, char const *argv[])
{
    Stack<string> st;
    char ch;
    string po;
    cout << "Please enter A to add purchase order , " << std::endl
    << "P to process a PO, or Q to quit." << std::endl;
    while(cin >> ch && toupper(ch) != 'Q'){
        while(cin.get() != '\n');
        if(!isalpha(ch)){
            cout << '\a';
            continue;
        }
        switch(ch){
            case 'A':
            case 'a':{
                cout << "Enter a PO number to add: ";
                cin >> po;
                if(st.isFull()){
                    cout << "stack already full." << std::endl;
                }else{
                    st.push(po);
                }
                break;
            }
            case 'P':
            case 'p':{
                if(st.isEmpty()){
                    cout << "stack already empty" << std::endl;
                }else{
                    st.pop(po);
                    cout << "PO #" << po << " popped" << std::endl;
                }
                break;
            }
        }
        cout << "Please enter A to add purchase order , " << std::endl
        << "P to process a PO, or Q to quit." << std::endl;
    }
    cout << "Bye." << std::endl;
    return 0;
}
