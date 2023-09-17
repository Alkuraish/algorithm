#include <iostream>
#include <memory>
#include <string>


struct element_tree {
    int value;
    std::shared_ptr<element_tree> left;
    std::shared_ptr<element_tree> right;
    std::shared_ptr<element_tree> parent;
};

class Binary_Tree {
    private:      
        std::shared_ptr<element_tree> root;

    public:
        Binary_Tree(int value_root);

        void insert(int value, std::string path);
    
    friend std::ostream& operator<<(std::ostream& stream, Binary_Tree& tree);
};



Binary_Tree::Binary_Tree(int value_root) {
    element_tree root = {value_root, nullptr, nullptr, nullptr};
    this->root = std::make_shared<element_tree>(root);
}

std::ostream& 
operator<<(std::ostream& stream, Binary_Tree& tree) {
    return stream;
}

void 
Binary_Tree::insert(int value, std::string path) {
    element_tree new_element = {value, nullptr, nullptr, nullptr};


    auto recent_point { std::make_shared<element_tree>(this) }; 
    size_t i {0};
    for (; i < path.length() - 1; ++i) {
        if (path[i] == 'l')
            recent_point = recent_point->left;
        else 
            recent_point = recent_point->right; 
    }

    new_element.parent = recent_point;

    if (path[i] == 'l')  {
        auto new_el = std::make_shared<element_tree>();

        recent_point->left      = new_el;
    }
    else {
        auto new_el = std::make_shared<element_tree>();

        recent_point->right     = new_el;
    }
}

int main(int args, char** argv) {
    return 0;

    Binary_Tree tree(10);


}