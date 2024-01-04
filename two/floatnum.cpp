#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    cout.setf(ios_base::fixed , ios_base::floatfield);
    float tub = 10.0 / 3.0;
    double mint = 10.0 / 3.0;
    const float million = 1.0e+6;
    cout << "tub = " << tub;
    cout << ", a million tubs = " << million * tub << ",\n";
    cout << "and ten million tubs = " << million * 10 * tub << endl;
    cout << "mint = " << mint << " and a million mints = " << million * mint << endl;
    return 0;
}
