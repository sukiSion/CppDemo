#include<iostream>
#include<fstream>
#include<cstdlib>
int main(int argc, char const *argv[])
{
    const int SIZE = 60;
    using namespace std;
    char filename[SIZE];
    ifstream inFile;
    // cout << "Enter name of data file: ";
    // cin.getline(filename  , SIZE);
    // inFile.open(filename);
    inFile.open("scores.txt");
    if(!inFile.is_open()){
        exit(EXIT_FAILURE);
    }
    double value ;
    double sum = 0.0;
    int count = 0;
    // inFile >> value;
    while (inFile >> value)
    {j
        ++count;
        sum += value;

        // inFile >> value;
    }
    if(inFile.eof()){
        cout << "End of file reached." << endl;
    }else if(inFile.fail()){
        cout << "Input terminated by data mismatch." << endl;
    }else{
        cout << "Input terminated for unknown reason." << endl;
    }
    if(count == 0){
        cout << "No data processed." << endl;
    }else{
        cout << "Item read: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum / count << endl;
    }
    inFile.close();
    

    return 0;
}
