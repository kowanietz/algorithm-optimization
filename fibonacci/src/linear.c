#include <gmp.h>
#include "fibonacci.h"

void fib_linear(mpz_t result, int n) {
    if (n < 2) {
        mpz_set_ui(result, n);
        return;
    }

    mpz_t f0, f1;
    mpz_init_set_ui(f0, 0);
    mpz_init_set_ui(f1, 1);

    while (n-- > 1) {
        mpz_add(f0, f0, f1);
        mpz_swap(f0, f1);
    }

    mpz_set(result, f1);
    mpz_clear(f0);
    mpz_clear(f1);
}
