#include<iostream>
#include<cstdlib>
#include<ctime>
#include "vect.h"

int main(int argc, char const *argv[])
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result;
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit):";
    while(cin >> target){
        cout << "Enter step length: ";
        if(!(cin >> dstep)){
            break;
        }

        while(double(result) < target){
            direction = rand() % 360;
            step.reset(dstep , direction , Vector::Mode::POL);

            // result += step;
            result = result + step;
            steps++;
        }
        cout << "After " << steps << " steps, the subject "
            "has the following location:\n";
        cout << result << endl;
        result.polar_mode();
        cout << " or\n" << result << endl;
        cout << "Average outward distance per step = "
            << result.magval()/steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    return 0;
}
