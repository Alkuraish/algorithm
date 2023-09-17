#include <iostream>
#include "list.hpp"
#include "hash.hpp"


int main(int args, char** argv) {
    list l;

    hash  h;

    h.insert(std::make_pair(9, 8));
    h.insert(7, 7);
    h.insert(10, 7);
    h.insert(11, 6);
    h.insert(34, 67);
    h.insert(21, 878);

    h.remove(10);
    h.remove(7);
    

    std::cout << h;

    return 0;
}