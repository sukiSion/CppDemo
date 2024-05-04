#include<iostream>
#include<string>
#include "queuetp.h"

int main(int argc, char const *argv[])
{
    using std::string;
    using std::cout;
    using std::endl;
    using std::cin;
    using std::getline;
    QueueTp<string> cs(5);
    string temp;
    while (!cs.isfull())
    {
        cout << "Please enter your name. You will be served in the order of arrival." << endl;
        cout << "name: ";
        getline(cin , temp);
        cs.enqueue(temp);
    }
    cout << "The queue is full. Processing begins!" << endl;
    while(!cs.isempty()){
        cs.dequeue(temp);
        cout << "Now Processing " << temp << "..." << endl;
    }
    return 0;
}
