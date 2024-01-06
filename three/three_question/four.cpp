#include<iostream>
#include<string>

int main(int argc, char const *argv[])
{
    using namespace std;
    const string interval = ", ";
    string first_name , last_name , name;
    cout << "Enter your first name: " ;
    getline(cin , first_name);
    cout << "Enter your last name: ";
    getline(cin , last_name);
    name = last_name + interval + first_name;
    cout << "Here's the information in a single string: " << name << endl;
    return 0;
}