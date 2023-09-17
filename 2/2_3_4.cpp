#include <iostream>

void add_element(size_t right, int* arr);

void inseration_sort(size_t r, int* arr, size_t n) {
    if (r >= 1) {
        inseration_sort(r - 1, arr, n);
        add_element(r, arr);

        for (size_t i = 0; i < n; ++i) std::cout << arr[i] << ' ';
        std::cout << std::endl; 
    }
}

void add_element(size_t right, int* arr) {
    int key = *(arr + right);
    int j = right - 1;
    for (; j >= 0 && key < arr[j]; --j) 
        *(arr + j + 1) = *(arr + j);
    arr[j  + 1] = key;   
}


int main(int args, char* argv[]) {
    int n;
    std::cin >> n;

    int array[n];
    for (size_t i = 0; i < n; ++i) std::cin >> array[i];

    inseration_sort(n - 1, array, n);

    for (int value: array)  std::cout << value << ' ';
    std::cout << std::endl;
    

    return 0;
}