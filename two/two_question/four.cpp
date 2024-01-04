#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    const int MINUTE_UNIT = 60;
    const int HOUR_UNIT = 60 * MINUTE_UNIT;
    const int DAY_UNIT = 24 * HOUR_UNIT;
    long long seconds;
    cout << "Enter the number of seconds: ";
    cin >> seconds;
    int days = seconds / DAY_UNIT;
    int hours = (seconds % DAY_UNIT) / HOUR_UNIT;
    int minutes = (seconds % HOUR_UNIT) / MINUTE_UNIT;
    int sseconds = seconds % MINUTE_UNIT;
    cout << seconds << " seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes, " << sseconds << " seconds." << endl;
    return 0;
}
