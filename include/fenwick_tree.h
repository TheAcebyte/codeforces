#pragma once

#include <cstddef>
#include <iterator>
#include <vector>

template <typename T> class fenwick_tree {
private:
  int n;
  std::vector<T> data;

public:
  fenwick_tree(int n) : n(n), data(n) {}
  fenwick_tree(const std::vector<T> &v) : fenwick_tree(v.size()) {
    for (int i = 0; i < n; ++i) {
      data[i] += v[i];
      int j = i | (i + 1);
      if (j < n) {
        data[j] += data[i];
      }
    }
  }

  T query(int i) {
    T result = 0;
    int r = i;
    while (r >= 0) {
      result += data[i];
      r = (r & (r + 1)) - 1;
    }

    return result;
  }

  void update(int i, T x) {
    int r = i;
    while (r < n) {
      data[r] += x;
      r = r | (r + 1);
    }
  }
};
