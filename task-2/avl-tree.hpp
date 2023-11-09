#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int k);
};

class AVLTree {
public:
    /**
    * @brief Конструктор по умолчанию
    */
    AVLTree();

    /**
    * @brief Параметризированный конструктор
    */
    AVLTree(const int key);

    /**
    * @brief Конструктор копирования
    * @param other Другое дерево
    */
    AVLTree(const AVLTree& other);

    /**
    * @brief Вставка ключа в дерево AVL.
    * @param k Ключ для вставки.
    */
    void insert(int k);

    /**
    * @brief Удаление ключа из дерева AVL.
    * @param k Ключ для удаления.
    */
    void remove(int k);

    /**
    * @brief Прямой обход дерева.
    */
    void preOrder() const;

private:
    Node* root;
    
    /**
    * @brief Возвращает высоту узла.
    * @param node Узел, высоту которого нужно получить.
    * @return Высота узла или 0, если узел не существует.
    */
    int getHeight(const Node* node) const;

    /**
    * @brief Получение баланса узла.
    * @param node Узел, для которого необходимо определить баланс.
    * @return Баланс узла (разница высоты левого и правого поддеревьев).
    */
    int getBalance(const Node* node) const;

    /**
    * @brief Правое вращение вокруг узла y.
    * @param y Узел, вокруг которого производится вращение.
    * @return Новый корень поддерева после вращения.
    */
    Node* rightRotate(Node* y);

    /**
    * @brief Левое вращение вокруг узла x.
    * @param x Узел, вокруг которого производится вращение.
    * @return Новый корень поддерева после вращения.
    */
    Node* leftRotate(Node* x);

    /**
    * @brief Вставка ключа в дерево AVL (вспомогательная функция).
    * @param node Узел, в который производится вставка.
    * @param k Ключ для вставки.
    * @return Указатель на новый корень поддерева после вставки.
    */
    Node* insert(Node* node, int k);

    /**
    * @brief Удаление ключа из дерева AVL (вспомогательная функция).
    * @param root Корень поддерева, в котором производится удаление.
    * @param key Ключ для удаления.
    * @return Указатель на новый корень поддерева после удаления.
    */
    Node* remove(Node* root, int key);

    /**
    * @brief Поиск узла с минимальным ключом в поддереве.
    * @param node Корень корневого поддерева, в котором нужно найти узел с минимальным ключом.
    * @return Указатель на узел с минимальным ключом в поддереве.
    */
    Node* minValueNode(Node* node);

    /**
    * @brief Прямой обход (pre-order traversal) дерева (вспомогательная функция).
    * @param node Корень поддерева для обхода.
    */
    void preOrder(const Node* node) const;
};

#endif