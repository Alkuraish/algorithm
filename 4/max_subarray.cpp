#include <iostream>
#include <limits>
#include <vector>

#define inf std::numeric_limits<int>::max()

std::vector<int> find_crossing_subarray(int* array, int left, int mid, int right) {
    int left_sum = -inf;
    int max_left_ind = NULL;

    int summ = 0;
    for (int i = mid; i >= left; --i) {
        summ += array[i];
        if (summ >= left_sum) {
            left_sum = summ;
            max_left_ind = i;
        }
    }

    int right_sum = -inf;
    int max_right_ind = NULL;
    summ = 0;
    for (int j = mid + 1; j <= right; ++j) {
        summ += array[j];
        if (summ >= right_sum) {
            right_sum = summ;
            max_right_ind = j;         
        }
    }
    return {max_left_ind, max_right_ind, left_sum + right_sum};
}

std::vector<int> find_max_subarray(int* array, int left, int right) {
    if (left == right)
        return {left, right, array[left]};
    else {
        int mid = (left + right) / 2;

        std::vector<int> value_left_seg = find_max_subarray(array, left, mid);
        std::vector<int> value_right_seg = find_max_subarray(array, mid + 1, right);
        std::vector<int> value_crossing_seg = find_crossing_subarray(array, left, mid, right);
        
        if (value_left_seg[2] >= value_right_seg[2] && value_left_seg[2] >= value_crossing_seg[2])
            return value_left_seg;
        else if (value_right_seg[2] >= value_left_seg[2] && value_right_seg[2] >= value_crossing_seg[2])
            return value_right_seg;
        else
            return value_crossing_seg;
    }
}




int main(int args, char* argv[]) {
    int n;
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; ++i) std::cin >> array[i];


    std::vector<int> max_subarray = find_max_subarray(array, 0, n - 1);

    for (auto value: max_subarray) {
        std::cout << value << std::endl;
    }

    return 0;
}