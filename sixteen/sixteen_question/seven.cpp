#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;


void ShowStr(const string & s){
    cout << s << endl;
}

class Store{
    private:
    ofstream & os;
    public:
    Store(ofstream & fout): os(fout){}
    void operator()(const string &s){
        size_t len = s.size();
        os.write((char *) &len ,  sizeof(size_t));
        os.write(s.data() , len);
    }
};

void GetStrs(ifstream & is , vector<string> & v){
    size_t len;
    char *temp;
    while (is.read((char *) &len , sizeof(size_t))){
        temp = new char[len + 1];
        is.read(temp , len);
        temp[len] = '\0';
        v.push_back(temp);
        delete [] temp;
    }
}


int main()
{
    vector<string> vostr;
    string temp;

    cout << "Enter strings (empty line to quit):\n";
    while (getline(cin, temp) && temp[0] != '\0')
    {
        vostr.push_back(temp);
    }
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open())
    {
        cerr << "Coult not open file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}