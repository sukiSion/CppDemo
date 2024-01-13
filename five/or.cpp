#include<iostream>


int main(int argc, char const *argv[])
{
    using namespace std;
    cout << "This program my reformat your hard disk" << endl;
    cout << "and destory all your dara." << endl;
    cout << "Do you wish to continue? <y/n> ";
    char ch;
    cin >> ch;
    if(ch == 'y' || ch == 'Y'){
        cout << "You were warned!\a\a\n";
    }else if(ch == 'n' || ch == 'N'){
        cout << "A wise choice ... bye" << endl;
    }else{
        cout << "That wasn't a y or n! Apparently you  can't follow"<< endl;
        cout << "instructions, so I'll trash your disk anyway.\a\a\a\n";
    }
    return 0;
}
