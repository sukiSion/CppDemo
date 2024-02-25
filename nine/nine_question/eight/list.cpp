#include "list.h"

bool List::isEmpty() const{
    return top == 0;
}

bool List::isFull() const{
    return top == MAX;
}

bool List::push(const Item & item){
    if(top < MAX){
        items[top++] = item;
        return true;
    }else{
        return false;
    }
}

void List::visit(void (*pf)(Item &)){
    for(int i = 0 ; i < top ; i++){
        (*pf)(items[i]);
    }
}