#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <limits>

static int mod(int value, int del) {
    if (value >= 0) 
        return value % del;
    else 
        return value - (value % del);

}

class Deque {
    private:
        static const size_t max_size {10000};
        int left;
        int right;
        std::unique_ptr<int[]> ptr;
    public:
        Deque(void);
        Deque(std::vector<int>);
        
        void push_back(int);
        void push_front(int);

        int pop_back();
        int pop_front();
};


void Deque::push_back(int value) {
    if ( mod ( (this->right + 1),  max_size ) != this->left) {
        this->ptr[ mod ( (this->right + 1), max_size)] = value;
        this->right = mod( (this->right + 1), max_size );
    }
    else {
        std::cout << "Segmentation fault: push_back" << std::endl;
    }
}


int Deque::pop_back() {
    int value;
    if ( mod((this->right - 1), max_size) != this->left - 1) {
        value = this->ptr[this->right];
        this->right = mod( (this->right - 1), max_size); 
    }
    else {
        std::cout << "Segmentation fault: pop_back" << std::endl;
        value = std::numeric_limits<int>::max();
    }
    return value;

}


void Deque::push_front(int value) {
    if ( mod(this->left - 1 , max_size) != this->right) {
        this->ptr[mod(this->left - 1, max_size)] = value;
        this->left = mod(this->left - 1, max_size);
    }
    else {
        std::cout << "Segmentation fault: push_front" << std::endl;
    }
}


int Deque::pop_front() {
    int value;
    if (mod(this->left + 1, max_size) != this->right + 1)  {
        value = this->ptr[this->left];
    }
    else {
        std::cout << "Segmantatation fault: pop_front" << std::endl;
        value = std::numeric_limits<int>::max();
    }
    return value;
}   


Deque::Deque(): left(-1), right(-1), ptr(std::make_unique<int[]>(max_size)) {}

Deque::Deque(std::vector<int> array): Deque() {
    for (size_t i {0}; i < array.size(); ++i) 
        push_back(array[i]);
    this->left = 0;
}

using deque = Deque;

int main(int args, char** argv) {
    deque d;
    for (size_t i {0}; i < 100; ++i)
        d.push_back(i);

    std::cout << d.pop_front() << std::endl;
    std::cout << d.pop_back()  << std::endl;
    return 0;
}