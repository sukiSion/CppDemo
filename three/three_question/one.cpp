#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    const int NAME_SIZE = 20;
    char first_name[NAME_SIZE] , last_name[NAME_SIZE];
    int age;
    char grade;
    cout << "What is your first name? ";
    cin.getline(first_name , NAME_SIZE);
    cout << "What is your last name? ";
    cin.getline(last_name , NAME_SIZE);
    cout << "What letter grade do you deserve? ";
    cin >> grade;
    cout << "What is your age? ";
    cin >> age;
    cout << "Name: " << last_name << ", " << first_name << endl;
    cout << "Grade: " << static_cast<char>(grade + 1) << endl;
    cout << "Age: " << age << endl;
    return 0;
}
