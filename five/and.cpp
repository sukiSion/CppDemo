#include<iostream>
const int ArSize = 6;


int main(int argc, char const *argv[])
{
    using namespace std;

    float naaq[ArSize];
    cout << "Enter the NAAQs (New Age Awareness Quotients) of "
    << "your neighbors. Program terminates when you make 6 entries or enter a nagative value." 
    << endl;
    int i = 0;
    float temp;
    cout << "First value: ";
    cin >> temp;
    while (i <ArSize && temp >=0)
    {
        naaq[i] = temp;
        i++;
        if(i < ArSize){
            cout << "Next value: ";
            cin >> temp;
        }
    }
    if(i == 0){
        cout << "No data--byte" << endl;
    }else{
        cout << "Enter your NAAQ: ";
        float you;
        cin >> you;
        int count = 0;
        for(int j = 0 ; j < i ; j ++){
            if(naaq[j] > you){
                count++;
            }
        }
        cout << count << " of your neighbors have greater awareness of the New Age than you do." << endl; 
    }
    return 0;
}
