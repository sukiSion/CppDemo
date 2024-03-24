#ifndef STACKTP_H_
#define STACKTP_H_

template <typename T>
class Stack{
    private:
    static const int MAX = 10;
    T items[MAX];
    int top;
    public:
    Stack(){
        top = 0;
    }
    bool isEmpty();
    bool isFull();
    bool push(const T & item);
    bool pop(T & item);
};

template <typename T>
bool Stack<T>::isEmpty(){
    return top == 0;
}

template <typename T>
bool Stack<T>::isFull(){
    return top == MAX;
}

template <typename T>
bool Stack<T>::push(const T & item){
    if(top < MAX){
        items[top++] = item;
        return true;
    }else{
        return false;
    }   
}

template <typename T>
bool Stack<T>::pop(T & item){
    if(top > 0){
        item = items[--top];
        return true;
    }else{
        return false;
    }
}

#endif