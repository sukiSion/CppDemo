#include<iostream>
const int Mins_per_hr = 60;
struct travel_time
{
    int hours;
    int mins;
};

void show_time(travel_time);
travel_time sum(travel_time , travel_time);

void show_time(travel_time t){
    using namespace std;
    cout << t.hours << " hours, " << t.mins << " minutes." << endl;
}

travel_time sum(travel_time t1 , travel_time t2){
    travel_time total;
    total.mins = (t1.mins + t2.mins) % Mins_per_hr;
    total.hours = (t1.hours + t2.hours) + ((t1.mins + t2.mins) / Mins_per_hr);
    return total;
}

int main(int argc, char const *argv[])
{
    using namespace std;
    travel_time day1  {5 , 45};
    travel_time day2 {4 , 55};
    travel_time trip = sum(day1 , day2);
    cout << "Two-day total: ";
    show_time(trip);

    travel_time day3 {4 , 32};
    cout << "Three-day total: ";
    show_time(sum(trip , day3));
    return 0;
}

