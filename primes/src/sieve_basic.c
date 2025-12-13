#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

uint32_t sieve_basic(const uint32_t n) {
    if (n < 6) {
        const uint8_t small[] = {2, 3, 5, 7, 11, 13};
        return small[n];
    }

    // https://en.wikipedia.org/wiki/Rosser%27s_theorem i really hope this works
    const double n_d = (double) n;
    const uint32_t limit = (uint32_t) (n_d * (log(n_d) + log(log(n_d))) * 1.3);

    // save primalities in array
    bool *is_prime = (bool *) malloc((limit + 1) * sizeof(bool));
    if (is_prime == NULL) {
        return 0;
    }

    for (uint32_t i = 0; i <= limit; i++) {
        is_prime[i] = true;
    }

    is_prime[0] = false;
    is_prime[1] = false;

    // https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
    for (uint32_t p = 2; p <= limit; p++) {
        if (is_prime[p]) {
            for (uint32_t multiple = p + p; multiple <= limit; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }

    // Count primes and find the nth one
    uint32_t count = 0;
    uint32_t result = 0;
    for (uint32_t i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            if (count == n) {
                result = i;
                break;
            }
            count++;
        }
    }

    free(is_prime);
    return result;
}
