#include <iostream>
#include <vector>
#include "heap.h"

static std::vector<int> heapsort(std::vector<int> value) {
    Heap heap(value);
    for (size_t i {value.size()}; i >= 2; --i) {
        std::swap(heap.heap[Heap::get_index(1)], heap.heap[Heap::get_index(i)]);
        heap.size -= 1;
        heap.max_Heapify(1);
    }
    return heap.heap;
}


int main(int args, char* argv[]) {
    std::vector<int> v {5, 13, 2, 25, 7, 17, 20, 8, 4};
    v = heapsort(v);
    for (auto value: v)
        std::cout << value << ' ' << std::endl;
    return 0;
}