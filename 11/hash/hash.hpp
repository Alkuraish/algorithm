#ifndef HASH

#define HASH

#include <iostream>
#include <memory>
#include "list.hpp"


class Hash 
{
    public:
        Hash(const Hash& obj) = delete;

        Hash(): __hashTable{std::make_unique<list[]>(__size)} {}

        void insert(std::pair<int, int> value);
        void insert(int first, int second) { insert(std::make_pair(first, second)); }

        void remove(int key);


    private:

        static const size_t __size {9};

        int hash_function(int key) const { return key % 9; }

        std::unique_ptr<list[]> __hashTable;

    friend std::ostream& operator<<(std::ostream& stream, Hash& hash);  

};


std::ostream& operator<<(std::ostream& stream, Hash& hash) {
    for (size_t i {0}; i < Hash::__size; ++i) 
        stream << i << ": " << hash.__hashTable[i] << '\n';
    return stream;
}

void Hash::insert(std::pair<int, int> value) {
    int index = hash_function(value.first);

    __hashTable[index].insert(value);
}

void Hash::remove(int key) {
    int index = hash_function(key);

    __hashTable[index].remove(key);
}

using hash = Hash;

#endif