#include <iostream>
#include <string>
#include <memory>
#include <vector>





using pointer = std::shared_ptr<Node>;

struct Node {

    Node(pointer p, pointer left, pointer right, int value):    /* constructor Node*/
        p{p}, left{left}, right{right}, value{value} { }

    /* member variable */
        pointer p;
        pointer left;
        pointer right;
        int value;
};


class BinaryTree {
    public:
        BinaryTree(const BinaryTree& obj) = delete;
        BinaryTree(): __root{nullptr} {}

        void insert_tree(pointer z);

    private:
        pointer __root;
};


void BinaryTree::insert_tree(pointer node) {
    pointer parent_node {nullptr};
    pointer i {__root};

    while  (i != ) {
        
    }
}


