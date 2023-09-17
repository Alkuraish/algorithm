#include <iostream>
#include <array>

size_t partition(int*, int, int);

void quick_sort(int* arr, int p , int r) {
    if (p < r) {
        size_t q = partition(arr, p, r);
        quick_sort(arr, p, q - 1);
        quick_sort(arr, q + 1, r);
    }
}

size_t partition(int* arr, int p, int r) {
    int x = arr[r];
    int i = p;

    for (int j {p}; j <= r - 1; ++j) {
        if (arr[j] < x) {
            std::swap(arr[i], arr[j]);
            i += 1;
        }
    }
    std::swap(arr[i], arr[r]);
    return i;
}

int main(int args, char* argv[]) {
    int arr[]   {1, 5, 6, 1, 5, 6 };
    quick_sort(arr, 0, std::size(arr) - 1);
    for (int value: arr) std::cout << value << ' ' ;

}
