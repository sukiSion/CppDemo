#include<iostream>
using namespace std;
void simple(void);
void simple(void){
    cout << "I'm but a simple function." << endl;
    return;
}

int main(int argc, char const *argv[])
{
    cout << "main() will call the simple() function:" << endl;
    simple();
    cout << "main() is finished with the simple() function." << endl;
    return 0;
}
