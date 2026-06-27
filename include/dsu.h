#pragma once

#include <cassert>
#include <cstddef>
#include <numeric>
#include <utility>
#include <vector>

class dsu {
private:
  int n;
  std::vector<int> p;
  std::vector<int> sizes;

  int find(int u) {
    if (p[u] == u) {
      return u;
    }

    return p[u] = find(p[u]);
  }

public:
  dsu(int n) : n(n), p(n), sizes(n, 1) {
    std::iota(p.begin(), p.end(), 0);
  }

  int find_set(int u) {
    assert(u < n);
    return find(u);
  }

  void union_sets(int u, int v) {
    assert(u < n && v < n);
    int s = find_set(u);
    int t = find_set(v);
    if (s == t) {
      return;
    }

    if (sizes[s] < sizes[t]) {
      std::swap(s, t);
    }

    p[t] = s;
    sizes[s] += sizes[t];
  }

  int get_size(int u) {
    int s = find_set(u);
    return sizes[s];
  }
};
