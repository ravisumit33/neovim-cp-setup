#include <cassert>
#include <cstdint>
#include <functional>
#include <iostream>

using namespace std;

namespace modular {

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
  static constexpr int MOD = 998244353;
  static constexpr bool MOD_IS_PRIME = true;
};

const int MAXN = 2e5;
mint factorial[MAXN + 1];
mint inv_factorial[MAXN + 1];

void precompute() {
  factorial[0] = 1;
  for (int i = 1; i <= MAXN; i++) {
    factorial[i] = factorial[i - 1] * i;
  }

  inv_factorial[MAXN] = 1 / factorial[MAXN];
  for (int i = MAXN - 1; i >= 0; --i) {
    inv_factorial[i] = inv_factorial[i + 1] * (i + 1);
  }
}

mint ncrp(int n, int r) {
  if (r > n || r < 0)
    return 0;
  return factorial[n] * inv_factorial[r] * inv_factorial[n - r];
}

} // namespace modular
