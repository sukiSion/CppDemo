#include<iostream>
void simon(int);

void simon(int n){
    using namespace std;
    cout << "Simon says touch your toes " << n << " times." << endl;
}

int main(int argc, char const *argv[])
{
    using namespace std;
    simon(3);
    cout << "Pick an integet: " << endl;
    int count;
    cin >> count;
    simon(count);
    cout << "Done!" << endl;
    return 0;
}
