#include<iostream>
const double * f1(const double ar[] , int n);
const double * f2(const double [] , int);
const double * f3(const double * , int);
const double * f1(const double * ar , int n){
    return ar;
}
const double * f2(const double ar[] , int n){
    return ar + 1;
}
const double * f3(const double ar[] , int n){
    return ar + 2;
}

int main(int argc, char const *argv[])
{
    using namespace std;
    double av[3]{1112.3 , 1542.6 , 2227.9};
    const double * (*p1)(const double ar[] , int n) = f1;
    auto p2 = f2;
    cout << "Using pointers to functions:" << endl;
    cout << " Address  Value" << endl;
    cout << (*p1)(av , 3) << ": " << *(*p1)(av , 3) << endl;
    cout << p2(av , 3) << ": " << *(p2)(av , 3) << endl;

    const double * (*pa[3])(const double ar[] , int n){f1 , f2 , f3};
    auto pb = pa;
    cout << endl << "Using an array of pointers to functions:" << endl;
    cout << " Address  Value" << endl;
    for(int i = 0 ; i < 3 ; i++){
        cout << pa[i](av , 3) << ": " << *pa[i](av , 3) << endl;
    }
    cout << endl << "Using a pointer to a pointer to a function:" << endl;
    cout << " Address  Value" << endl;
    for(int i = 0 ; i < 3 ; i++){
        cout << (*pb[i])(av , 3) << ": " << *(*pb[i])(av , 3) << endl;
    }
    
    cout << endl << "Using pointers to an array of pointers:" << endl;
    cout << " Address  Value" << endl;
    auto pc = &pa;
    cout << (*pc)[0](av , 3) << *(*pc)[0](av , 3) << endl;
    const double * (*(*pd)[3]) (const double ar[] , int n) = &pa;
    const double * pdb = (*pd)[1](av , 3);
    cout << pdb << ": " << *pdb << endl;
    cout << (*(*pd)[2])(av , 3) << ":7 " << *((*(*pd)[2])(av , 3)) << endl; 
    return 0;
}
