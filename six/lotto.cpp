#include <iostream>
long double probability(unsigned numbers, unsigned picks);
long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;
    long double n;
    unsigned p;
    for (n = numbers, p = picks; p > 0; n--, p--)
    {
        result *= n / p;
    }
    return result;
}

int main(int argc, char const *argv[])
{

    using namespace std;
    double total, choices;
    cout << "Enter the total number of choices on the game card and\n"
            "the number of picks allowed:\n";
    while ((cin >> total >> choices) && choices <= total)
    {
        cout << "You have one chance in ";
        cout << probability(total, choices); // compute the odds
        cout << " of winning.\n";
        cout << "Next two numbers (q to quit): " << endl;
    }
    cout << "bye\n";
    return 0;
}
