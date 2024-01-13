#include <iostream>
#include <array>

int main(int argc, char const *argv[])
{
    const int SIZE = 10;
    using namespace std;
    array<double, SIZE> donations;
    int count = 0;
    double sum = 0.0;
    double average = 0.0;
    cout << "Please Enter:" << endl;
    cout << "donations #1: ";
    while (count < SIZE && cin >> donations[count])
    {
        sum += donations[count];
        count++;
        if (count < SIZE)
        {
            cout << "donations #" << count + 1 << ": ";
        }
    }
    if (count == 0)
    {
        cout << "No Data!" << endl;
    }
    else
    {
        average = sum / count;
        int bigger = 0;
        for (int i = 0; i < count; i++)
        {
            if (donations[i] > average){
                bigger ++;
            }
        }
        cout << "average = " << average << endl;
        cout << "bigger than average = " << bigger << endl;
    }
    cout << "Done!" << endl;
    return 0;
}
