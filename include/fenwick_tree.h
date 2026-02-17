#pragma once

#include <cstddef>
#include <iterator>
#include <vector>

template <typename T> class fenwick_tree {
private:
  std::size_t n;
  std::vector<T> data;

public:
  fenwick_tree(std::size_t n) : n(n), data(n) {}
  fenwick_tree(const std::vector<T> &v) : fenwick_tree(v.size()) {
    for (std::size_t i = 0; i < n; ++i) {
      data[i] += v[i];
      std::size_t j = i | (i + 1);
      if (j < n) {
        data[j] += data[i];
      }
    }
  }

  T query(std::ptrdiff_t i) {
    T result = 0;
    while (i >= 0) {
      result += data[i];
      i = (i & (i + 1)) - 1;
    }

    return result;
  }

  void update(std::size_t i, T x) {
    while (i < n) {
      data[i] += x;
      i = i | (i + 1);
    }
  }
};
