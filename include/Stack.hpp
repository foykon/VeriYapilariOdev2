#ifndef Stack_HPP
#define Stack_HPP

#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack();
    ~Stack();

    void push(int value);
    void pop();
    void peek();
    bool isEmpty();
};

#endif // STACK_HPP
