#include "worker.h"
#include<iostream>
using std::cout;
using std::endl;
using std::getline;
using std::cin;

void Worker::Set()
{
    cout << "Enter worker's name: ";
    getline(cin, fullname);
    cout << "Enter worker's ID: ";
    cin >> id;
    while (cin.get() != '\n')
        continue;
}

void Worker::Show() const
{
    cout << "Worker name: " << fullname << endl;
    cout << "Worker ID: " << id << endl;
}