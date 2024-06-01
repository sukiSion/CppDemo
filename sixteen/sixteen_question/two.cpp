#include<iostream>
#include<fstream>
#include <cstdlib>

int main(int argc, char const *argv[])
{
    using namespace std;
    char ch;
    if(argc != 2){
        cerr << "Your command arguments are invalid!" << endl;
        exit(EXIT_FAILURE);
    }
    ofstream fout(argv[1]);
    if(!fout.is_open()){
        cerr << "Can't open the file " << argv[1] << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Please enter some characters: ";
    while (cin.get(ch) && ch != EOF)
    {
        fout << ch;
    }
    cout << "Done.\n";
    fout.close();
    return 0;
}
