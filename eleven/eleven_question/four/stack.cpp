#include "stack.h"

bool Stack::isEmpty() const{
    return top == 0;
}

bool Stack::isFull() const{
    return top == size;
}

bool Stack::push(const Item & item){
    if(top < size){
        pitems[top++] = item;
        return true;
    }else return false;
}

bool Stack::pop(Item & item){
    if(top > 0){
        item = pitems[--top];
        return true;
    }else return false;
}

Stack::~Stack(){
    delete [] pitems;
}

Stack::Stack(int n ){
    pitems = new Item[n];
    size = n;
    top = 0;
}

Stack::Stack(const Stack & st){
    size = st.size;
    top = st.top;
    pitems = new Item[size];
    for(int i = 0 ; i < st.size ; i++){
        pitems[i] = st.pitems[i];
    }
}

Stack & Stack::operator=(const Stack & st){
    if(this == &st){
        return *this;
    }
    delete[] pitems;
    size = st.size;
    top = st.top;
    pitems = new Item[size];
    for(int i = 0 ; i < st.size ; i++){
        pitems[i] = st.pitems[i];
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Stack & st) {
  for (int i = 0; i < st.top; i++) {
    os << st.pitems[i] << std::endl;
  }
  return os;
}