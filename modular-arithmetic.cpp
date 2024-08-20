//
//  modular-arithmetic.cpp
//  codeforces
//
//  Created by Sumit Kumar on 08/06/24.
//
#include <iostream>
#include <cstdint>
#include <functional>
#include <cassert>

using namespace std;

namespace modular{

const int MOD = 998244353;

class mint {
public:
    int64_t num;

    mint() : num(0) {}
    mint(int64_t n) : num((n % MOD + MOD) % MOD) {}
    mint operator+(const mint& a)const{
        return mint(*this) += a;
    }
    mint operator-() const{
        return mint(0) - *this;
    }
    mint& operator+=(const mint& a){
        if((num += a.num) >= MOD) num -= MOD;
        return *this;
    }
    mint& operator-=(const mint& a){
        if((num += MOD - a.num) >= MOD) num -= MOD;
        return *this;
    }
    mint& operator*=(const mint& a){
        ( num *= a.num) %= MOD;
        return *this;
    }
    mint operator-(const mint& a)const{
        return mint(*this) -= a;
    }
    mint operator*(const mint& a)const{
        return mint(*this) *= a;
    }
    bool operator<(const mint& a)const{
        return num < a.num;
    }
    bool operator==(const mint& a)const{
        return num == a.num;
    }
};
istream& operator>>(istream&i,mint&a){
    i >> a.num;
    return i;
}
ostream& operator<<(ostream&o,const mint&a){
    o << a.num;
    return o;
}


inline int64_t mod_add(int64_t x, int64_t y){
    return ((x % MOD) + (y % MOD)) % MOD;
}

inline int64_t mod_sub(int64_t x, int64_t y){
    return ((x % MOD) - (y % MOD) + MOD)%MOD;
}

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

int64_t mod_inv(int64_t x) {
    function<int64_t(int64_t, int64_t, int64_t&, int64_t&)> gcd_extended = [&](int64_t a, int64_t b, int64_t& y, int64_t& z){
        if (a == 0) {
            y = 0;
            z = 1;
            return b;
        }
        int64_t y1, z1;
        int64_t g = gcd_extended(b % a, a, y1, z1);
        y = y1 - (b / a) * z1;
        z = y1;
        return g;
    };
    
    int64_t y, z;
    int64_t g = gcd_extended(x, MOD, y, z);
    assert(g != 1); // x and MOD should be coprime for inverse to exist
    return (x % MOD + MOD) % MOD;
}

int64_t mod_div(int64_t x, int64_t y){
    x %= MOD;
    int64_t inv = mod_inv_prime(y);
    // int64_t inv = mod_inv(y);
    return (inv * x) % MOD;
}

} // modular
