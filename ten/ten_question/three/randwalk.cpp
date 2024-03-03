// randwalk.cpp -- using the Vector class
// compile with the vect.cpp file
#include <iostream>
#include <cstdlib> // rand(), srand() prototypes
#include <ctime>   // time() prototype
#include "vect.h"
int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0)); // seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    double target;
    double dstep;
    unsigned long steps = 0;
    cout << "Enter test count: ";
    int count;
    int n = 0;
    if (cin >> count && count > 0)
    {
        unsigned long * stepsArray = new unsigned long[count];
        cout << "Enter target distance (q to quit): ";
        while (n < count && cin >> target)
        {
            cout << "Enter step length: ";
            if (!(cin >> dstep))
                break;
            while (result.magval() < target)
            {
                direction = rand() % 360;
                step.reset(dstep, direction, Vector::Mode::POL);
                result = result + step;
                steps++;
            }
            stepsArray[n++] = steps;
            steps = 0;
            result.reset(0.0, 0.0);
            if(n < count) cout << "Enter target distance (q to quit): ";
            // cout << "After " << steps << " steps, the subject "
            //     "has the following location:\n";
            // cout << result << endl;
            // result.polar_mode();
            // cout << " or\n" << result << endl;
            // cout << "Average outward distance per step = "
            //     << result.magval()/steps << endl;
           
        }
        if(n > 0){
            int stepCount = 0;
            int maxStep = stepsArray[0];
            int minStep = stepsArray[0];
            for(int i = 0 ; i < n ; i++){
                maxStep = stepsArray[i] > maxStep ? stepsArray[i]: maxStep;
                minStep = stepsArray[i] < minStep ? stepsArray[i]: minStep;
                stepCount += stepsArray[i];
            }
            cout << "Max Steps: " << maxStep << endl;
            cout << "Min Steps: " << minStep << endl;
            cout << "Average Steps: " << stepCount / n << endl;
        }
        delete [] stepsArray;
    }
    cout << "Bye!\n";
    return 0;
}
