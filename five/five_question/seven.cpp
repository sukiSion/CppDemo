#include <iostream>
#include <cctype>

int main(int argc, char const *argv[])
{
    using namespace std;
    char ch;
    cout << "Enter word(q to quit)" << endl;
    int vowels = 0;
    int consonants = 0;
    int others = 0;
    bool isNewWord = true;
    bool isReadyExit = false;
    while (cin.get(ch))
    {
        if (isspace(ch))
        {
            if (isReadyExit)
            {
                consonants--;
                break;
            }
            isNewWord = true;
            continue;
        }
        else
        {
            if (isReadyExit)
            {
                isReadyExit = false;
            }
        }
        if (isNewWord)
        {
            if (isalpha(ch))
            {
                if (ch == 'q')
                {
                    isReadyExit = true;
                    consonants++;
                }
                else
                {
                    char ch_copy = tolower(ch);
                    if (ch_copy == 'a' || ch_copy == 'e' || ch_copy == 'i' || ch_copy == 'o' || ch_copy == 'u')
                    {
                        vowels++;
                    }
                    else
                    {
                        consonants++;
                    }
                }
            }
            else if (isdigit(ch))
            {
                others++;
            }
            isNewWord = false;
        }
    }
    cout << vowels << " words begining with vowels" << endl;
    cout << consonants << " words beginning with consonants" << endl;
    cout << others << " words beginning with consonants" << endl;
    return 0;
}
