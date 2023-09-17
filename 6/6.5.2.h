
#include <iostream>
#include <limits>
#include <memory>
#include <vector>

#ifndef HEAP

#define HEAP

static const int min_value = std::numeric_limits<int>::min();

class Back_Heap {
    static const size_t max_size = 10e6;
    public:

        std::unique_ptr<int[]> pointer;
        size_t size;

        static size_t parent(size_t index);
        static size_t left(size_t index);
        static size_t right(size_t index);

        void min_heapify(size_t index);

        void build_min_heap();

        Back_Heap(std::vector<int> value);

        int& operator[](size_t index);

    friend std::ostream& operator<<(std::ostream& stream, Back_Heap& h);
};

int& Back_Heap::operator[](size_t index) {
    return this->pointer[index - 1];
}


size_t Back_Heap::parent(size_t index) {
    return index / 2;
}
size_t Back_Heap::left(size_t index ) {
    return index * 2;
}
size_t Back_Heap::right(size_t index) {
    return index * 2 + 1;
}

void Back_Heap::min_heapify(size_t index) {
    size_t left = Back_Heap::left(index);
    size_t right = Back_Heap::right(index);

    size_t letter = index;

    if ( left <=  this->size &&  (*this)[left] < (*this)[index]) {
        letter =  left;
    }
    if (right <= this->size && (*this)[right] < (*this)[letter]) {
        letter = right;
    }

    if (letter != index) {
        std::swap((*this)[letter], (*this)[index]);
        return min_heapify(letter);
    }
}

void Back_Heap::build_min_heap() {
    for (size_t i {this->size / 2}; i >= 1; --i) {
        this->min_heapify(i);
    }
}

Back_Heap::Back_Heap(std::vector<int> value): size(value.size()) {
    this->pointer = std::make_unique<int[]>(max_size);

    for (size_t i {0}; i < this->size; ++i)
        pointer[i] = value[i];

    this->build_min_heap();
}


std::ostream& operator<<(std::ostream& stream, Back_Heap& h) {
    for (size_t i{1}; i <= h.size; ++i)
        stream << h[i] << ' ';
    return stream;
}

#define QUEUE




class Queue: public Back_Heap {
    public:
        Queue(std::vector<int> value);

        int heap_min();

        int heap_extract_min();

        void heap_decrease_key(size_t index, int value);

        void min_heap_insert(int value);

};

Queue::Queue(std::vector<int> value): Back_Heap(value) {}


int Queue::heap_min() {
    return (*this)[1];
}

int Queue::heap_extract_min() {
    if (this->size < 1)
        return std::numeric_limits<int>::max();
    else {
        int max = (*this)[1];
        (*this)[1] = (*this)[this->size];
        this->min_heapify(1);
        this->size -= 1;
        return max;
    }
}

void Queue::heap_decrease_key(size_t index, int value) {
    if ((*this)[index] > value) {
        (*this)[index] = value;
        size_t i = index;
        while (parent(i) <= this->size && (*this)[i] < (*this)[parent(i)]) {
            std::swap((*this)[parent(i)], (*this)[i]);
            i = parent(i);
        }
    }
}


void Queue::min_heap_insert(int value) {
    this->size += 1;
    (*this)[size] = std::numeric_limits<int>::max();
    this->heap_decrease_key(this->size, value);
}


#endif



