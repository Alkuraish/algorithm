#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <limits>


class Queue {
    private:
        static const size_t max_size {100000};
        std::unique_ptr<int[]> ptr;
        int tail;
        int head;
    public:
        Queue(void);
        Queue(std::vector<int> array);


        void enqueue(int value);
        int dequeue();
};

Queue::Queue(void): tail(0), head(-1), ptr(std::make_unique<int[]>(max_size)) 
{}


Queue::Queue(std::vector<int> array): Queue() {
    this->tail = array.size();
    this->head = 0;
    for (size_t i {0}; i < max_size; ++i) 
        this->ptr[i] = ptr[i];
}

void Queue::enqueue(int value) {
    if (tail != head) {
        this->ptr[tail] = value;
        this->tail = (this->tail + 1) % max_size;
    }
}

int Queue::dequeue()
{    
    this->head = (this->head + 1) % max_size;

    if (head != -1)
        return this->ptr[head];

    return std::numeric_limits<int>::max();
}


using queue = Queue;

int main(int args, char** argv) {

    queue qu;

    for (size_t i {0}; i < 100; ++i) {
        qu.enqueue(i);
    }


    for (size_t i {0}; i < 100; ++i) {
        std::cout << qu.dequeue() << std::endl;
    }

    qu.enqueue( 1000 );

    qu.enqueue(100);


    std::cout <<  qu.dequeue() << std::endl;

    return 0;
}


