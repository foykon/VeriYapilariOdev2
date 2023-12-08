#ifndef Stack_HPP
#define Stack_HPP

#include <iostream>

struct SNode {
    int data;
    SNode* next;

    SNode(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    SNode* top;

public:
    Stack();
    ~Stack();

    void push(int value);
    void pop();
    int peek();
    bool isEmpty();
};

#endif // STACK_HPP
