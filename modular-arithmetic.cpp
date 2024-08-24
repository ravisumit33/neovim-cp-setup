//
//  modular-arithmetic.cpp
//  codeforces
//
//  Created by Sumit Kumar on 08/06/24.
//
#include <cassert>
#include <cstdint>
#include <functional>
#include <iostream>

using namespace std;

namespace modular {

const int MOD = 998244353;
const bool MOD_IS_PRIME = true;

class mint {
public:
  mint() : m_num(0) {}
  mint(int64_t n) : m_num((n % MOD + MOD) % MOD) {}
  mint &operator++() {
    m_num++;
    if (m_num == MOD)
      m_num = 0;
    return *this;
  }
  mint &operator--() {
    if (m_num == 0)
      m_num = MOD;
    m_num--;
    return *this;
  }
  mint operator++(int) {
    mint result = *this;
    ++(*this);
    return result;
  }
  mint operator--(int) {
    mint result = *this;
    --(*this);
    return result;
  }
  mint &operator+=(const mint &rhs) {
    if ((m_num += rhs.m_num) >= MOD)
      m_num -= MOD;
    return *this;
  }
  mint &operator-=(const mint &rhs) {
    if ((m_num += MOD - rhs.m_num) >= MOD)
      m_num -= MOD;
    return *this;
  }
  mint &operator*=(const mint &rhs) {
    (m_num *= rhs.m_num) %= MOD;
    return *this;
  }
  mint &operator/=(const mint &rhs) { return *this *= mint(rhs).inv(); }

  mint operator+() const { return *this; }
  mint operator-() const { return mint(0) - *this; }

  mint pow(int64_t y) const {
    assert(y >= 0);
    if (m_num == 0)
      return mint(0);
    if (y == 0)
      return mint(1);
    mint x = *this, r = 1;
    while (y) {
      if (y & 1)
        r *= x;
      x *= x;
      y >>= 1;
    }
    return r;
  }

  mint inv() const {
    if (MOD_IS_PRIME) {
      return pow(MOD - 2);
    } else {
      function<int64_t(int64_t, int64_t, int64_t &, int64_t &)> gcd_extended =
          [&](int64_t a, int64_t b, int64_t &y, int64_t &z) {
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
      int64_t g = gcd_extended(m_num, MOD, y, z);
      assert(g != 1); // x and MOD should be coprime for inverse to exist
      return (y % MOD + MOD) % MOD;
    }
  }

  friend mint operator+(const mint &lhs, const mint &rhs) {
    return mint(lhs) += rhs;
  }
  friend mint operator-(const mint &lhs, const mint &rhs) {
    return mint(lhs) -= rhs;
  }
  friend mint operator*(const mint &lhs, const mint &rhs) {
    return mint(lhs) *= rhs;
  }
  friend mint operator/(const mint &lhs, const mint &rhs) {
    return mint(lhs) /= rhs;
  }
  friend bool operator==(const mint &lhs, const mint &rhs) {
    return lhs.m_num == rhs.m_num;
  }
  friend bool operator!=(const mint &lhs, const mint &rhs) {
    return !(lhs == rhs);
  }
  friend ostream &operator<<(ostream &o, const mint &a) {
    o << a.m_num;
    return o;
  }

private:
  int64_t m_num;
};

inline int64_t mod_add(int64_t x, int64_t y) {
  return ((x % MOD) + (y % MOD)) % MOD;
}

inline int64_t mod_sub(int64_t x, int64_t y) {
  return ((x % MOD) - (y % MOD) + MOD) % MOD;
}

inline int64_t mod_mul(int64_t x, int64_t y) {
  return ((x % MOD) * (y % MOD)) % MOD;
}

int64_t mod_pow(int64_t x, int64_t y) {
  int64_t result = 1;
  x %= MOD;
  if (x == 0)
    return 0;
  while (y > 0) {
    if (y & 1)
      result = (result * x) % MOD;
    y >>= 1;
    x = (x * x) % MOD;
  }
  return result;
}

inline int64_t mod_inv_prime(int64_t x) {
  // This works only if MOD is a prime number.
  return mod_pow(x, MOD - 2);
}

int64_t mod_inv(int64_t x) {
  function<int64_t(int64_t, int64_t, int64_t &, int64_t &)> gcd_extended =
      [&](int64_t a, int64_t b, int64_t &y, int64_t &z) {
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
  return (y % MOD + MOD) % MOD;
}

int64_t mod_div(int64_t x, int64_t y) {
  x %= MOD;
  int64_t inv = mod_inv_prime(y);
  // int64_t inv = mod_inv(y);
  return (inv * x) % MOD;
}

} // namespace modular
