#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>

using namespace std;
const char * file = "planets.dat";
const int LIM = 20;

inline void eatline(){
    while(cin.get() != '\n');
}

struct planet{
    char name[LIM];
    double population;
    double g;
};

int main(int argc, char const *argv[])
{
    planet pl;
    cout << fixed;
    fstream finout;
    finout.open(
        file,
        ios_base::in | ios_base::out | ios_base::binary
    );
    int ct = 0;
    if(finout.is_open()){
        finout.seekg(0);
        cout << "Here are the current contents of the " << file << " file: " << endl;
        while(finout.read((char *) &pl , sizeof pl)){
            cout << ct++ << ": " << setw(LIM) << pl.name << ": "
            << setprecision(0) << setw(12) << pl.population
            << setprecision(2) << setw(6) << pl.g << endl;
        }
        if(finout.eof()){
            finout.clear();
        }else{
            cerr << "Error in reading " << file << "." << endl;
            exit(EXIT_FAILURE);
        }
    }else{
        cerr << file << " could not be opened -- bye." << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Enter the record number you wish to change: ";
    long rec;
    cin >> rec;
    eatline();
    if(rec < 0 || rec >= ct){
        cerr << "Invalid record number -- bye." << endl;
        exit(EXIT_FAILURE);
    }
    streamoff place = rec * sizeof pl;
    finout.seekg(place);
    if(finout.fail()){
        cerr << "Error on attempted seek" << endl;
        exit(EXIT_FAILURE);
    }
    finout.read((char *)&pl , sizeof pl);
    cout << "Your selection: " << endl;
    cout << rec << ": " << setw(LIM) << pl.name << ": "
        << setprecision(0) << setw(12) << pl.population
        << setprecision(2) << setw(6) << pl.g << endl;
    if(finout.eof()){
        finout.clear();
    }
    cout << "Enter planet name: ";
    cin.get(pl.name , LIM);
    eatline();
    cout << "Enter planetary population: ";
    cin >> pl.population;
    cout << "Enter planet's acceleration of gravity: ";
    cin >> pl.g;
    finout.seekp(place , ios_base::beg);
    finout.write( (char *)&pl , sizeof pl );
    if(finout.fail()){
        cerr << "Error on attempted write" << endl;
        exit(EXIT_FAILURE);
    } 
    ct = 0;
    finout.seekg(0);
    cout << "Here are the current contents of the " << file << " file: " << endl;
    while(finout.read((char *) &pl , sizeof pl)){
        cout << ct++ << ": " << setw(LIM) << pl.name << ": "
        << setprecision(0) << setw(12) << pl.population
        << setprecision(2) << setw(6) << pl.g << endl;
    }
    finout.close();
    cout << "Done." << endl;
    return 0;
}
