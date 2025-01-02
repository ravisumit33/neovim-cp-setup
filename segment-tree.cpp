#include <cassert>
#include <functional>
#include <vector>

using namespace std;

namespace SegmentTree {

struct Max {
  template <typename T> T operator()(const T &a, const T &b) const {
    return max(a, b);
  }
};

struct Min {
  template <typename T> T operator()(const T &a, const T &b) const {
    return min(a, b);
  }
};

template <typename T, typename Merge, typename Identity> class SegTree {
public:
  SegTree() : SegTree(0) {}
  SegTree(int n) : SegTree(vector<T>(n, Identity()())) {}
  SegTree(const vector<T> &arr)
      : merge(), identity(), _n(arr.size()), _tree(4 * _n, identity()) {
    if (_n) {
      _build(arr, 1, 0, _n - 1);
    }
  }

  void update(int idx, function<T(const T &)> update_val) {
    _update(1, 0, _n - 1, idx, update_val);
  }

  T query(int l, int r) { return _query(1, 0, _n - 1, l, r); }

private:
  Merge merge;
  Identity identity;
  int _n;
  vector<T> _tree;

  void _build(const vector<T> &arr, int node, int start, int end) {
    if (start == end) {
      _tree[node] = arr[start];
      return;
    }
    int mid = start + (end - start) / 2;
    _build(arr, 2 * node, start, mid);
    _build(arr, 2 * node + 1, mid + 1, end);
    _tree[node] = merge(_tree[2 * node], _tree[2 * node + 1]);
  }

  T _query(int node, int start, int end, int l, int r) {
    assert(0 <= l && l <= r && r < _n);
    if (r < start || end < l) {
      return identity();
    }
    if (l <= start && end <= r) {
      return _tree[node];
    }
    int mid = start + (end - start) / 2;
    return merge(_query(2 * node, start, mid, l, r),
                 _query(2 * node + 1, mid + 1, end, l, r));
  }

  void _update(int node, int start, int end, int idx,
               function<T(const T &)> update_val) {
    if (start == end) {
      _tree[node] = update_val(_tree[node]);
      return;
    }
    int mid = start + (end - start) / 2;
    if (idx <= mid) {
      _update(2 * node, start, mid, idx, update_val);
    } else {
      _update(2 * node + 1, mid + 1, end, idx, update_val);
    }
    _tree[node] = merge(_tree[2 * node], _tree[2 * node + 1]);
  }
};

} // namespace SegmentTree

namespace LazySegmentTree {} // namespace LazySegmentTree
