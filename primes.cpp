#include <cmath>
#include <vector>

using namespace std;

namespace primes {

namespace linearSieve {

constexpr int MAXN = 3e5;  // Max N till which linear sieve can be used
vector<int> spf(MAXN + 1); // smallest prime factor
vector<int> primes;

void sieve() {
  for (int i = 2; i <= MAXN; ++i) {
    if (spf[i] == 0) {
      spf[i] = i;
      primes.push_back(i);
    }
    for (auto p : primes) {
      if (p * i > MAXN)
        break;
      spf[p * i] = p;
      if (p == spf[i])
        break;
    }
  }
}

vector<int> getFactorization(int x) {
  vector<int> ret;
  while (x != 1) {
    ret.push_back(spf[x]);
    x /= spf[x];
  }
  return ret;
}

} // namespace linearSieve

namespace primeFactorization {

vector<int> primeFactor(int n) {
  vector<int> ret;
  while (n % 2 == 0) {
    ret.push_back(2);
    n /= 2;
  }
  int sq = sqrt(n);
  for (int i = 3; i <= sq; i += 2) {
    while (n % i == 0) {
      ret.push_back(i);
      n /= i;
    }
  }
  if (n > 2) {
    ret.push_back(n);
  }
  return ret;
}

} // namespace primeFactorization
} // namespace primes
