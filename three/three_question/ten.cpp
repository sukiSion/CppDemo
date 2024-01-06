#include<iostream>
#include<array>

int main(int argc, char const *argv[])
{
    using namespace std;
    array<float , 3> scores;
    for(int i = 0 ; i < scores.size() ; i ++){
        cout << "Enter you score: " ;
        cin >> scores[i];
    }
    float overallScore;
    for(int i = 0 ; i < scores.size() ; i ++){
        cout << "scrore : " << scores[i] << endl;
        overallScore += scores[i];
    }
    cout << "overall score: " << overallScore << endl;
    return 0;
}
