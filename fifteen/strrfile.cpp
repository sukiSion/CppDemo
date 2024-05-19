#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>

int main(int argc, char const *argv[])
{
    using namespace std;
    ifstream fin;
    fin.open("tobuy.txt");
    if(!fin.is_open()){
        cerr << "Can't open file. Bye.\n";
        exit(EXIT_FAILURE);
    }
    string item;
    int count = 0;
    while(getline(fin , item , ':')){
        ++count;
        cout << count << ": " + item << endl;
    }
    cout << "Done\n";
    fin.close();
    return 0;
}
