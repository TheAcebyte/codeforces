#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>

using i64 = std::int64_t;

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

struct interval {
  int l;
  int r;

  bool operator<(const interval &other) const { return l < other.l; }
};

void solve() {
  int n;
  std::cin >> n;

  std::vector<interval> intervals(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> intervals[i].l >> intervals[i].r;
  }
  std::sort(intervals.begin(), intervals.end());

  std::vector<int> rights(n);
  std::iota(rights.begin(), rights.end(), 0);
  auto cmp = [&](int i, int j) { return intervals[i].r < intervals[j].r; };
  std::sort(rights.begin(), rights.end(), cmp);

  std::vector<int> reverse_rights(n);
  for (int r = 0; r < n; ++r) {
    int i = rights[r];
    reverse_rights[i] = r;
  }

  std::vector<i64> initial_count(n, 1);
  fenwick_tree<i64> counter(initial_count);

  i64 result = 0;
  for (int r : reverse_rights) {
    result += counter.query(r - 1);
    counter.update(r, -1);
  }

  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  while (T-- > 0) {
    solve();
  }

  return 0;
}
