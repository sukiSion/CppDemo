#include<iostream>
#include<string>

int main(int argc, char const *argv[])
{
    using namespace std;
    cout << "Enter a world: ";
    string word;
    getline(cin , word);
    for (int i = word.size() - 1 ; i >= 0 ; i--){
        cout << word[i];
    }

    cout  << endl << "Bye." << endl;
    return 0;
}
