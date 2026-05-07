#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <set>
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

bool is_cyclic(const std::vector<int>& neighbor, std::set<int>& visited, int u, int p = -1) {
  if (visited.find(u) != visited.end()) {
    return true;
  }

  visited.insert(u);
  int v = neighbor[u];
  if (v == p) {
    return false;
  }

  return is_cyclic(neighbor, visited, v, u);
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> neighbor(n);
  for (int& v : neighbor) { std::cin >> v; --v; }

  dsu sets(n);
  for (int u = 0; u < n; ++u) {
    int v = neighbor[u];
    sets.union_sets(u, v);
  }

  int cycles = 0;
  int components = 0;
  for (int u = 0; u < n; ++u) {
    int p = sets.find_set(u);
    if (p != u) {
      continue;
    }

    ++components;
    std::set<int> visited;
    if (is_cyclic(neighbor, visited, u)) {
      ++cycles;
    }
  }

  int min = cycles + (cycles < components);
  int max = components;
  std::cout << min << ' ' << max << '\n';
}

int main() {
#ifdef DEBUG
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
