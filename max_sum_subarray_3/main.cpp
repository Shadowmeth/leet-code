#include <iostream>
#include <limits>
using namespace std;

int max_sum_subarray(int *arr, int size /* array size */, int k) {
    int max_sum     = numeric_limits<int>::min();
    int current_sum = 0;

    for (int i = 0; i < size; i++) {
        current_sum += arr[i];
        if (i >= k - 1) {
            // reached window size
            max_sum = std::max(max_sum, current_sum);
            current_sum -= arr[i - (k - 1)];
        }
    }

    return max_sum;
}

int main() {
    int arr[]    = {4, 2, 1, 7, 8, 1, 2, 8, 1, 0};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout << max_sum_subarray(arr, arr_size, 3) << endl;
}
