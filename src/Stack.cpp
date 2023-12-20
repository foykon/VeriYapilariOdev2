/**
* @file Stack.cpp
* @description avl ağacının yapraklarını saklmak için kullandığımız yığıt sınıfı
* @course Dersi 1. öğretin a grubu
* @assignment 2. ödev
* @date 8.12.2023
* @author Furkan YILDIZ furkan.yildiz12@ogr.sakarya.edu.tr
*/

#include "Stack.hpp"

Stack::Stack() : top(nullptr) {}

Stack::~Stack() {
    // Yığın boşaltılırken bellek sızıntısını önlemek için düğümleri sil
    while (!isEmpty()) {
        pop();
    }
}

void Stack::push(int value) {
    SNode* newNode = new SNode(value);
    newNode->next = top;
    top = newNode;
    //std::cout << value << " yigita eklendi." << std::endl;
}

void Stack::pop() {
    if (!isEmpty()) {
        SNode* temp = top;
        top = top->next;
        //std::cout << temp->data << " yigittan cikarildi." << std::endl;
        delete temp;
    } else {
      //  std::cout << "Yigit bos, eleman cikarilamadi." << std::endl;
    }
}

int Stack::peek() {
    if (!isEmpty()) {
        //std::cout << "Yigitin ustundeki eleman: " << top->data << std::endl;
        return top->data;
    } else {
    //    std::cout << "Yigit bos, eleman goruntulenemiyor." << std::endl;
        return 0;
    }
}

bool Stack::isEmpty() {
    return (top == nullptr);
}
