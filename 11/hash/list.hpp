#ifndef LIST

#define LIST

#include <iostream>
#include <string>
#include <memory>


struct Unit {

    Unit(std::shared_ptr<Unit> left, std::shared_ptr<Unit> right, std::pair<int, int> value): 
                left{left}, right{right}, value{value} { }                                                 
                                                                                   
    std::shared_ptr<Unit> right ;
    std::shared_ptr<Unit> left  ;
    std::pair<int, int> value   ;
};

class List 
{
    public:
        List(): __last{ nullptr } {}
        List(const List& obj) = delete;

        void insert(std::pair<int, int> value);

        void insert(int first, int second) { insert(std::make_pair(first, second)); }

        std::shared_ptr<Unit> search_key(int key);

        
        void remove(std::shared_ptr<Unit> unit);

        void remove(int key) {  remove(search_key(key));    } 

    private:
        std::shared_ptr<Unit> __last;
    friend std::ostream& operator<<(std::ostream& stream, List& list);
};



void List::insert(std::pair<int, int> value) {
    auto current {std::make_shared<Unit>(Unit{nullptr, __last, value})};

    if (__last != nullptr) 
        __last->left = current;

    __last = current;
}

void List::remove(std::shared_ptr<Unit> unit) {
    if (unit == nullptr)
        return ;
    
    auto left_unit      {unit->left};
    auto right_unit     {unit->right};

    if (left_unit != nullptr && right_unit != nullptr) {

        left_unit->right                = right_unit;
        right_unit->left                = left_unit;

    }   

    else if (left_unit == nullptr && right_unit == nullptr) {
        __last                          = nullptr;
    }
    else if (left_unit != nullptr) {
        left_unit->right                = nullptr;
    }
    else if (right_unit != nullptr) {
        right_unit->left                = nullptr;
        __last                          = right_unit;
    }
}


std::shared_ptr<Unit> List::search_key(int key) {
    auto current {__last};
    while (current != nullptr && current->value.first != key) {
        current = current->right;
    }
    return current;
}

std::ostream& operator<<(std::ostream& stream, List& list) 
{

    auto current {list.__last};

    while (current != nullptr) {
        stream << '(' << current->value.first << ", " << current->value.second << ')' << ' ';
        current = current->right;
    }

    return stream;
}

using list = List;

#endif