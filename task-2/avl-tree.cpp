#include "avl-tree.hpp"
#include <iostream>

Node::Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::AVLTree(const int key) {}

AVLTree::AVLTree(const AVLTree& other) {}

int AVLTree::getHeight(const Node* node) const {
    if (node == nullptr)
        return 0;
    return node->height;
}

int AVLTree::getBalance(const Node* node) const {
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* AVLTree::rightRotate(Node* y) {
    Node* x = y->left;
    Node* const T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* AVLTree::leftRotate(Node* x) {
    Node* y = x->right;
    Node* const T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* AVLTree::insert(Node* node, int k) {
    if (node == nullptr)
        return new Node(k);

    if (k < node->key)
        node->left = insert(node->left, k);
    else if (k > node->key)
        node->right = insert(node->right, k);
    else
        return node;

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1) {
        if (k < node->left->key)
            return rightRotate(node);
        else {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }

    if (balance < -1) {
        if (k > node->right->key)
            return leftRotate(node);
        else {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

Node* AVLTree::remove(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = remove(root->left, key);
    else if (key > root->key)
        root->right = remove(root->right, key);
    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;

            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = remove(root->right, temp->key);
        }

        if (root == nullptr)
            return root;

        root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));

        int balance = getBalance(root);

        if (balance > 1) {
            if (getBalance(root->left) >= 0)
                return rightRotate(root);
            else {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }

        if (balance < -1) {
            if (getBalance(root->right) <= 0)
                return leftRotate(root);
            else {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }
    }
    return root;
}

Node* AVLTree::minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

void AVLTree::preOrder(const Node* node) const {
    if (node != nullptr) {
        preOrder(node->left);
        std::cout << node->key << " ";
        preOrder(node->right);
    }
}