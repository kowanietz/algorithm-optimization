#include <span>

namespace internal {
    void selection_sort(std::span<int32_t> arr) {
        const size_t n = arr.size();

        for (size_t i = 0; i < n - 1; ++i) {
            size_t min_index = i;

            for (size_t j = i + 1; j < n; ++j) {
                if (arr[j] < arr[min_index]) {
                    min_index = j;
                }
            }

            std::swap(arr[i], arr[min_index]);
        }
    }
}

extern "C" {
void selection_sort(int32_t *arr, const uint32_t n) {
    internal::selection_sort(std::span<int32_t>(arr, n));
}
}
