#include<iostream>
#include<cstring>

int main(int argc, char const *argv[])
{
    using namespace std;
    const int NAME_SIZE = 20;
    const char interval[] = ", ";

    char first_name[NAME_SIZE] , last_name[NAME_SIZE];
    cout << "Enter your first name: " ;
    cin.getline(first_name , NAME_SIZE);
    cout << "Enter your last name: ";
    cin.getline(last_name , NAME_SIZE);
    char name[strlen(first_name) + strlen(last_name) + strlen(interval) + 1];
    strcpy(name , last_name);
    strcat(name , interval);
    strcat(name , first_name);
    cout << "Here's the information in a single string: " << name << endl;
    return 0;
}
