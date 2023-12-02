#ifndef BST_HPP
#define BST_HPP

template<typename T>
struct Node {
    T key;
    Node<T>* left;
    Node<T>* right;

    /**
     * @brief Конструктор узла.
     * @param key Ключ узла.
     */
    explicit Node(T key) : key(key), left(nullptr), right(nullptr) {}
};

template<typename T>
class BST {
private:
    Node<T>* root;

    /**
     * @brief Вставка ключа в узел дерева.
     * @param node Узел для добавления.
     * @param key Ключ для добавления.
     * @return Узел дерева.
     */
    Node<T>* insert(Node<T>* node, T key);

    /**
     * @brief Удаление ключа из узла дерева.
     * @param root Корневой узел.
     * @param key Ключ для удаления.
     * @return Узел дерева.
     */
    Node<T>* deleteNode(Node<T>* root, T key);

    /**
     * @brief Наименьший узел в дереве.
     * @param node Узел для поиска.
     * @return Узел с наименьшим ключом.
     */
    Node<T>* minValueNode(Node<T>* node);

    /**
     * @brief Печать узлов дерева в центрированном порядке.
     * @param root Корневой узел.
     */
    void inorderAF(Node<T>* root) const;

    /**
     * @brief Поиск ключа в дереве.
     * @param root Корневой узел.
     * @param key Ключ для поиска.
     * @return Узел с ключом, если он существует.
     */
    Node<T>* search(Node<T>* root, T key) const;
    
public:
    /**
     * @brief Конструктор дерева.
     */
    BST();

    /**
     * @brief Деструктор дерева.
     */
    ~BST();

    /**
     * @brief Вставка ключа в дерево.
     * @param key Ключ для вставки.
     */
    void insert(T key);

    /**
     * @brief Удаление ключа из дерева.
     * @param key Ключ для удаления.
     */
    void deleteKey(T key);

    /**
     * @brief Печать дерева.
     */
    void printTree() const;

    /**
     * @brief Поиск ключа в дереве.
     * @param key Ключ для поиска.
     * @return Узел с ключом, если он существует.
     */
    Node<T>* search(T key) const;
};

#endif  // BST_HPP