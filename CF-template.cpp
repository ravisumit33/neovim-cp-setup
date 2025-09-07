#define STRCMP(a, b) strcmp_##a##_##b
#define strcmp_Codeforces_Codeforces 1
#define strcmp_AtCoder_Codeforces 0

// IWYU pragma: begin_keep

#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#ifdef DEBUG_ENV

#include "RNG.hpp"
#include "custom-assert.hpp"

#endif // DEBUG_ENV

// IWYU pragma: end_keep

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename K, typename V>
using ordered_map =
    tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

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
