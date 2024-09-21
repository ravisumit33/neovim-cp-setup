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
      : parent(n), size(n, 1), rank(n, 0), N(n), num_sets(n) {
    iota(parent.begin(), parent.end(), 0);
  }

  void make_set(int t) {
    parent[t] = t;
    size[t] = 1;
    rank[t] = 0;
  }

  int find_set(int v) {
    if (v == parent[v])
      return v;
    return parent[v] = find_set(parent[v]);
  }

  void merge_set(int a, int b) {
    int pa = find_set(a);
    int pb = find_set(b);
    if (pa != pb) {
      if (size[pa] < size[pb])
        swap(pa, pb); // merging on the basis of size
      // if (rank[pa] < rank[pb]) swap(pa, pb); // merging on the basis of rank
      parent[pb] = pa;
      size[pa] += size[pb];
      if (rank[pa] == rank[pb])
        ++rank[pa];
      --num_sets;
    }
  }

  int get_size(int v) { return size[find_set(v)]; }

  vector<int> get_set(int v) {
    int pv = find_set(v);
    vector<int> ans;
    for (int i = 0; i < N; ++i) {
      if (find_set(i) == pv) {
        ans.push_back(i);
      }
    }
    return ans;
  }

  unordered_map<int, vector<int>> get_all_sets() {
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < N; ++i) {
      int p = find_set(i);
      mp[p].push_back(i);
    }
    return mp;
  }

private:
  vector<int> parent;
  vector<int> size, rank;
  int N;
  int num_sets;
};

} // namespace DSU
