#include<iostream>
using namespace std;
const int SIZE = 10;
void show_golfs(const double[] , int);
int fill_golfs(double[] , int);
void average_golfs(const double[] , int);

void show_golfs(const double golfs[] , int n){
    cout << "golfs: ";
    for(int i = 0 ; i < n ; i++){
        cout <<  golfs[i] << " " ;
    }
    cout << endl;
}

int fill_golfs(double golfs[] , int n){
    int length = 0;
    double temp;
    cout << "Enter value:(q to quit)" << endl;
    while(length < n && cin >> temp ){
        if(temp < 0){
            break;
        }
        golfs[length] = temp;
        length++;
    }
    return length;
}

void average_golfs(const double golfs[] , int n){
    cout << "average: ";
    double total;
    for(int i = 0 ; i < n ; i++){
        total += golfs[i];
    }
    cout << total / n << endl;
}

int main(int argc, char const *argv[])
{
    double golfs[SIZE];
    int length = fill_golfs(golfs , SIZE);
    if(length > 0){
        show_golfs(golfs , length);
        average_golfs(golfs , length);
    }else
    {
        cout << "No Data" << endl;

    }
    cout << "Done." << endl;
    return 0;
}


