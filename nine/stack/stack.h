#ifndef _STACK_H_
#define _STACK_H_

typedef unsigned long Item;

class Stack
{
private:
    enum {MAX = 10};    
    Item items[MAX];    
    int top;           
public:
    Stack(){
        top = 0;
    }
    bool isEmpty() const;
    bool isFull() const;
    bool push(const Item & item);   
    bool pop(Item & item);          
};
#endif