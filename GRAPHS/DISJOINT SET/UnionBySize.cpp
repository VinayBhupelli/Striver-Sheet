#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
  vector<int> rank, parent, size;

 public:
  DisjointSet(int n) {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    size.resize(n + 1);
    for (int i = 0; i <= n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }
  int findPar(int node) {
    if (node == parent[node]) return node;
    return parent[node] = findPar(parent[node]);
  }
  void unionBySize(int u, int v) {
    int ulp_u = findPar(u);
    int ulp_v = findPar(v);
    if (ulp_u == ulp_v) return;
    if (size[ulp_u] < size[ulp_v]) {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    } else {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
  }
};
int main() {
  DisjointSet ds(7);
  ds.unionBySize(1, 2);
  ds.unionBySize(2, 3);
  ds.unionBySize(4, 5);
  ds.unionBySize(6, 7);
  ds.unionBySize(5, 6);
  // checking whether 3 and 7 are in same component
  if (ds.findPar(3) == ds.findPar(7))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  // joining them
  ds.unionBySize(3, 7);
  if (ds.findPar(3) == ds.findPar(7))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}