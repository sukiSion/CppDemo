#include<iostream>
#include<string>

int main(int argc, char const *argv[])
{
    using namespace std;
    int count = 0;
    cout << "Enter word (to stop, type the word done): " << endl;
    string word;
    cin >> word;
    while(word != "done"){
        count ++;
        cin >> word;
    }
    cout << "You entered a total of " << count << " words." << endl;
    return 0;
}