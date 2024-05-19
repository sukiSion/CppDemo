#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;
const int LIM = 6;
void Show(double v){
    cout.width(6);
    cout << v << " ";
}

int main(int argc, char const *argv[])
{
    double arr1[]{
        28 , 29 , 30 , 35 , 38 , 59
    };
    double arr2[]{
        63 , 65 , 69 , 75 , 80 , 99
    };
    vector<double> gr8(arr1 , arr1 + LIM);
    vector<double> m8(arr2 , arr2 + LIM);
    cout.setf(ios_base::fixed);
    cout.precision(1);
    cout << "gr8:" << endl;
    for_each(gr8.begin() , gr8.end() , Show);
    cout << endl;
    cout << "m8:" << endl;
    for_each(m8.begin() , m8.end() , Show);
    cout << endl;
    vector<double> sum;
    transform(gr8.begin() , gr8.end() , m8.begin() , back_insert_iterator<vector<double>>(sum) , plus<double>());
    cout << "sum:" << endl;
    for_each(sum.begin() , sum.end() , Show);
    cout << endl;
    vector<double> prod(LIM);
    transform(gr8.begin() , gr8.end() , prod.begin() , bind1st(multiplies<double>() , 2.5));
    cout << "prod:" << endl;
    for_each(prod.begin() , prod.end() , Show);
    cout << endl;
    return 0;
}
