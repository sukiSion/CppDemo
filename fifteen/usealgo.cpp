#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#include<iterator>
#include<cctype>

using namespace std;

char toLower(char ch){
    return tolower(ch);
}
string & ToLower(string & st){
    transform(st.begin() , st.end() , st.begin() , toLower);
    return st;
}

void display(const string & s){
    cout << s << " ";
}

int main(int argc, char const *argv[])
{
    vector<string> words;
    cout << "Enter words(enter quit to quir): " << endl;
    string input;
    while(cin >> input && input != "quit"){
        words.push_back(input);
    }
    cout << "You entered the following words:" << endl;
    for_each(words.begin() , words.end() , display);
    cout << endl;

    set<string> wordset;
    transform(words.begin() , words.end() , insert_iterator<set<string>>(wordset , wordset.begin()) , ToLower);
    cout << endl << "Alphabetic list of words:" << endl;
    for_each(wordset.begin() , wordset.end() , display);
    cout << endl;

    cout << "Original words:" << endl;
    for_each(words.begin() , words.end() , display);
    cout << endl;

    map<string,int> wordmap;
    set<string>::iterator si;
    for(si = wordset.begin() ; si != wordset.end() ; si++){
        wordmap[*si] = count(words.begin() , words.end() , *si);
    }
    cout << "Word frequency: " << endl;
    for(si = wordset.begin() ; si != wordset.end() ; si++){
        cout << *si << ": " << wordmap[*si] << endl;
    }
    return 0;
}






