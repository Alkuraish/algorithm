#include <iostream>

void merge(size_t, size_t, size_t, int*);


void merge_sort(size_t l, size_t r, int* arr) {
    if (l < r) {
        size_t m = (r + l) / 2;
        merge_sort(l, m, arr);
        merge_sort(m + 1, r, arr);
        merge(l, m, r, arr);
    }
}

void merge(size_t l, size_t m, size_t r, int* arr) {
    int L[m - l + 1], R[r - m];

    for (size_t i = 0; i < m - l + 1; ++i)     L[i] = *(arr + l + i);
    for (size_t i = 0; i < r - m; ++i )    R[i] = *(arr + m + 1 + i);

    size_t l_i = 0, r_i = 0; 
    for (size_t i = l; i <= r ; ++i) {
        if ( (L[l_i] < R[r_i] && l_i < m - l + 1) || (r_i >= r - m))
            arr[i] = L[l_i++];
        else
            arr[i] = R[r_i++];
    }
}


int main(int args, char* argv[]) {
    int n; 
    std::cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i) std::cin >> arr[i];

    merge_sort(0, n - 1, arr);


    for (int value: arr) std::cout << value << ' ';
    std::cout << std::endl;

    return 0;
}