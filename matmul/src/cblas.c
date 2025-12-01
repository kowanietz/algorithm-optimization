#include <cblas.h>

void cblas(const double *A, const double *B, double *res,
           const int m, const int k, const int n) {
    cblas_dgemm(CblasRowMajor,
                CblasNoTrans,
                CblasNoTrans,
                m, n, k,
                1.0, A, k,
                B, n,
                0.0, res, n);
}
