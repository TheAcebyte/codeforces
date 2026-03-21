#include <cassert>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

class dsu {
private:
  std::size_t n;
  std::vector<std::size_t> p;
  std::vector<std::size_t> sizes;

  std::size_t find(std::size_t u) {
    if (p[u] == u) {
      return u;
    }

    return p[u] = find(p[u]);
  }

public:
  dsu(std::size_t n) : n(n), p(n), sizes(n, 1) {
    std::iota(p.begin(), p.end(), 0);
  }

  std::size_t find_set(std::size_t u) {
    assert(u < n);
    return find(u);
  }

  void union_sets(std::size_t u, std::size_t v) {
    assert(u < n && v < n);
    std::size_t s = find_set(u);
    std::size_t t = find_set(v);
    if (s == t) {
      return;
    }

    if (sizes[s] < sizes[t]) {
      std::swap(s, t);
    }

    p[t] = s;
    sizes[s] += sizes[t];
  }

  std::size_t get_size(std::size_t u) {
    std::size_t s = find_set(u);
    return sizes[s];
  }
};

void solve() {
  int n;
  std::cin >> n;

  dsu sets(n);
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    --x;

    sets.union_sets(i, x);
  }

  int result = 0;
  for (int x = 0; x < n; ++x) {
    int p = sets.find_set(x);
    if (p != x) {
      continue;
    }

    int size = sets.get_size(p);
    result += (size - 1) / 2;
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
