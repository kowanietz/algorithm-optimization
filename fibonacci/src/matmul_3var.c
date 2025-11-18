#include <gmp.h>
#include "fibonacci.h"

void matmul_3var(mpz_t result[3], mpz_t A[3], mpz_t B[3]) {
    mpz_t tmp0, tmp1, tmp2;
    mpz_inits(tmp0, tmp1, tmp2, NULL);

    mpz_mul(tmp0, A[0], B[0]);
    mpz_addmul(tmp0, A[1], B[1]);

    mpz_mul(tmp1, A[0], B[1]);
    mpz_addmul(tmp1, A[1], B[2]);

    mpz_mul(tmp2, A[1], B[1]);
    mpz_addmul(tmp2, A[2], B[2]);

    mpz_set(result[0], tmp0);
    mpz_set(result[1], tmp1);
    mpz_set(result[2], tmp2);

    mpz_clears(tmp0, tmp1, tmp2, NULL);
}


void fib_matmul_3var(mpz_t result, int n) {
    if (n <= 0) {
        mpz_set_ui(result, 0);
        return;
    }

    mpz_t step[3];
    mpz_init_set_ui(step[0], 0);
    mpz_init_set_ui(step[1], 1);
    mpz_init_set_ui(step[2], 1);


    mpz_t fib[3];
    mpz_init_set_ui(fib[0], 0);
    mpz_init_set_ui(fib[1], 1);
    mpz_init_set_ui(fib[2], 1);

    while (n > 0) {
        if ((n & 1) != 0) {
            matmul_3var(fib, fib, step);
        }
        matmul_3var(step, step, step);
        n >>= 1;
    }

    mpz_set(result, fib[0]);

    mpz_clears(step[0], step[1], step[2], NULL);
    mpz_clears(fib[0], fib[1], fib[2], NULL);
}
