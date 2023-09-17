#include <iostream>

int main(int args, char* argv[]) {
    int n; std::cin >> n;
    int array[n];
    for (size_t i = 0; i < n; ++i) std::cin >> array[i];

    int count = 1;
    for (size_t i = 1; i < n - 1; ++i) {
        for (size_t j = n - 1; j >= i + 1; --j) {
            count++;
            if (array[j] < array[j - 1]) 
                std::swap(array[j], array[j - 1]);
        }
    }

    std::cout << count << std::endl;
    for (int value: array) std::cout << value << ' ';
    std::cout << std::endl;
}