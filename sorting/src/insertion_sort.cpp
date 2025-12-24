#include <span>

namespace internal {
    void insertion_sort(std::span<int32_t> arr) {
        const size_t n = arr.size();

        for (size_t i = 1; i < n; ++i) {
            const int32_t key = arr[i];
            ssize_t j = static_cast<ssize_t>(i) - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }

            arr[j + 1] = key;
        }
    }
}

extern "C" {
void insertion_sort(int32_t *arr, const uint32_t n) {
    internal::insertion_sort(std::span<int32_t>(arr, n));
}
}
