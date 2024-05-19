#include<iostream>
#include<string>
#include<vector>
const int NUM = 5;

int main(int argc, char const *argv[])
{
    using namespace std;
    vector<int> ratings(NUM);
    vector<string> titles(NUM);
    cout << "You will do exactly as told. You will enter" << endl;
    cout << NUM << " book titles and your ratings (0-10)." << endl;
    int i;
    for(i = 0 ; i < NUM ; i++){
        cout << "Enter title #" << i + 1 << ": ";
        getline(cin , titles[i]);
        cout << "Enter your rating(0-10): ";
        (cin >> ratings[i]).get();
    }
    cout << "Thank you. You entered the following:" << endl;
    cout << "Rating\tBook" << endl;
    for(i = 0 ; i < NUM ; i++){
        cout << ratings[i] << "\t" << titles[i] << endl;
    }
    return 0;
}
