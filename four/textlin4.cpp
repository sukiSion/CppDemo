#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    int count = 0;
    int ch;
    while ((ch = cin.get()) != EOF) 
    {
        cout.put(static_cast<char>(ch));
        count++;
    }
    cout << endl << count << " characters read" << endl;
    return 0;
}
