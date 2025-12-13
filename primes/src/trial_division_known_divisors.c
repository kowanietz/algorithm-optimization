#include <stdbool.h>
#include <stdlib.h>

uint32_t trial_division_known_divisors(const uint32_t n) {
    if (n == 0) return 2;

    uint32_t *primes = malloc((n + 1) * sizeof(uint32_t)); // store konwn primes in array
    primes[0] = 2;

    uint32_t count = 1;
    uint32_t candidate = 3;

    while (count <= n) {
        bool is_prime = true;

        // only test against primes
        for (uint32_t i = 0; i < count; i++) {
            if (primes[i] * primes[i] > candidate) {
                break;
            }
            if (candidate % primes[i] == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            primes[count] = candidate;
            count++;
        }
        candidate += 2; // Skip even numbers
    }

    const uint32_t result = primes[n];
    free(primes);

    return result;
}
