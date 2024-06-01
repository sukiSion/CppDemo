#include "emp.h"
#include<cstdlib>
#include<algorithm>
const int MAX = 10;
const char * FILE_NAME = "employee.txt";
const char *emp_str[4] = {"Employee", "Manager", "Fink", "Highfink"};

using namespace std;


void eatline(istream & is){
    while(is.get() != '\n');
}

int main(int argc, char const *argv[])
{
    abstr_emp * pc[MAX];
    ifstream fin(FILE_NAME);
    int n = 0;
    if(fin.is_open()){
        cout << "Here are the current contents of the " << FILE_NAME <<  " file:" << endl;
        int type;
        while(fin >> type){
            eatline(fin);
            classkind kind = static_cast<classkind>(type);
            switch(kind){
                case Employee: {
                    pc[n] = new employee;
                    break;
                }
                case Manager: {
                    pc[n] = new manager;
                    break;
                }
                case Fink: {
                    pc[n] = new fink;
                    break;
                }
                case Highfink: {
                    pc[n] = new highfink;
                    break;
                }
            }
            cout << emp_str[type] << ": " << endl;
            pc[n]->getall(fin);
            pc[n++] -> ShowAll();
            cout << endl;
        }
        fin.close();
    }
    ofstream fout(FILE_NAME);
    if (!fout.is_open())
    {
        cerr << "Can't open the file" << FILE_NAME  << ".txt.\n";
        exit(EXIT_FAILURE);
    }
    cout << "Enter the employee category:\n";
    cout << "e: employee\n";
    cout << "m: manager\n";
    cout << "f: fink\n";
    cout << "h: highfink\n";
    cout << "q: quit\n";
    char ch;
    n = 0;
    while(cin.get(ch) && (ch = tolower(ch)) != 'q' && n < MAX){
        switch(ch){
            case 'e': {
                pc[n] = new employee;
                break;
            }
            case 'm': {
                pc[n] = new manager;
                break;
            }
            case 'f': {
                pc[n] = new fink;
                break;
            }
            case 'h': {
                pc[n] = new highfink;
                break;
            }
            default:
            {
                cout << "Try again: ";
                eatline(cin);
                continue;
            }
        }
        pc[n]->SetAll();
        pc[n++] -> writeall(fout);
        cout << "Enter the employee category:\n";
        cout << "e: employee\n";
        cout << "m: manager\n";
        cout << "f: fink\n";
        cout << "h: highfink\n";
        cout << "q: quit\n";
    }
    fout.close();

    fin.clear();
    fin.open(FILE_NAME);
    if(fin.is_open()){
        cout << "Here are the current contents of the " << FILE_NAME <<  " file:" << endl;
        int type;
        while(fin >> type){
            eatline(fin);
            classkind kind = static_cast<classkind>(type);
            switch(kind){
                case Employee: {
                    pc[n] = new employee;
                    break;
                }
                case Manager: {
                    pc[n] = new manager;
                    break;
                }
                case Fink: {
                    pc[n] = new fink;
                    break;
                }
                case Highfink: {
                    pc[n] = new highfink;
                    break;
                }
            }
            cout << emp_str[type] << ": " << endl;
            pc[n]->getall(fin);
            pc[n++] -> ShowAll();
            cout << endl;
        }
        fin.close();
    }
    cout << "Done.\n";
    return 0;
}
