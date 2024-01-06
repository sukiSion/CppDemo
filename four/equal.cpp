#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    int i;
    int quizscores[10]{20 , 20 , 20 , 20 , 20 , 19 , 20 , 18 , 20 , 20};
    for(i = 0 ; quizscores[i] == 20 ; i++){
        cout << "quiz " << i << " is a 20" << endl;
    }
    return 0;
}
