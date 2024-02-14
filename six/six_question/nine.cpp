#include <iostream>
using namespace std;
const int SLEN = 30;
struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student[], int);
void display1(student);
void display2(const student *);
void display3(const student[], int);
int getinfo(student pa[], int n)
{
    int entered = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter student #" << entered + 1<< endl;
        cout << "Enter fullname: ";
        if (!cin.getline(pa[i].fullname, SLEN))
        {
            break;
        }
        else
        {
            if (pa[i].fullname[0] == '\0')
            {
                break;
            }
            // cin.get();
        }

        cout << "Enter hobby: ";
        if (!cin.getline(pa[i].hobby, SLEN))
        {
            break;
        }
        cout << "Enter ooplevel: ";
        if (!(cin >> pa[i].ooplevel))
        {
            break;
        }
        else
        {
            cin.get();
        }

        entered++;
    }
    return entered;
}

void display1(student st)
{
    cout << "fullname: " << st.fullname;
    cout << ", hobby: " << st.hobby;
    cout << ", ooplevel: " << st.ooplevel << endl;
}

void display2(const student *ps)
{
    cout << "fullname: " << ps->fullname;
    cout << ", hobby: " << ps->hobby;
    cout << ", ooplevel: " << ps->ooplevel << endl;
}

void display3(const student ps[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "fullname: " << ps[i].fullname;
        cout << ", hobby: " << ps[i].hobby;
        cout << ", ooplevel: " << ps[i].ooplevel << endl;
    }
}

int main(int argc, char const *argv[])
{
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n')
        ;
    student *ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]);
    }
    for (int i = 0; i < entered; i++)
    {
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete[] ptr_stu;
    cout << "Done." << endl;
    return 0;
}
