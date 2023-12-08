#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP
#include "Stack.hpp"

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
public:
    int siraNo;

    int sumOfRoot=0;

    Node* root;

    Stack* stack;

    AVLTree();

    ~AVLTree(); // Yıkıcı fonksiyon

    void destroyTree(Node* root);// yıkıcı yardım

    int height(Node* node);

    int max(int a, int b);

    Node* rotateRight(Node* y);

    Node* rotateLeft(Node* x);

    int getBalance(Node* node);

    Node* insert(Node* root, int key);

    void insert(int key);

    void postorderTraversal(Node* root);

    void display();

    void yapraklariBulPostorder(Node* node);
};

#endif // AVL_TREE_HPP
