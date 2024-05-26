#include<iostream>
#include<cstring>

int main(int argc, char const *argv[])
{
    using std::cout;
    using std::endl;
    const char * state1 = "Florida";
    const char * state2 = "Kansas";
    const char * state3 = "Euphoria";

    cout << "Increasing loop index: " << endl;
    int len = std::strlen(state2);
    int i;
    for(i = 1 ; i <= len ; i++){
        cout.write(state2 , i) << endl;
    }
    cout << "Decreasing loop index:" << endl;
    for(i = len ; i > 0 ; i--){
        cout.write(state2 , i) << endl;
    }
    cout << "Exceeding string length: "<< endl;
    cout.write(state2 , len + 5) << endl;
    return 0;
}
