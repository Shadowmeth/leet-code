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

void subarr_given_sum(int *arr, int size, int target) {
    // sub array with sum = target
    int sum = 0;

    // dynamic window so we need a low and high
    size_t low, high;
    low = high = 0;
    for (low = 0; low < size; low++) {
        while (sum < target && high < size) {
            sum += arr[high];
            high++;
        }
        // check if we reached the target sum
        if (sum == target) {
            printf("subarray found: arr[%zu, %zu]\n", low, high - 1);
            return;
        }

        // target sum not reached, shrink the window
        sum -= arr[low];
    }

    return;
}

int smallest_subarr_sum_k(int *arr, int size, int target) {
    int sum             = 0;
    int smallest_subarr = numeric_limits<int>::max();

    int low, high;
    low = high = 0;
    for (; high < size; high++) {
        sum += arr[high];
        while (sum >= target && low < high) {
            // target sum reached, try shrinking the window while trying to
            // maintain the criteria
            if (sum - arr[low] < target) {
                break;
            }
            sum -= arr[low++];
        }

        if (sum >= target) {
            int new_win_size = high - low + 1;
            smallest_subarr  = std::min(new_win_size, smallest_subarr);
        }
    }

    return smallest_subarr;
}

int main() {
    // int arr[]    = {4, 2, 1, 7, 8, 1, 2, 8, 1, 0};
    // int arr_size = sizeof(arr) / sizeof(arr[0]);
    int arr[]      = {4, 2, 2, 7, 8, 1, 2, 8, 10};
    int arr_size   = sizeof(arr) / sizeof(arr[0]);
    int target_sum = 8;
    cout << smallest_subarr_sum_k(arr, arr_size, target_sum) << endl;
}
