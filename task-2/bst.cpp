#include <iostream>
#include "bst.hpp"

template<typename T>
Node<T>::Node(T key) : key(key), left(nullptr), right(nullptr) {}

template<typename T>
BST<T>::BST() : root(nullptr) {}

template<typename T>
Node<T>* BST<T>::insert(Node<T>* node, T key) {
    if (node == nullptr)
        return new Node<T>(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

template<typename T>
Node<T>* BST<T>::deleteNode(Node<T>* root, T key) {
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr) {
            Node<T>* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node<T>* temp = root->left;
            delete root;
            return temp;
        }

        Node<T>* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}


template<typename T>
Node<T>* BST<T>::minValueNode(Node<T>* node) {
    Node<T>* current = node;

    while (current && current->left != nullptr)
        current = current->left;

    return current;
}

template<typename T>
void BST<T>::inorderAF(Node<T>* root) const {
    if (root != nullptr) {
        inorder(root->left);
        std::cout << root->key << " ";
        inorder(root->right);
    }
}

template<typename T>
Node<T>* BST<T>::search(Node<T>* root, T key) const {
    if (root == nullptr || root->key == key)
        return root;

    if (root->key < key)
        return search(root->right, key);

    return search(root->left, key);
}

template<typename T>
BST<T>::~BST() {
    while(root != nullptr)
        deleteKey(root->key);
}

template<typename T>
void BST<T>::insert(T key) {
    root = insert(root, key);
}

template<typename T>
void BST<T>::deleteKey(T key) {
    root = deleteNode(root, key);
}

template<typename T>
void BST<T>::printTree() const {
    inorder(root);
    std::cout << "\n";
}

template<typename T>
Node<T>* BST<T>::search(T key) const {
    return search(root, key);
}
