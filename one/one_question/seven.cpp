#include<iostream>
using namespace std;

void printFormatTime(int hours , int minutes);

void printFormatTime(int hours , int minutes){
    cout << "Time: " << hours << ":" << minutes << endl;
}

int main(int argc, char const *argv[])
{
    int hours , minutes;
    cout << "Enter the number of hours: ";
    // 输入后自动换行
    cin >> hours;
    cout << "Enter the number of minutes: ";
    cin >> minutes;
    printFormatTime(hours , minutes);
    return 0;
}

