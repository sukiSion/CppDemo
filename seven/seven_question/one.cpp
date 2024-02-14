#include <iostream>
using namespace std;
int beCalled = 0;
void printStr(const char *, int n = 0);
void printStr(const char *ch, int n)
{
    beCalled += 1;
    if (n != 0)
    {
        for (int index = 0; index < beCalled; index++)
        {
            cout << ch << endl;
        }
    }
    else
    {
        cout << ch << endl;
    }
}

int main(int argc, char const *argv[])
{
    char str[] = "Sion";
    printStr(str);
    printStr(str, 1);
    printStr(str, 1);
    cout << "end";
    return 0;
}
