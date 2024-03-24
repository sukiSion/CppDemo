#include "studenti.h"
using std::cin;
using std::cout;
using std::endl;
using std::getline;
const int pupils = 3;
const int quizzes = 5;
void set(Student & sa , int n){
    cout << "Please enter the student's name: ";
    getline(cin , sa);
    cout << "Please enter " << n << " quiz scores: " << endl;
    for(int i = 0 ; i < n ; i ++){
        cin >> sa[i];
    }
    while(cin.get() != '\n');
}

int main(int argc, char const *argv[])
{
    Student ada[pupils] = {
        Student(quizzes),
        Student(quizzes),
        Student(quizzes)
    };
    int i;
    for(int i = 0 ; i < pupils ; i++){
        set(ada[i] , quizzes);
    }
    cout << endl;
    cout << "Student List: " << endl;
    for(int i = 0 ; i < pupils ; i++){
        cout << ada[i].Name() << endl;
    }
    cout << endl;
    cout << "Results:" ;
    for(int i = 0 ; i < pupils ; i++){
        cout << endl << ada[i];
        cout << "average: " << ada[i].Average() << endl;
    }
    cout << "Done." << endl;
    return 0;
}
