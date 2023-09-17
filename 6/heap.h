#ifndef HEAP

#include <iostream>
#include <vector>

#define HEAP


class Heap {

    const static size_t max_size = 10e6;

    public:

        static size_t get_index(size_t index);

        std::vector<int> heap;

        size_t size;

        Heap(std::vector<int> value);

        void Build_max_Heap();

        void max_Heapify(size_t index);

        static size_t left(size_t index);

        static size_t right(size_t index);

        static size_t parent(size_t index);

        int& operator[](size_t value);

    friend std::ostream& operator<<(std::ostream& stream, Heap& h);
};

void Heap::Build_max_Heap() {
    for (size_t i {this->size / 2 }; i >= 1; --i) {
        max_Heapify(i);
    }

}

std::ostream& operator<<(std::ostream& stream, Heap& h) {
    for (size_t i = 1; i <= h.size; ++i)
        stream << h[i] << ' ';
    return stream;
}

Heap::Heap(std::vector<int> value): size(value.size()) {
    heap = std::vector<int>(max_size, 0);

    for (size_t i = 0; i < value.size(); ++i)
            heap[i] = value[i];
    this->Build_max_Heap();
}

size_t Heap::get_index(size_t index) {
    return index - 1;
}
size_t Heap::left(size_t index) {
    return index * 2;
}
size_t Heap::right(size_t index) {
    return index * 2 + 1;
}
size_t Heap::parent(size_t index) {
    return index / 2;
}

void Heap::max_Heapify(size_t index) {
    size_t left  {Heap::left(index)};
    size_t right  {Heap::right(index)};

    size_t largest {};

    if (right <= this->size && this->heap[Heap::get_index(index)] < this->heap[Heap::get_index(right)])
        largest = right;
    else
        largest = index;
    if (left <= this->size && this->heap[Heap::get_index(largest)] < this->heap[Heap::get_index(left)])
        largest = left;
    if (largest != index) {
        std::swap(this->heap[get_index(index)], this->heap[get_index(largest)]);
        return max_Heapify(largest);
    }
}

int& Heap::operator[](size_t value) {
    return this->heap[get_index(value)];
}

#endif

