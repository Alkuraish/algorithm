#include <iostream>
#include "6.5.2.h"

using Heap = Back_Heap;

int main(int args, char* argv[]) {
    Queue v({4, 1, 3, 4, 6});
    std::cout << v << std::endl;
    v.min_heap_insert(2);
    std::cout << v << std::endl;
    return 0;
}