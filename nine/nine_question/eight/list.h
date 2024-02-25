#ifndef _LIST_H_
#define _LIST_H_

typedef unsigned long Item;

class List{
    private:
    static const int MAX = 10;
    Item items[MAX];
    int top;
    public:
    List(){
        top = 0;
    }
    bool isEmpty() const;
    bool isFull() const;
    void visit(void (*pf)(Item &));
    bool push(const Item & item);
};


#endif
