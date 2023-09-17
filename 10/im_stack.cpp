#include <memory>
#include <iostream>
#include <array>
#include <vector>

class Stack {
    private:
        const static size_t max_size {1000000};
        std::unique_ptr<int[]> ptr;
        size_t top;
    public:

        Stack(int* array, size_t num);

        Stack(std::vector<int>); 
        
        Stack operator=(std::vector<int>);

        bool stack_empty();


        int pop();

        void push(int value);
};

Stack 
Stack::operator=(std::vector<int> array) {
    return Stack(array);
}


Stack::Stack(int* array, size_t num): top(num) {
    this->ptr = std::make_unique<int[]>(max_size);
    for (size_t i {0}; i < num; ++i) {
        this->ptr[i] = array[i];
    }
}


Stack::Stack(std::vector<int> array): top(array.size()) {
    this->ptr = std::make_unique<int[]>(max_size);
    for (size_t i {0}; i < array.size(); ++i)
        this->ptr[i] = array[i];
}

bool 
Stack::stack_empty() {
    if (this->top == 0) {
        return true;
    }
    else {
        return false;
    }
}

int
Stack::pop() {
    return this->ptr[--this->top];
}


void 
Stack::push(int value) {
    this->ptr[this->top++] = value;
}



int main(int args, char** argv) {
    Stack value({1, 2, 5, 6});
    Stack val = std::vector<int>({1, 7, 6, 4});
    
    std::cout << val.pop() << std::endl;
    std::cout << val.pop() << std::endl;
    
    return 0;
}