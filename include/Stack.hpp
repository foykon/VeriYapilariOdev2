/**
* @file Stack.hpp
* @description avl ağacının yapraklarını saklmak için kullandığımız yığıt sınıfınin arayüzü
* @course Dersi 1. öğretin a grubu
* @assignment 2. ödev
* @date 8.12.2023
* @author Furkan YILDIZ furkan.yildiz12@ogr.sakarya.edu.tr
*/

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
    void bosalt();
    void pop();
    int peek();
    bool isEmpty();
};

#endif // STACK_HPP
