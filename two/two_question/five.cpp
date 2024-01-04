#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    long long current_pop, US_pop;
    double percent;
    // cout.setf(ios_base::fixed , ios_base::floatfield);
    cout << "Enter the world's population: ";
    cin >> current_pop;
    cout << "Enter the population of the US: ";
    cin >> US_pop;
    percent = double(US_pop) / double(current_pop) * 100;
    cout << "The population of the US is " << percent << "% of the world population." << endl;
    return 0;
}
