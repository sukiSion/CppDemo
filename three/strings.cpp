#include<iostream>
#include<cstring>

int main(int argc, char const *argv[])
{
    using namespace std;
    const int SIZE = 15;
    char name1[SIZE];
    char name2[SIZE] = "C++owboy";
    cout << "Howdy! I'm " << name2 << "! What's your name?" << endl;
    cin >> name1;
    cout << "Well, Basicman, your name has " << strlen(name1) << " letters and is stored." << endl;
    cout << "in a array of " << sizeof(name1) << " bytes." << endl;
    cout << "You initial is " << name1[0] << "." << endl;
    name2[3] = '\0';
    cout << "Here are the first 3 characters of your name: ";
    cout << name2 << endl;
    return 0;
}
