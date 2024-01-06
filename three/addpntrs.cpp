#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    double wages[3]{10000.0 , 20000.0 , 30000.0};
    short stacks[3]{3 , 2 , 1};
    double * pw = wages;
    short * ps = &(stacks[0]);
    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    cout << "Add 1 to the pw pointer" << endl;
    pw += 1;
    cout << "pw = " << pw << ", *pw = " << *pw << endl << endl;
    cout << "ps = " << ps << ", *ps = " << *ps << endl;
    cout << "Add 1 to the ps pointer" << endl;
    ps += 1;
    cout << "ps = " << ps << ", *ps = " << *ps << endl << endl;

    cout << "access two elements with array notation" << endl;
    cout << "stacks[0] = " << stacks[0] << ", stacks[1] = " << stacks[1] << endl;
    cout << "access two elements with pointer notation" << endl;
    cout << "*stacks = " << *stacks << ", *(stacks + 1) = " << *(stacks + 1) << endl;
    cout << sizeof(wages) << " = size of wages array" << endl;
    cout << sizeof(pw) << " = size of pw pointer" << endl;
    return 0;
}
