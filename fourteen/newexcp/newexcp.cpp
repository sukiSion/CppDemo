#include<iostream>
#include<new>
#include<cstdlib>
using namespace std;

struct Big{
    double stuff[20000];
};

int main(int argc, char const *argv[])
{
    Big * pb;
    try{
        cout << "Trying to get a big block of memory:" << endl;
        pb = new (nothrow) Big[1000000];
        cout << "Got past the new request:" << endl;

        if(pb == 0){
            cout << "Caught the exception!" << endl;
            exit(EXIT_FAILURE);
        }
    }catch(bad_alloc & ba){
        cout << "Caught the exception!" << endl;
        cout << ba.what() << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Memory successfully allocated" << endl;
    pb[0].stuff[0] = 4;
    cout << pb[0].stuff[0] << endl;
    delete [] pb;
    return 0;
}
