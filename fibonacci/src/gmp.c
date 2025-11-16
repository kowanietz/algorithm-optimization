#include <gmp.h>
#include "fibonacci.h"

void fib_gmp(mpz_t result, const int n) {
    mpz_fib_ui(result, n);
}