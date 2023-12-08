#include "stack.hpp"
#include <iostream>

Stack::Stack() : top(-1) {}

void Stack::push(int value) {
    if (top < MAX_SIZE - 1) {
        elements[++top] = value;
        std::cout << value << " yigita eklendi." << std::endl;
    } else {
        std::cout << "Yigit dolu, eleman eklenemedi." << std::endl;
    }
}

void Stack::pop() {
    if (top >= 0) {
        std::cout << elements[top--] << " yigittan cikarildi." << std::endl;
    } else {
        std::cout << "Yigit bos, eleman cikarilamadi." << std::endl;
    }
}

void Stack::peek() {
    if (top >= 0) {
        std::cout << "Yigitin ustundeki eleman: " << elements[top] << std::endl;
    } else {
        std::cout << "Yigit bos, eleman goruntulenemiyor." << std::endl;
    }
}

bool Stack::isEmpty() {
    return (top == -1);
}
