#include <gmp.h>
#include "fibonacci.h"

void matmul_2x2_fastexp(mpz_t result[2][2], mpz_t A[2][2], mpz_t B[2][2]) {
    mpz_t tmp00, tmp01, tmp10, tmp11;
    mpz_inits(tmp00, tmp01, tmp10, tmp11, NULL);

    mpz_mul(tmp00, A[0][0], B[0][0]);
    mpz_addmul(tmp00, A[0][1], B[1][0]);

    mpz_mul(tmp01, A[0][0], B[0][1]);
    mpz_addmul(tmp01, A[0][1], B[1][1]);

    mpz_mul(tmp10, A[1][0], B[0][0]);
    mpz_addmul(tmp10, A[1][1], B[1][0]);

    mpz_mul(tmp11, A[1][0], B[0][1]);
    mpz_addmul(tmp11, A[1][1], B[1][1]);

    mpz_set(result[0][0], tmp00);
    mpz_set(result[0][1], tmp01);
    mpz_set(result[1][0], tmp10);
    mpz_set(result[1][1], tmp11);

    mpz_clears(tmp00, tmp01, tmp10, tmp11);
}


void fib_matmul_fastexp(mpz_t result, int n) {
    if (n <= 0) {
        mpz_set_ui(result, 0);
        return;
    }

    mpz_t step[2][2];
    mpz_init_set_ui(step[0][0], 0);
    mpz_init_set_ui(step[0][1], 1);
    mpz_init_set_ui(step[1][0], 1);
    mpz_init_set_ui(step[1][1], 1);

    mpz_t fib[2][2];
    mpz_init_set_ui(fib[0][0], 0);
    mpz_init_set_ui(fib[0][1], 1);
    mpz_init_set_ui(fib[1][0], 1);
    mpz_init_set_ui(fib[1][1], 1);

    while (n > 0) {
        if ((n & 1) != 0) {
            matmul_2x2_fastexp(fib, fib, step);
        }
        matmul_2x2_fastexp(step, step, step);
        n >>= 1;
    }

    mpz_set(result, fib[0][0]);

    mpz_clears(step[0][0], step[0][1], step[1][0], step[1][1], NULL);
    mpz_clears(fib[0][0], fib[0][1], fib[1][0], fib[1][1], NULL);
}
