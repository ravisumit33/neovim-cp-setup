#define STRCMP(a, b) strcmp_##a##_##b
#define strcmp_Codeforces_Codeforces 1
#define strcmp_AtCoder_Codeforces 0

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
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

template <typename T> void inV(vector<T> &v) {
  for (auto &el : v)
    cin >> el;
}

void solve() {
  // Solve test case here
}

#define TEST_CASES STRCMP(Codeforces, Codeforces)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

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
