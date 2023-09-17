#include <iostream>


int main(int args, char* argv[]) {
    int len;
    std::cin >> len;
    int array[len];


    for (int i = 0; i < len; ++i) 
        std::cin >> array[i];

    for (int i = 1; i < len; ++i) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && key < array[j]) {
            array[j + 1] = array[j];
            j -= 1;
        }
        array[j + 1] = key;
    }

    for (int i = 0; i < len; ++i) 
        std::cout << *(array + i) <<  ' ';
    std::cout << std::endl;

    return 0;

}