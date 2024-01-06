#include<iostream>
#include<string>

int main(int argc, char const *argv[])
{
    using namespace std;
    cout << "Enter a word: ";
    string word;
    cin >> word;
    for(int j = 0 , i = word.size() - 1 ; j < i; j++ , i--){
        char temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
    cout << word << endl << "Done!" << endl;
    return 0;
}
