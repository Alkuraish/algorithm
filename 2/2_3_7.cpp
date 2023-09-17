#include <iostream>
#include <limits>
#include <algorithm>

#define inf 10e4;

void merge(int array[], int l, int mid, int r) {
    int left_arr[mid - l  + 2], right_arr[r - mid + 1];

    std::copy(array + l, array + mid + 1, left_arr);
    std::copy(array + mid + 1, array + r + 1, right_arr);

    left_arr[mid - l + 1] = inf;
    right_arr[r - mid] = inf;

    int i = 0, j = 0;
    for (int it = l; it <= r; ++it) {
        if (left_arr[i] <= right_arr[j]) {
            array[it] = left_arr[i++];
        }
        else
            array[it] = right_arr[j++];
    }
}

void merge_sort(int* array, int l, int r) {
    if (r > l) {
        int mid = (r + l) / 2;
        merge_sort(array, l, mid);
        merge_sort(array, mid + 1, r);
        merge(array, l, mid, r);
    }
}


int main(int args, char* argv[]) {
    int n; std::cin >> n;
    int array[n];    
    for (int i = 0; i < n; ++i) 
        std::cin >> array[i];


    merge_sort(array, 0, n - 1);


    int value; std::cin >> value;

    int l = 0, r = n - 1;
    while (r > l) {
        if (value > array[r] + array[l])
            l += 1;
        else if (value < array[r] + array[l]) 
            r += 1;
        else {
            std::cout << "Yes";
            break;
        }
    }

    return 0;
}