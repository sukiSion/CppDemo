#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    const float TIME_UNIT = 60.f;
    int degrees , minutes , seconds;
    auto resultDegrees = 0.f; 
    cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
    cout << "First, enter the degrees: ";
    cin >> degrees;
    cout << "Next, enter the minutes of arc: ";
    cin >> minutes;
    cout << "Finally, enter the seconds of arc: ";
    cin >> seconds;
    resultDegrees = degrees +  (minutes / TIME_UNIT + seconds / (TIME_UNIT * TIME_UNIT));
    cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = " << resultDegrees << " degrees" << endl;
    return 0;
}
