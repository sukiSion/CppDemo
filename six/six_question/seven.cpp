#include<iostream>
using namespace std;
double * fill_array(double * , double *);
void show_array(const double * , const double *);
void revalue(double , double * , double *);

double * fill_array(double * start , double * end){
    double temp;
    double * pd = start;
    int i = 0;
    for(pd ; pd <= end ; pd++ , i++){
        cout << "Enter value #" << i + 1 << ": ";
        if(!(cin >> temp)){
            cin.clear();
            while(cin.get() != '\n');
            cout << "Bad input; input process terminated." << endl;
            break;
        }else if(temp < 0){
            break;
        }
        *pd = temp;
    }
    return pd - 1;
}

void show_array( double * start,  const double * end){
    int i = 0;
    for(double * pd = start ; pd <= end ;  pd++ , i ++){
        cout << "Property #" << i + 1 << ": $" << *pd << endl;
    }
}

void revalue(double r , double * start, double * end){
    int i = 0 ;
    for(double * pd = start ; pd <= end ; i++ , pd++ ){
        *pd *= r;
    }
}

const int Max = 5;

int main(int argc, char const *argv[])
{
    double properties[Max];
    double * end = fill_array(properties , properties + Max - 1);
    show_array(properties , end);
    if(end != properties){
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor))
        {
            cin.clear();
            while(cin.get() != '\n') continue;
            cout << "Bad input; Please enter a number: ";
        }
        revalue(factor , properties , end);
        show_array(properties , end);
    }
    cout << "Done!"<< endl;
    return 0;
}
