#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include "vect.h"

int main(int argc, char const *argv[])
{
    using namespace std;
    using VECTOR::Vector;
    ofstream outFile;
    outFile.open("randonwalk.txt");
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
        outFile << "Target Distance: " << target << ", Step Size: " << dstep << endl;\
        outFile << steps << ": " << result << endl; 
        while(result.magval() < target){
            direction = rand() % 360;
            step.reset(dstep , direction , Vector::Mode::POL);
            // result += step;
            result = result + step;
            steps++;
            outFile << steps << ": " << result << endl; 
        }
        cout << "After " << steps << " steps, the subject "
            "has the following location:\n"; 
        outFile << "After " << steps << " steps, the subject "
            "has the following location:\n"; 
        cout << result << endl;
        outFile << result << endl;
        result.polar_mode();
        cout << " or\n" << result << endl;
        outFile << " or\n" << result << endl;
        cout << "Average outward distance per step = "
            << result.magval()/steps << endl;
        outFile << "Average outward distance per step = "
            << result.magval()/steps << endl;
        
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    outFile.close();
    return 0;
}
