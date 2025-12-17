#include <span>
#include <iostream>

/**
 * This "optimized" version is actually only faster for nearly sorted arrays.
 * It achieves the same time complexits as the naive version for random arrays.
 * For nearly sorted arrays, the time complexity approaches O(n).
 */
namespace {
    void bubble_sort(std::span<int32_t> arr) {
        if (arr.size() <= 1) return;

        size_t n = arr.size();

        while (n > 1) {
            size_t prev_swap = 0; // following elements are already sorted

            for (size_t i = 1; i < n; i++) {
                if (arr[i - 1] > arr[i]) {
                    std::swap(arr[i - 1], arr[i]);
                    prev_swap = i;
                }
            }

            n = prev_swap; // break loop if nos waps occurred
        }
    }
}

extern "C" {
void bubble_sort_optimized(int32_t *arr, const uint32_t n) {
    bubble_sort(std::span<int32_t>(arr, n));
}
}
