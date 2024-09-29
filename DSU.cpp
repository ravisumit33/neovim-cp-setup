//
//  DSU.cpp
//  codeforces
//
//  Created by Sumit Kumar on 12/06/24.
//

#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

namespace DSU {

class DSU {
public:
  DSU(int n /* max elements in DSU */)
      : _parent(n), _size(n, 1), _rank(n, 0), _N(n), _num_sets(n) {
    iota(_parent.begin(), _parent.end(), 0);
  }

  void make_set(int t) {
    _parent[t] = t;
    _size[t] = 1;
    _rank[t] = 0;
  }

  int find_set(int v) {
    if (v == _parent[v])
      return v;
    return _parent[v] = find_set(_parent[v]);
  }

  void merge_set(int a, int b) {
    int pa = find_set(a);
    int pb = find_set(b);
    if (pa != pb) {
      if (_size[pa] < _size[pb])
        swap(pa, pb); // merging on the basis of size
      // if (rank[pa] < rank[pb]) swap(pa, pb); // merging on the basis of rank
      _parent[pb] = pa;
      _size[pa] += _size[pb];
      if (_rank[pa] == _rank[pb])
        ++_rank[pa];
      --_num_sets;
    }
  }

  int num_sets() { return _num_sets; }

  int get_size(int v) { return _size[find_set(v)]; }

  vector<int> get_set(int v) {
    int pv = find_set(v);
    vector<int> ans;
    for (int i = 0; i < _N; ++i) {
      if (find_set(i) == pv) {
        ans.push_back(i);
      }
    }
    return ans;
  }

  unordered_map<int, vector<int>> get_all_sets() {
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < _N; ++i) {
      int p = find_set(i);
      mp[p].push_back(i);
    }
    return mp;
  }

private:
  vector<int> _parent;
  vector<int> _size, _rank;
  int _N;
  int _num_sets;
};

} // namespace DSU
