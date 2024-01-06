#include<iostream>
#include<string>

int main(int argc, char const *argv[])
{
    using namespace std;
    string first_name , last_name;
    int age;
    char grade;
    cout << "What is your first name? ";
    getline(cin , first_name);
    cout << "What is your last name? ";
    getline(cin , last_name);
    cout << "What letter grade do you deserve? ";
    cin >> grade;
    cout << "What is your age? ";
    cin >> age;
    cout << "Name: " << last_name << ", " << first_name << endl;
    cout << "Grade: " << static_cast<char>(grade + 1) << endl;
    cout << "Age: " << age << endl;
    return 0;
}