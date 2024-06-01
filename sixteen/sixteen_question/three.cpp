#include<iostream>
#include<fstream>

int main(int argc, char const *argv[])
{
    using namespace std;
    if(argc != 3){
        cerr << "Your command arguments are invalid!" << endl;
        exit(EXIT_FAILURE);
    }
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    if (!fin.is_open())
    {
        cerr << "Can't open the file " << argv[1] << endl;
        exit(EXIT_FAILURE);
    }
    if (!fout.is_open())
    {
        cerr << "Can't open the file " << argv[2] << endl;
        exit(EXIT_FAILURE);
    }
    char ch;
    while(fin.get(ch) && !fin.eof()){
        fout.put(ch);
    }
    cout << "Done.\n";
    fout.close();
    fin.close();
    return 0;
}
