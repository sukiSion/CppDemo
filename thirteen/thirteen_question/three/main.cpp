#include <iostream>
#include <cstring>
#include "worker.h"
#include "queuetp.h"
const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    int ct;
    Worker *temp;
    QueueTp<Worker *> lolas(SIZE);

    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the menu order:" << endl;
        cout << "a: add a worker to queue." << endl;
        cout << "d: delete a worker from queue." << endl;
        cout << "q: quit." << endl;
        cin >> choice;
        while (NULL == strchr("adq", choice))
        {
            while(cin.get() != '\n');
            cout << "Please enter a, d or q: ";
            cin >> choice;
        }
        if ('q' == choice)
        {
            break;
        }
        switch (choice)
        {
        case 'a':
        {
            if (lolas.isfull()) 
            {
                cout << "Queue is full!" << endl;
            }
            else
            {
                temp = new Worker;
                cin.get();
                temp->Set();
                lolas.enqueue(temp);
            }
            break;
        }
        case 'd':
        {
            if (lolas.isempty())
            {
                cout << "Queue is empty!" << endl;
            }
            else
            {
                lolas.dequeue(temp);
            }
            break;
        }
        }
    }
    ct = lolas.queuecount();
    cout << "\nHere is " << ct << " worker(s) in queue:" << endl;
    for (int i = 0; i < ct; i++)
    {
        lolas.dequeue(temp);
        temp->Show();
    }
    cout << "Done.\n";

    return 0;
}