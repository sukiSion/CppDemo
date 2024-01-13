#include<iostream>
#include<cctype>

int main(int argc, char const *argv[])
{
    using namespace std;
    cout << "Enter text for analysis , and type @ to terminate input." << endl;
    char ch;
    int whitespace = 0;
    int digites = 0;
    int chars = 0;
    int punct = 0;
    int others = 0;
    cin.get(ch);
    while (ch != '@')
    {
        if(isalpha(ch)){
            chars++;
        }else if (isspace(ch))
        {
            whitespace++;
        }else if (isdigit(ch))
        {
            digites++;
        }else if (ispunct(ch))
        {
            punct++;
        }else{
            others++;
        }
        cin.get(ch);
    }
    cout << chars << " letters, " << whitespace << " whitespace, " << digites << " digits, " << punct << " punctuations, " << others <<" others." << endl; 
    
    return 0;
}
