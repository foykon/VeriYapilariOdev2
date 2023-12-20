/**
* @file AVLTree.cpp
* @description avlağacının çalışma mantığına göre ve program için özel fonksiyonlar
* @course Dersi 1. öğretin a grubu
* @assignment 2. ödev
* @date 8.12.2023
* @author Furkan YILDIZ furkan.yildiz12@ogr.sakarya.edu.tr
*/

#include "AVLTree.hpp"
#include <iostream>
#include "Stack.hpp"

AVLTree::AVLTree() : root(nullptr) {
    Stack* s = new Stack();
    stack=s;
}

AVLTree::~AVLTree() {
    destroyTree(root);
}

void AVLTree::destroyTree(Node* root) {
    if (root != nullptr) {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}

int AVLTree::height(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int AVLTree::max(int a, int b) {
    return (a > b) ? a : b;
}

Node* AVLTree::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* AVLTree::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int AVLTree::getBalance(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

Node* AVLTree::insert(Node* root, int key) {
    
    if (root == nullptr)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root; // Duplicate keys are not allowed

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && key < root->left->key)
        return rotateRight(root);

    // Right Right Case
    if (balance < -1 && key > root->right->key)
        return rotateLeft(root);

    // Left Right Case
    if (balance > 1 && key > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Left Case
    if (balance < -1 && key < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void AVLTree::insert(int key) {
    root = insert(root, key);
    
}

void AVLTree::postorderTraversal(Node* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        //std::cout << root->key << " ";
    }
}

void AVLTree::display() {
    postorderTraversal(root);

}


void AVLTree::yapraklariBulPostorder(Node* node) {
    if (node == nullptr) {
        return;
    }

    yapraklariBulPostorder(node->left);
    yapraklariBulPostorder(node->right);

    if (node->left == nullptr && node->right == nullptr) {
        stack->push(node->key);
    }else{
        sumOfRoot += node->key;
    }
}