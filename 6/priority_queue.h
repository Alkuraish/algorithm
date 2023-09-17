#ifndef QUEUE

#define QUEUE

#include <iostream>
#include "heap.h"
#include <limits>


static const int min = std::numeric_limits<int>::min();

class Queue : public Heap {
    public:
        Queue(std::vector<int> value);

        int max_heap();

        void max_heap_insert(int value);

        int extract_max();

        void increase_max_key(size_t index, int new_key);

};

Queue::Queue(std::vector<int> value): Heap(value) {}


int Queue::max_heap() {
    return this->heap[get_index(1)];
}

int Queue::extract_max() {
    if (this->size > 1) {
        int max = heap[get_index(1)];
        this->heap[get_index(1)] = this->heap[get_index(this->size)];
        this->size -= 1;
        this->max_Heapify(1);
        return max;
    }
    else
        return std::numeric_limits<int>::min();
}



void Queue::increase_max_key(size_t index, int new_key) {
    if (this->heap[index] < new_key) {
        this->heap[index] = new_key;

        size_t i = index;
        while (Queue::parent(i) > 0 && this->heap[Queue::parent(i)] < this->heap[i]) {
            std::swap(this->heap[i], this->heap[Queue::parent(i)]);
            i = Queue::parent(i);
        }
    }
    else
        std::cout << "Элемент меньше, чем значение" << std::endl;
}



void Queue::max_heap_insert(int value) {
    this->size += 1;
    this->heap[this->size] = min;
    this->increase_max_key(this->size, value);
}

#endif