#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
    using namespace std;
    ifstream inFile;
    inFile.open("nine.txt");
    if (inFile.is_open())
    {
        int count;
        char ch;
        while (inFile.get(ch))
        {
            count++;
        }
        cout << "count: " << count << endl;
        if (inFile.eof())
        {
            cout << "Done!" << endl;
        }
    }
    inFile.close();
    return 0;
}
