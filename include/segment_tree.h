#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

template <typename T> class segment_tree {
private:
  int n;
  std::vector<T> data;

  void build(const std::vector<T> &a, int u, int l, int r) {
    if (l == r) {
      data[u] = a[l];
      return;
    }

    int m = l + (r - l) / 2;
    build(a, 2 * u + 1, l, m);
    build(a, 2 * u + 2, m + 1, r);
    data[u] = data[2 * u + 1] + data[2 * u + 2];
  }

  T _query(int u, int l, int r, int i, int j) {
    if (i > j) return 0;
    if (l == i && r == j) {
      return data[u];
    }

    int m = l + (r - l) / 2;
    T x = _query(2 * u + 1, l, m, i, std::min(j, m));
    T y = _query(2 * u + 2, m + 1, r, std::max(i, m + 1), j);
    return x + y;
  }

  void _update(int u, int l, int r, int i, T x) {
    if (l == r) {
      data[u] = x;
      return;
    }

    int m = l + (r - l) / 2;
    if (i <= m) {
      _update(2 * u + 1, l, m, i, x);
    } else {
      _update(2 * u + 2, m + 1, r, i, x);
    }

    data[u] = data[2 * u + 1] + data[2 * u + 2];
  }

public:
  segment_tree(int n) : n(n), data(4 * n) {}
  segment_tree(const std::vector<T> &v) : segment_tree(v.size()) {
    build(v, 0, 0, n - 1);
  }

  T query(int i, int j) {
    assert(i >= 0 && j < n && i <= j);
    return _query(0, 0, n - 1, i, j);
  }

  void update(int i, T x) {
    assert(i >= 0 && i < n);
    _update(0, 0, n - 1, i, x);
  }
};
