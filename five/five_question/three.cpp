#include <iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    cout << "Please enter one of the following choices:" << endl;
    cout << "c) carnivore p) pianist" << endl;
    cout << "t) tree g) game" << endl;
    char ch;
    while (cin.get(ch) && !(ch == 'q' || ch == 'Q'))
    {
        switch (ch)
        {
        case 'c':
        {
            cout << "carnivore" << endl;
            break;
        }
        case 'p':
        {
            cout << "pianist" << endl;
            break;
        }
        case 't':
        {
            cout << "tree" << endl;
            break;
        }
        case 'g':
        {
            cout << "game" << endl;
            break;
        }
        default:
        {
            cout << "Please enter a c, p, t or g: ";
            break;
        }
        }
    };
    cout << "Done!" << endl;
    return 0;
}
