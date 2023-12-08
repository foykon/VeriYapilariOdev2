#ifndef Stack_HPP
#define Stack_HPP

class Stack {
private:
    static const int MAX_SIZE = 100;
    int top;
    int elements[MAX_SIZE];

public:
    Stack();
    void push(int value);
    void pop();
    void peek();
    bool isEmpty();
};

#endif // STACK_HPP
