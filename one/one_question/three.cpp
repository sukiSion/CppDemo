#include<iostream>
using namespace std;

void mice(void);
void run(void);

void mice(void){
    cout << "Three blind mice" << endl;
}

void run(void){
    cout << "See how they run" << endl;
}

int main(int argc, char const *argv[])
{
    mice();
    mice();
    run();
    run();
    return 0;
}
