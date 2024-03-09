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
    Queue line1(qs);
    Queue line2(qs);
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
        while (!line1.isempty())
        {
            line1.dequeue(temp);
        }
        while (!line2.isempty())
        {
            line2.dequeue(temp);
        }
        
        min_per_cust = MIN_PER_HR / perhour;
        long turnaways = 0;
        long customers = 0;
        long served = 0;
        long sum_line = 0;
        long line_wait = 0;
        int wait_time1 = 0;
        int wait_time2 = 0;
        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust))
            {
                if (line1.isfull() && line2.isfull())
                {
                    turnaways++;
                }else if (line1.quenecount() < line2.quenecount())
                {
                    customers++;
                    temp.set(cycle);
                    line1.enqueue(temp);
                }else
                {
                    customers++;
                    temp.set(cycle);
                    line2.enqueue(temp);
                }
            }
            if (wait_time1 <= 0 && !line1.isempty())
            {
                line1.dequeue(temp);
                wait_time1 = temp.ptime();
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time2 <= 0 && !line2.isempty())
            {
                line2.dequeue(temp);
                wait_time2 = temp.ptime();
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time1 > 0)
            {
                wait_time1--;
            }
            if (wait_time2 > 0)
            {
                wait_time2--;
            }
            sum_line += (line1.quenecount() + line2.quenecount());
        }
        if (customers > 0)
        {
            cout << "customers accepted: " << customers << endl;
            cout << "  customers served: " << served << endl;
            cout << "         turnaways: " << turnaways << endl;
            cout << "average queue size: ";
            cout.precision(2);
            cout.setf(ios_base::fixed, ios_base::floatfield);
            cout << (double)sum_line / cyclelimit / 2 << endl;
            cout << " average wait time: "
                 << (double)line_wait / served << " minutes\n";
            average_wait_time = (double)line_wait / served;
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