//
//  binomial.cpp
//  codeforces
//
//  Created by Sumit Kumar on 15/06/24.
//

#include <numeric>

namespace binomial {

int ncr(int n, int r) {
    double res = 1;
    for (int i = 1; i <= r; ++i)
        res = res * (n - r + i) / i;
    return (int)(res + 0.01);
}


namespace pascal {

const int MAXN = 1e3;
int C[MAXN + 1][MAXN + 1];
void precompute() {
    C[0][0] = 1;
    for (int n = 1; n <= MAXN; ++n) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k)
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
    }
}

} // pascal

namespace modulo {

const int MAXN = 2e5;
const int MOD = 1e9 + 7;
int64_t factorial[MAXN + 1];
int64_t inv_factorial[MAXN + 1];

inline int64_t mod_mul(int64_t x, int64_t y){
    return ((x % MOD) * (y % MOD)) % MOD;
}

int64_t mod_pow(int64_t x, int64_t y) {
    int64_t result = 1;
    x %= MOD;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1)
            result = (result * x) % MOD;
        y >>= 1;
        x = (x * x) % MOD;
    }
    return result;
}

inline int64_t mod_inv_prime(int64_t x){
    // This works only if MOD is a prime number.
    return mod_pow(x, MOD-2);
}

void precompute() {
    factorial[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        factorial[i] = mod_mul(factorial[i - 1], i);
    }
    
    inv_factorial[MAXN] = mod_inv_prime(factorial[MAXN]);
    for(int i = MAXN - 1; i >= 0; --i){
        inv_factorial[i] = mod_mul(inv_factorial[i + 1], i + 1);
    }
}

int64_t ncrp(int n, int r){
    if (r > n || r < 0) return 0;
    return mod_mul(mod_mul(factorial[n], inv_factorial[r]), inv_factorial[n - r]);
}
} // modulo

} //binomial
