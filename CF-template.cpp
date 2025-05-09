#define STRCMP(a, b) strcmp_##a##_##b
#define strcmp_Codeforces_Codeforces 1
#define strcmp_AtCoder_Codeforces 0

// IWYU pragma: begin_keep

#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// IWYU pragma: end_keep

using namespace std;

// NOLINTBEGIN(clang-diagnostic-unused*)

class RNG {
public:
  RNG(int mn, int mx) : gen(rd()), dist(mn, mx) {}
  int generate() { return dist(gen); }

private:
  random_device rd;
  mt19937 gen;
  uniform_int_distribution<int> dist;
};

template <typename T> void print_vars(const char *var_names, const T &var) {
  cerr << var_names << " = " << var << endl;
}

template <typename T, typename... Args>
void print_vars(const char *var_names, const T &var, const Args &...args) {
  const char *comma = strchr(var_names, ',');
  cerr.write(var_names, comma - var_names) << " = " << var << endl;
  print_vars(comma + 1, args...);
}

#define ASSERT_WITH_VARS(condition, ...)                                       \
  do {                                                                         \
    if (!(condition)) {                                                        \
      cerr << "Assertion failed: " #condition << endl;                         \
      print_vars(#__VA_ARGS__, __VA_ARGS__);                                   \
      abort();                                                                 \
    }                                                                          \
  } while (0)

constexpr int i32inf = numeric_limits<int>::max();
constexpr int i32minf = numeric_limits<int>::min();
constexpr int64_t i64inf = numeric_limits<int64_t>::max();
constexpr int64_t i64minf = numeric_limits<int64_t>::min();

template <typename T> void inV(vector<T> &v) {
  for (auto &el : v)
    cin >> el;
}

// NOLINTEND(clang-diagnostic-unused*)

// #define USE_RNG 1

#define TEST_CASES STRCMP(Codeforces, Codeforces)

void precompute() {}

void solve() {
  // Solve test case here
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  precompute();
#if TEST_CASES
  int t;
  cin >> t;
  while (t--) {
#endif
    solve();
#if TEST_CASES
  }
#endif

  return 0;
}
