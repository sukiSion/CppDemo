#include<iostream>
const int strsize = 20;
struct bop
{
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    int preference;
};


int main(int argc, char const *argv[])
{
    using namespace std;
    cout << "Benevolent Order of Progranmers Report" << endl;
    cout << "a. display by name\a" << "b. display by title" << endl;
    cout << "c .display by bopname\a" << "d. display by preference" << endl;
    cout << "quit"<< endl;
    char ch;
    cout << "Enter your choice: ";
    bop bops[]{
        {"Wimp Macho" , "" , "" , 0},
        {"Raki Rhodes" , "Junior Programmer" , "" , 1},
        {"Celia Laiter" , "" , "MIPS" , 2},
        {"Hoppy Hipman" , "Analyst Trainee" , "" , 1},
        {"Pat Hand" , "" , "LOOPY" , 2},

    };
    while (cin.get(ch) && ch != 'q')
    {
       switch(ch){
        case 'a':{
            for(bop b: bops){
                cout << b.fullname << endl;
            }
            break;
        }
        case 'b':{

            break;
        }
        case 'c':{

            break;
        }
        case 'd':{
             for(bop b: bops){
                if(b.preference == 0){
                    cout << b.fullname << endl;
                }else if(b.preference == 1){
                    cout << b.title << endl;
                }else{
                    cout << b.bopname << endl;
                }
            }
            break;
        }
       } 
       while(cin.get() != '\n');
       cout << "Next choice: ";
    }
    cout << "Bye!" << endl;
    return 0;
}
