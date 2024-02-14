#include<iostream>
#include<cstring>
using namespace std;
struct stringy
{
    char * str;
    int ct;
};

void set(stringy & beany , const char testing[]);
void set(stringy & beany , const char testing[]){
    beany.ct = strlen(testing);
    // 不能直接使用char [], 因为函数调用结束会释放导致无法输出
    beany.str = new char[beany.ct + 1];
    strcpy(beany.str , testing);
}

void show(const stringy & beany , int n = 1);
void show(const stringy & beany , int n){
    for(int i = 0 ;  i < n ; i++){
        cout << beany.str << endl;
    }
}

void show(const char * ch , int n = 1);
void show(const char * ch , int n){
    for(int i = 0 ;  i < n ; i++){
        cout << ch << endl;
    }
}


int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
    show(testing);
	show(testing, 3);
    show("Done");
}
