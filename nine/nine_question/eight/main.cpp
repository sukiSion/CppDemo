#include<iostream>
#include "list.h"
using namespace std;
void show(Item & item){
    cout << item << endl;
}

int main(int argc, char const *argv[])
{
    List list;
    list.push(1);
    list.push(2);
    list.push(3);
    list.visit(show);
    
    return 0;
}
