#include <iostream>

#define MAX 10e5;
void merge(int*, int, int, int);

void merge_sort(int* array, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(array, p, q);
        merge_sort(array, q + 1, r);
        merge(array, p, q, r);
    }

}

void merge(int* array, int p, int q, int r) {
    int len_left = q - p + 1;
    int len_right = r - q;
    int left_arr[len_left + 1], right_arr[len_right + 1];
    for (int i = 0; i < len_left; ++i) 
        left_arr[i] = array[p + i];
    for (int j = 0; j < len_right; ++j) 
        right_arr[j] = array[q + j + 1];

    left_arr[len_left] = MAX;
    right_arr[len_right] = MAX;



    int left_iter = 0;
    int right_iter = 0;

    for (int i = p; i <= r; ++i) { 
        if (left_arr[left_iter] <= right_arr[right_iter]) 
            *(array + i) = left_arr[left_iter++];
        else 
            *(array + i) = right_arr[right_iter++];
        
    }

}


int main(int args, char* argv[]) {
    int n;
    std::cin >> n;
    int array[n];

    for (int i = 0; i < n; ++i) 
        std::cin >> array[i];
    
    merge_sort(array, 0, n - 1);

    for (auto value: array) 
        std::cout << value << ' ';
    std::cout  << std::endl;


    return 0;
}