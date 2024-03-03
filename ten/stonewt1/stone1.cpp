#include<iostream>
#include "stonewt1.h"

int main(int argc, char const *argv[])
{
    using std::cout;
    Stonewt poppins(9 , 2.8);
    double p_wt = static_cast<double>(poppins);
    cout << "Convert to double => " << "Poppins: " << p_wt << " pounds.\n";
    cout << "Convert to int => " << "Poppins: " << static_cast<int>(poppins) << " pounds.\n";
    return 0;
}
