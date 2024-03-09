#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <iostream>

#include "queue.h"
const int MIN_PER_HR = 60;
bool newcustomer(double x); // is there a new customer?
int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    cout << "Case Study: Bank of Heather Automatic Teller" << endl;
    cout << "Enter maxium size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);
    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;
    double perhour = 0;
    double min_per_cust;
    Item temp;
    double average_wait_time = 0;
    while (average_wait_time <= 1 )
    {
        while (!line.isempty())
        {
            line.dequeue(temp);
        }
        min_per_cust = MIN_PER_HR / perhour;
        long turnaways = 0;
        long customers = 0;
        long served = 0;
        long sum_line = 0;
        int wait_time = 0;
        long line_wait = 0;
        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust))
            {
                if (line.isfull())
                {
                    turnaways++;
                }
                else
                {
                    customers++;
                    temp.set(cycle);
                    line.enqueue(temp);
                }
            }
            if (wait_time <= 0 && !line.isempty())
            {
                line.dequeue(temp);
                wait_time = temp.ptime();
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time > 0)
            {
                wait_time--;
            }
            sum_line += line.quenecount();
        }
        if (customers > 0)
        {
            cout << "customers accepted: " << customers << endl;
            cout << "  customers served: " << served << endl;
            cout << "         turnaways: " << turnaways << endl;
            cout << "average queue size: ";
            cout.precision(2);
            cout.setf(ios_base::fixed, ios_base::floatfield);
            cout << (double)sum_line / cyclelimit << endl;
            average_wait_time = (double)line_wait / served;
            cout << " average wait time: "
                 << average_wait_time << " minutes\n";
        }
        else
        {
            cout << "No customers!" << endl;
            average_wait_time = 0;
        }
        if(average_wait_time <= 1) perhour++;
    }
    cout << "When there comes " << perhour
       << " people per hour, the average wait time will be about 1 minute.\n";
    cout << "Done!" << endl;
    return 0;
}

bool newcustomer(double x) { return (std::rand() * x / RAND_MAX < 1); }