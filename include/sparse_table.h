#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

template <typename T> class sparse_table {
private:
  int n;
  std::vector<int> log2;
  std::vector<std::vector<T>> data;

  void precompute_log2() {
    log2[0] = log2[1] = 0;
    for (int i = 2; i <= n; ++i) {
      log2[i] = log2[i >> 1] + 1;
    }
  }

public:
  sparse_table(const std::vector<T> &v) : n(v.size()), log2(n + 1) {
    precompute_log2();
    int m = log2[n];
    data = std::vector(m + 1, std::vector<T>(n));
    std::copy(v.begin(), v.end(), data.front().begin());
    for (int k = 1; k <= m; ++k) {
      for (int i = 0; i + (1 << k) <= n; ++i) {
        int j = i + (1 << (k - 1));
        data[k][i] = std::min(data[k - 1][i], data[k - 1][j]);
      }
    }
  }

  T query(int l, int r) {
    assert(l >= 0 && r < n && l <= r);
    int k = log2[r - l + 1];
    int i = r - (1 << k) + 1;
    T result = std::min(data[k][l], data[k][i]);
    return result;
  }
};
