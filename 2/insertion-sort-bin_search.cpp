#include <iostream>

int main(int args, char*  argv[]) {
    int n;
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; ++i) 
                    std::cin >> array[i];


    for (int i = 1; i < n; ++i) {
        int new_element = array[i];
        int left = -1, right = i;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (array[mid] <= new_element) 
                left = mid;
            else
                right = mid;
        }
        for (int j = i - 1; j > left; --j) 
            array[j + 1] = array[j];
        array[left + 1] = new_element;
    }

    for (int value: array) 
        std::cout << value << ' ';
    std::cout << std::endl;

    return 0;
}