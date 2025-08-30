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
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#ifdef LOCAL_ENV

#include "RNG.hpp"
#include "custom-assert.hpp"

#endif // LOCAL_ENV

// IWYU pragma: end_keep

using namespace std;

// NOLINTBEGIN(clang-diagnostic-unused*)

constexpr int i32inf = numeric_limits<int>::max();
constexpr int i32minf = numeric_limits<int>::min();
constexpr int64_t i64inf = numeric_limits<int64_t>::max();
constexpr int64_t i64minf = numeric_limits<int64_t>::min();

template <typename T> void inV(vector<T> &v) {
  for (auto &el : v)
    cin >> el;
}

template <typename T> void inV(vector<vector<T>> &vv) {
  for (auto &row : vv)
    inV(row);
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
