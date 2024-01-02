#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    int carrots;
    cout << "How many carrots do you have?" << endl;
    // 将键入的数字输出到carrots
    cin >> carrots;
    cout << "Here are two more. ";
    carrots += 2;
    cout << "Now you have " << carrots << " carrots." << endl;
    return 0;
}
