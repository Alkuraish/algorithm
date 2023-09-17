#include <iostream>
#include "priority_queue.h"


int main(int args, char* argv[]) {
    std::vector<int>  vec = {15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1};
    Queue queue(vec);
    queue.max_heap_insert(10);
    std::cout << queue << std::endl;
}