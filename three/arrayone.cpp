#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    int yams[3];
    yams[0] = 7;
    yams[1] = 8;
    yams[2] = 6;

    int yamcosts[3] = {20 , 30 , 5};
    cout << "Total yams = " <<  yams[0] + yams[1] + yams[2] << endl;
    cout << "The package with " << yams[1] << " yams costs " << yamcosts[1] << " cents per yam.\n";
    int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1] + yams[2] * yamcosts[2];
    cout << "The total yam expense is " << total << " cents.\n";
    cout << "\nSize of yams array = " <<  (yams) << " bytes." << endl;
    cout << "Size of one element = " << sizeof(yams[0]) << " bytes." << endl;
    return 0;
}
