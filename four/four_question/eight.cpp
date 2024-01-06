#include<iostream>
#include<cstring>
const int WordSize = 80;

int main(int argc, char const *argv[])
{
    using namespace std;
    cout << "Enter word (to stop, type the word done): " << endl;
    int count;
    char word[WordSize];
    cin >> word ;
    while (strcmp(word , "done"))
    {
        count ++;
        cin >> word;
    }
    
    cout << "You entered a total of " << count << " words." << endl;
    return 0;
}
