#include <iostream>
#include "avl-tree.hpp"

int main() {
    AVLTree tree;
    int keys[] = {9, 5, 10, 0, 6, 11, -1, 1, 2};
    for (int key : keys) {
        tree.insert(key);
    }

    std::cout << "Tree structure:\n";
    tree.preOrder();

    return 0;
}