#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <numeric>
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
    data[u] = std::gcd(data[2 * u + 1], data[2 * u + 2]);
  }

  T _query(int u, int l, int r, int i, int j) {
    if (i > j) return 0;
    if (l == i && r == j) {
      return data[u];
    }

    int m = l + (r - l) / 2;
    T x = _query(2 * u + 1, l, m, i, std::min(j, m));
    T y = _query(2 * u + 2, m + 1, r, std::max(i, m + 1), j);
    return std::gcd(x, y);
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

    data[u] = std::gcd(data[2 * u + 1], data[2 * u + 2]);
  }

public:
  segment_tree(int n) : n(n), data(4 * n) {}
  segment_tree(const std::vector<T> &a) : segment_tree(a.size()) {
    build(a, 0, 0, n - 1);
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

void solve() {
  int n, q;
  std::cin >> n >> q;

  std::vector<int> a(n);
  for (int& x : a) std::cin >> x;

  if (n == 1) {
    const char* separator = "";
    while (q-- > 0) {
      int l, r;
      std::cin >> l >> r;
      std::cout << separator << 0;
      separator = " ";
    }

    std::cout << '\n';
    return;
  }

  std::vector<int> b;
  b.reserve(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    b.push_back(std::abs(a[i + 1] - a[i]));
  }

  segment_tree<int> range(b);
  const char* separator = "";
  while (q-- > 0) {
    int l, r;
    std::cin >> l >> r;
    --l; --r;

    int m = l == r ? 0 : range.query(l, r - 1);
    std::cout << separator << m;
    separator = " ";
  }

  std::cout << '\n';
}

int main() {
#ifndef ONLINE_JUDGE 
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t-- > 0) {
    solve();
  }

  return 0;
}
