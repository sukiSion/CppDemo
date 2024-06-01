#include<iostream>
#include<fstream>
#include<string>
const char * FIN1 = "four_in_1.txt";
const char * FIN2 = "four_in_2.txt";
const char * FOUT = "four_out.txt";

int main(int argc, char const *argv[])
{
    using namespace std;
    ifstream fin1(FIN1);
    ifstream fin2(FIN2);
    ofstream fout(FOUT);
    if (!fin1.is_open())
    {
        cout << "Can't open the file in1.txt\n";
        exit(EXIT_FAILURE);
    }
    if (!fin2.is_open())
    {
        cout << "Can't open the file in2.txt\n";
        exit(EXIT_FAILURE);
    }
    if (!fout.is_open())
    {
        cout << "Can't open the file out.txt\n";
        exit(EXIT_FAILURE);
    }
    string s;
    while(!fin1.eof() || !fin2.eof()){
        if(fin1.eof()){
            getline(fin2 , s);
            fout << s << endl;
        }else if(fin2.eof()){
            getline(fin1 , s);
            fout << s << endl;
        }else{
            getline(fin1 , s);
            fout << s << ' ';
            getline(fin2 , s);
            fout << s << endl;
        }
    }
    fin1.close();
    fin2.close();
    fout.close();
    cout << "Done" << endl;
    return 0;
}
