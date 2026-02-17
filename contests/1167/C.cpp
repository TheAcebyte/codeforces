#include <cassert>
#include <cstddef>
#include <iostream>
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
    for (std::size_t i = 0; i < n; ++i) {
      p[i] = i;
    }
  }

  std::size_t find_set(std::size_t u) {
    assert(u < n);
    return find(u);
  }

  void union_sets(std::size_t u, std::size_t v) {
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

  std::size_t get_size(std::size_t u) {
    int s = find_set(u);
    return sizes[s];
  }
};

void solve() {
  int n, m;
  std::cin >> n >> m;

  dsu sets(n);
  for (int i = 0; i < m; ++i) {
    int k;
    std::cin >> k;
    if (k == 0) {
      continue;
    }

    int u;
    std::cin >> u;
    --u;

    for (int j = 1; j < k; ++j) {
      int v;
      std::cin >> v;
      --v;

      sets.union_sets(u, v);
      u = v;
    }
  }

  const char* separator = "";
  for (int u = 0; u < n; ++u) {
    int size = sets.get_size(u);
    std::cout << separator << size;
    separator = " ";
  }
  std::cout << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  solve();

  return 0;
}
