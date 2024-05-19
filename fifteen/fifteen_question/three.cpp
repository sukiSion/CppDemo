#include<iostream>
#include<fstream>
#include<string>
#include<cctype>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream fin;
    fin.open("wordlist.txt");
    if(!fin.is_open()){
        cerr << "Can't open file.Bye." << endl;
        exit(EXIT_FAILURE);
    }
    vector<string> wordlist;
    string word;
    while(fin >> word){
        wordlist.push_back(word);
    }
    fin.close();
    srand(time(0));
    char play;
    cout << "Will you play a word game? <y/n> ";
    cin >> play;
     while(tolower(play) == 'y'){
        string target = wordlist[rand() % wordlist.size()];
        int length = target.length();
        string attempt(length , '-');
        string badchars;
        int guesses = 6;
        cout << "Guess my secret word. It has " << length << " letters, and you guess" << endl;
        cout << "one latter at a time. You get " << guesses << " wrong gueeses." << endl;
        while(guesses > 0 && attempt != target){
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;
            if(badchars.find(letter) != string::npos
            || attempt.find(letter) != string::npos){
                cout << "You already guessed that. Try again.\n";
                continue;
            }
            int loc = target.find(letter);
            if(loc == string::npos){
                cout << "Oh, bad guess!\n";
                --guesses;
                badchars += letter;
            }else{
                cout << "Good guess!" << endl;
                attempt[loc] = letter;
                loc = target.find(letter , loc + 1);
                while(loc != string::npos){
                    attempt[loc] = letter;
                    loc = target.find(letter , loc + 1);
                }
            }
            cout << "Your word: " << attempt << endl;
            if(attempt != target){
                if(badchars.length() > 0){
                    cout << "Bad choices: " << badchars << endl;
                }
                cout << guesses << " bad guesses left" << endl;
            }
        }
        if(guesses > 0){
            cout << "That's right!" << endl;
        }else{
            cout << "Sorry, the word is " << target << "." << endl;
        }
        cout << "Will you play another? <y/n> ";
        cin >> play;
    }
    return 0;
}
