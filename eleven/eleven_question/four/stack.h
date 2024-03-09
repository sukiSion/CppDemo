#ifndef _STACK_H_
#define _STACK_H_
#include<iostream>
typedef unsigned long Item;
class Stack
{
private:
    enum {MAX = 10};    
    Item * pitems;    
    int top;
    int size;           
public:
    Stack(int n = MAX);
    Stack(const Stack & st);
    ~Stack();
    bool isEmpty() const;
    bool isFull() const;
    bool push(const Item & item);   
    bool pop(Item & item);          
    Stack & operator=(const Stack & st);
    friend std::ostream & operator<<(std::ostream& os, const Stack & st);
};

#endif