#include<iostream>
#include<string>
#include<iterator>
#include<vector>
#include<algorithm>

using namespace std;

void out_put(const string & s){
    cout << s << " ";
}

int main(int argc, char const *argv[])
{
    string s1[]{
        "fine" , "finish" , "fashion" , "fate"
    };
    string s2[]{
        "busy" , "bats"
    };
    string s3[]{
        "silly" , "singers"
    };
    vector<string> words(4);
    
    copy(s1 , s1 + 4,  words.begin());
    for_each(words.begin() , words.end() , out_put);
    cout << endl;
    copy(s2 , s2 + 2 , back_insert_iterator<vector<string>>(words));
    for_each(words.begin() , words.end() , out_put);
    cout << endl;
    copy(s3 , s3 + 2 , insert_iterator<vector<string>>(words , words.begin()));
    for_each(words.begin() , words.end() , out_put);
    cout << endl;
    return 0;
}
