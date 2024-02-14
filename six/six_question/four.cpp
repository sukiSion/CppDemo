#include <iostream>
long double probability(unsigned fieldNumber, unsigned fieldPicks , unsigned featuredNumber , unsigned featuredPicks);
long double probability(unsigned fieldNumber, unsigned fieldPicks , unsigned featuredNumber , unsigned featuredPicks)
{
    long double fieldReulst = 1.0;
    long double featuredResult = 1.0;
    long double n;
    unsigned p;
    for (n = fieldNumber, p = fieldPicks; p > 0; n--, p--)
    {
        fieldReulst *= n / p;
    }
    for (n = featuredNumber, p = featuredPicks; p > 0; n--, p--)
    {
        featuredResult *= n / p;
    }
    return fieldReulst * featuredResult;
}

int main(int argc, char const *argv[])
{

    using namespace std;
    double total, choices;
    cout << probability(47,  2 , 27 , 1 ) << endl; 
    cout << "bye\n";
    return 0;
}